#include <string>
using namespace std;

class Error {

public:
	int numLine;
	string message;
	Error(string message, int numLine);
};

Error::Error(string message, int numLine)
{
	this->numLine = numLine;
	this->message = message;
}
