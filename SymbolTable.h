#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <hash_map>
#include <cstring>

using namespace std;
using namespace __gnu_cxx;
//using namespace stdext;

struct eqstr{
  bool operator()(const char* s1, const char* s2) const {
    return strcmp(s1,s2)==0;
  }
};

class SymbolTable {		
	hash_map <const char*, class Symbol*, hash<const char*>, eqstr> symbols;		
	typedef pair <const char*, class Symbol*> Symbol_Pair;
	typedef pair < hash_map <const char*, class Symbol*> ::iterator, bool > insertValue;
	
	public:
		void Insert(Symbol *s);
		Symbol * Find(char* id, int scope);
		Symbol * Find(Symbol * other);
		char * getKey(char *id, int scope);
		bool exists(char *id, int scope);
		bool exists(Symbol *s);
		SymbolTable();
		void print();
};


