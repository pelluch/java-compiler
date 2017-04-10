#ifndef __S_STRINGTABLE
#define __S_STRINGTABLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

struct Slot **StringTable;

void StringTableAlloc();
void StringTableFree();
struct Slot *buscaInsertaString(const char *s);
void StringTablePrint();

#endif /*__S_STRINGTABLE*/
