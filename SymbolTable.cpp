#include "SymbolTable.h"
#include <string.h>
#include <string>
#include <sstream>


using namespace std;

void SymbolTable::Insert(Symbol *sym)
{		
	const char* key = getKey(sym->id, sym->scope);
	//printf("Inserting symbol with key %s\n", key);
	symbols[key] = sym;
	
	//Liberamos la memoria.
}

/*
string value = node->value;
string aux = value.substr(6);
       
char *key = new char[aux.size() + 1];
std::strcpy (key, aux.c_str() );
*/

SymbolTable::SymbolTable()
{
	
}
Symbol* SymbolTable::Find(char * id, int scope)
{
	hash_map<const char*, class Symbol*, hash<const char*>, eqstr>::iterator it;
	const char * key = getKey(id, scope);
	it = symbols.find(key);
	
	//pairValue = symbols.find( "asdasd");
	
	if(it == symbols.end())
	{
		//printf("Symbol with key %s not found.\n", key);
		return NULL;
	}
	else
	{
		//printf("Symbol with key %s found.\n", key);
		return symbols[key];
	}
}

void SymbolTable::print()
{
	hash_map<const char*, class Symbol*, hash<const char*>, eqstr>::iterator it;
	
	for (it = symbols.begin(); it != symbols.end(); ++it)
	{
		string str = "Symbol name: ";
		Symbol *sym = it->second;
		if(!strcmp(sym->type, "METHOD") || !strcmp(sym->type, "CONSTRUCTOR"))
		{
			Method *method = (Method*) sym;
			
			
			while(method != NULL)
			{
			
				stringstream ss;
				ss << "Symbol type: " << method->type << "\t Name: " << method->id << "\tScope: " << method->scope;
				cout << ss.str() << endl;
				stringstream ss2;
				ss2 << "\tParam types: ";
				
				
				
				for(int i = 0; i < method->params.size(); i++)
				{
					ss2 << method->params[i]->paramType << " ";
				}
				
				ss2 << endl;
				cout << ss2.str();
				
				method = method->next;
				
			}
			
			
		}
		else
		{
			stringstream ss;
			ss << "Symbol type: " << sym->type << "\t Name: " << sym->id << "\tScope: " << sym->scope;
			cout << ss.str() << endl;
		}		
		
		//cout << "key = " << it->first << "\n";
	}

}

Symbol* SymbolTable::Find(Symbol * other)
{
	char * key = getKey(other->id, other->scope);
	Symbol * sym = symbols[key];
	
	return sym;
	
}

char * SymbolTable::getKey(char *id, int scope)
{
	char fullString [strlen(id)+10];
	sprintf(fullString, "%s@%d", id, scope);
	return strdup(fullString);		
}

bool SymbolTable::exists(char *id, int scope)
{
	
	Symbol *s = Find(id, scope);
	
	if(s == NULL)
		 return false;
	else
		 return true;
	
}
