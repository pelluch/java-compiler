#include <string.h>
#include "Symbol.cpp"

class ScopeNode
{
	public:	
	int scopeNum;
	ScopeNode* dad;
	int numChildren;
	ScopeNode** children;
	Symbol** symbols;
	int numSymbols;
	
	ScopeNode(int scope, ScopeNode *newDad);
	void AddChild(ScopeNode* newChild);
	ScopeNode* getChild(int num);
	void AddSymbol (Symbol* newSymbol);
	Symbol* getSymbol(int num);
};

ScopeNode::ScopeNode(int scope, ScopeNode *newDad)
{
	this->scopeNum = scope;
	this->dad = newDad;
	this->numChildren = 0;
	this->numSymbols = 0;
}

void ScopeNode::AddChild(ScopeNode *newChild)
{
	ScopeNode** temp = new ScopeNode*[numChildren];
	for(int i = 0; i < numChildren; i++)
	{
		temp[i] = children[i];
	}

	children = new ScopeNode*[numChildren+1];

	for(int i = 0; i < numChildren; i++)
	{
		children[i] = temp[i];
	}
	
	children[numChildren] = newChild;
	numChildren++;
	delete temp;
}

ScopeNode* ScopeNode::getChild(int num)
{
	return children[num];
}

void ScopeNode::AddSymbol(Symbol* newSymbol)
{
	Symbol** temp = new Symbol*[numSymbols];
	for(int i = 0; i < numSymbols; i++)
	{
		temp[i] = symbols[i];
	}

	symbols = new Symbol*[numSymbols+1];

	for(int i = 0; i < numSymbols; i++)
	{
		symbols[i] = temp[i];
	}
	
	symbols[numSymbols] = newSymbol;
	numSymbols++;
	delete temp;
}

Symbol* ScopeNode::getSymbol(int num)
{
	return symbols[num];
}

