#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

enum ReturnType { INT, FLOAT, CHAR, VOID, BOOLEAN };
enum Visibility { PUBLIC, PROTECTED, PRIVATE, DEFAULT };
enum MethodType { CONSTRUCTOR, METHOD };

class Symbol {
	
	public:
		char *id;	//El identificador (nombre) del símbolo
		int scope;	//Bloque en el cual se declara
		char * type;  //Atributo, Parametro, Metodo etc.
		int numLine;
		Symbol();
};

Symbol::Symbol()
{
	numLine = 0;
}

class ClassSymbol: public Symbol {
	public:
	
	vector<class Method*> methods;
	vector<class Method*> constructors;
	
	vector <class Attribute *> attributes;	
	vector <Node* > fields;
	int numAttributes;
	ClassSymbol * baseClass;
	bool hasExplicitConstructor;
	int visibility;
	char * base;		
	bool hasBase;
	bool addedThis;
	void AddBase(char * name);
	void AddMethod(class Method *m);
	void AddConstructor(class Method *m);
	void AddAttribute(Attribute *a);
	int englobingScope;
	ClassSymbol();
};

void ClassSymbol::AddMethod(class Method *m)
{
	methods.push_back(m);
}

void ClassSymbol::AddConstructor(class Method *m)
{
	constructors.push_back(m);
}
ClassSymbol::ClassSymbol()
{
	base = NULL;
	baseClass = NULL;
	addedThis = false;
	hasBase = false;
	numAttributes = 0;
	hasExplicitConstructor = false;
}
void ClassSymbol::AddBase(char * name)
{
	hasBase = true;
	this->base = name;
}
//Variables definidas dentro de un método.
class Variable: public Symbol {
	public:
	char * variableType; //int, string, etc 
	char * value; //el 5 en int a = 5
	int numDimensions;		
	int arrayLength;
	Variable();	
};

Variable::Variable()
{
	numDimensions = 0;
	arrayLength = 0;
}



//Variables de clase.
class Attribute: public Symbol {
public:	
	int visibility;
	char * variableType; //(No usare el enum pq puede ser de otros tipos tb)
	char * value;
	int arrayLength;
	int numDimensions;
	Node * initializerCode; //Contiene un variable Declarator o es NULL
	
	Attribute();
};

Attribute::Attribute()
{
	initializerCode = NULL;
	numDimensions = 0;
	arrayLength = 0;
}

class Parameter: public Symbol {
public:
	char* paramType; 
	int numDimensions; //0 si no es un arreglo, n = dim(arr) si es un arreglo
	char* value;
	int arrayLength;
	Parameter();
};

Parameter::Parameter()
{
	numDimensions = 0;
	arrayLength = 0;
}

//Métodos dentro de una clase.
class Method: public Symbol {

public:
	int numParams;
	vector<Parameter*> params;
	class Variable ** variables;	
	int visibility;
	char* returnType;
	int line; //Linea donde fue declarado, solo se debiese usar en currentMethod
	bool isMain;
	enum MethodType methodType; //Constructor o metodo normal.	
	Method *next; //Alberga sobrecarga de métodos
	Method();
	void AddParameter(Parameter * param);
	bool AddOverload(Method *method);
	int englobingScope;
	bool hasExplicitConInv;
	bool HasSameSig(Method * otherMethod);
	vector<char*> paramInfo;
	bool ExistsOverload(vector<string> paramInfo);
};

//bool Method::HasSameSig(Method* otherMethod)
//{
//	if(!strcmp(otherMethod->id, this->id) && !strcmp(returnType, otherMethod->returnType))
//	{
//		if(params.size() != otherMethod->params.size())
//		{
//			return false;
//		}
//		else
//		{
//			for(int i = 0; i < params.size(); i++)
//			{
//				if(strcmp(params[i]->paramType, otherMethod->params[i]->paramType))
//					return false;
//			}
//			return true;	
//		}
//	}
//	else
//		return false;
//	
//}

Method::Method()
{
	next = NULL;
	isMain = false;
	hasExplicitConInv = false;
}

void Method::AddParameter(Parameter * param)
{
	params.push_back(param);
}

bool Method::ExistsOverload(vector<string> paramInfo)
{

	//Si tienen el mismo número de parámetros...
	cout << "Size 1: " << paramInfo.size()<< endl;
	cout << "Size 2: " << this->params.size() << endl;
	
	if(paramInfo.size() == this->params.size())
	{
		
		vector<string>::iterator it;	
		vector<Parameter*>::iterator it2;
	
		it2 = params.begin();
	
		bool match = true;
		//Vemos si por cada parámetro, tienen el mismo tipo.
		for(it = paramInfo.begin(); it != paramInfo.end(); it++, it2++)
		{
//			cout << "Param 1: " << *it << endl;
//			cout << "Param 2: " << (*it2)->paramType << endl;
			//Si algunos no son iguales, termino.
			
			if(*it != (*it2)->paramType)
			{
				match = false;
				break;
			}
		}
		if(match)
				return true;
		else
		{
			if(next == NULL) 
				return false;
			else
				return next->ExistsOverload(paramInfo);
		}
	}
	else if(next != NULL)	//Si no, pruebo con otro
	{
		return next->ExistsOverload(paramInfo);
	}
	else	//Si no queda otro, retorno false.
	{
		return false;
	}
	


}

bool Method::AddOverload(Method * methodSymbol)
{
	
	
	if(methodSymbol->paramInfo.size() != this->paramInfo.size() || (!strcmp(type, "METHOD")) && !strcmp(methodSymbol->returnType, this->returnType))
	{

		//Si no tienen el mismo número de parámetros y alcancé el final de la lista ligada, retorno true
		if(next == NULL)
		{
			next = methodSymbol;
			return true;
		}
		//Else sigo revisando el resto de la lista
		else
			return next->AddOverload(methodSymbol);
	}


	
	vector<char*>::iterator it;
	vector<char*>::iterator it2;
	it2 = methodSymbol->paramInfo.begin();
	
	for(it = paramInfo.begin(); it != paramInfo.end(); it++, it2++)
	{
//		if(!strcmp(type, "CONSTRUCTOR"))
//		{
//			cout << "Param 1: " << *it << endl;
//			cout << "Param 2: " << *it2 << endl;
//		}
		//printf("entra aqui\n");
		if(strcmp((*it), (*it2)))
		{
			if(next == NULL)
			{
				next = methodSymbol;
				return true;
			}
			else
			{				
				return next->AddOverload(methodSymbol);
			} 
		}
	}	
	return false;
	
}
