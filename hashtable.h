#ifndef __S_HASHTABLE
#define __S_HASHTABLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Slot {
	char *key;
	struct Slot *next;
	class Symbol *s;
};

struct Slot **HashTable;

void HashTableAlloc();
void HashTableFree();
struct Slot *buscaInserta(class Symbol * s);
void HashTablePrint();

#endif /*__S_HASHTABLE*/
