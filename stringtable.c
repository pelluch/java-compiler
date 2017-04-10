//Implementación de la ayudantía

#include "stringtable.h"

void StringTableAlloc() 
{
	int ni;
	StringTable = (struct Slot**)malloc(100*sizeof(struct Slot));
	for(ni = 0; ni < 100; ni++)
		*(StringTable + ni) = NULL;
}

void StringTableFree() 
{
	int ni;
	struct Slot *slot, *tmp, *aux;
	for(ni = 0; ni < 100; ni++) {
		slot = *(StringTable + ni);
		if(slot != NULL) {
			if(slot->next != NULL) 
			{
				tmp = slot->next;
				while(tmp != NULL) 
				{
					aux = tmp; 
					tmp = tmp->next;
					free(aux->key);
					free(aux);
				}
			}
			free(slot);
		}
	}
}

void StringTablePrint()
{
	int ni; 
	struct Slot *slot, *tmp, *aux;
	for(ni = 0; ni < 100; ni++)
	{
		slot = *(StringTable + ni);
		if(slot != NULL) 
		{
			printf("key: %s\n", slot->key);
			if(slot->next != NULL)
			{
				tmp = slot->next;
				while(tmp != NULL)
				{
					aux = tmp;
					tmp = tmp->next;
					printf("key: %s\n", aux->key);
				}
			}
		}
	}
}

struct Slot *buscaInsertaString(const char *s)
{
	int ni = 0, sum = 0, slot;
	char *scopy = (char *)malloc((strlen(s)+1) * sizeof(char));
	while( ni < strlen(s)) 
	{
		scopy[ni] = *(s + ni);
		sum += *(scopy + ni++);
	}
	*(scopy + ni) = '\0';
	slot = sum % 100;
	if(*(StringTable + slot) == NULL)
	{
		printf("String no encontrado. Agregando en tabla.\n");
		struct Slot *aux = (struct Slot *)malloc(sizeof(struct Slot));
		*(StringTable + slot) = aux;
		aux->key = scopy;
		aux->next = NULL;
		return aux;
	}
	else
	{
		struct Slot *aux = *(StringTable + slot);
		if(!strcmp(aux->key, scopy))
		{
			printf("Target found in string table.\n");
			return aux; //target found
		}
		else
		{
			while(aux->next != NULL)
			{
				if(!strcmp(aux->key, scopy))
				{
					printf("Target found in string table.\n");
					return aux; //target found
				}
				if(aux->next != NULL)
					aux = aux->next;
			}
		}
		//linked list ins
		printf("String no encontrado. Agregando en tabla.\n");
		aux->next = (struct Slot *)malloc(sizeof(struct Slot));
		aux = aux->next;
		aux->key = scopy;
		aux->next = NULL;
		return aux;
	}	
}
