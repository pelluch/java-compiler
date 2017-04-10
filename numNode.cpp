#include <string.h>

enum Flujo {IF, ELSE, WHILE, FOR, DO, SWITCH};

class numNode
{
	public:
	numNode* dad;
	int num; 
	int extra; //guarda un valor extra en caso de necesitarlo

	numNode(int number);
	void setDad(numNode *newDad);
	numNode* getDad();
	int getNum();
	void setNum(int n);
};

numNode::numNode(int number)
{
	num = number;
}

void numNode::setDad(numNode* newDad)
{
	dad = newDad;
}

numNode* numNode::getDad()
{
	return dad;
}

int numNode::getNum()
{
	return num;
}

void numNode::setNum(int n)
{
	num = n;
}
