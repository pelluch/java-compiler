#include <string.h>
#include <vector>
using namespace std;

class Node
{
		
		
	public:	
	char* token;
	int numChildren;
	int numDimensions; //Para el caso que las variables son arreglos
	int indexArrayParent; //el indice del nodo en el arreglo del padre
	Node** children;
	int counter;
	Node(const char* token, Node * node, int numLine);
	Node(const char* token, int numChildren);
	void AddChild(Node* newChild);
	void AddChild(Node *newChild, int numLine);	
	void removeChildren(class vector<int> v);
	char* leafValue();
	Node *parent;
	int getLine();
	void setLine(int line);
	bool visited;
	bool skipAnalysis;
	int line;
	string cil;
	class Symbol *symbol;
	vector<class Symbol*> symbols;
};

int Node::getLine()
{
	return line;
}

void Node::setLine(int line)
{
	this->line = line;
}
char* Node::leafValue()
{
	if(numChildren == 1 && children[0]->numChildren == 0)
		return children[0]->token;
	else
	{
		printf("Error: El nodo %s no es un nodo pre-hoja.\n", token);
		return NULL;
	}
}

void Node::removeChildren(class vector<int> v)
{
}

Node::Node(const char token[], Node *node, int numLine)
{
	line = 0;
	indexArrayParent = 0;
	this->token = strdup(token);
	this->numChildren = 1;
	this->children = new Node*[1];
	counter = 0;
	children[0] = node;
	children[0]->setLine(numLine);
	numDimensions = 0;
	visited = false;
	cil = "";
	symbol = NULL;
	parent = NULL;
	skipAnalysis = false;
}

Node::Node(const char token[], int numChildren)
{
	line = 0;
	indexArrayParent = 0;
	//printf("Node created: %s\n", token);
	this->token = strdup(token);
	this->numChildren = numChildren;
	this->children = new Node*[numChildren];
	counter = 0;
	visited = false;
	cil = "";
	symbol = NULL;
	parent = NULL;
	skipAnalysis = false;
}

void Node::AddChild(Node *newChild)
{
	children[counter] = newChild;
	children[counter]->indexArrayParent = counter;
	counter++;
}

void Node::AddChild(Node *newChild, int numLine)
{
	children[counter] = newChild;
	children[counter]->setLine(numLine);
	children[counter]->indexArrayParent = counter;
	counter++;
}

