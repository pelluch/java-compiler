//Implementación de la ayudantía

#include "hashtable.h"

void HashTableAlloc() 
{
	int ni;
	HashTable = (struct Slot**)malloc(100*sizeof(struct Slot));
	for(ni = 0; ni < 100; ni++)
		*(HashTable + ni) = NULL;
}

void HashTableFree() 
{
	int ni;
	struct Slot *slot, *tmp, *aux;
	for(ni = 0; ni < 100; ni++) {
		slot = *(HashTable + ni);
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

void HashTablePrint()
{
	int ni; 
	struct Slot *slot, *tmp, *aux;
	for(ni = 0; ni < 100; ni++)
	{
		slot = *(HashTable + ni);
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

struct Slot *buscaInserta(class Symbol *s)
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
	if(*(HashTable + slot) == NULL)
	{
		printf("Id no encontrado. Agregando en tabla.\n");
		struct Slot *aux = (struct Slot *)malloc(sizeof(struct Slot));
		*(HashTable + slot) = aux;
		aux->key = scopy;
		aux->next = NULL;
		return aux;
	}
	else
	{
		struct Slot *aux = *(HashTable + slot);
		if(!strcmp(aux->key, scopy))
		{
			printf("Target found in id table.\n");
			return aux; //target found
		}
		else
		{
			while(aux->next != NULL)
			{
				if(!strcmp(aux->key, scopy))
				{
					printf("Target found in id table.\n");
					return aux; //target found
				}
				if(aux->next != NULL)
					aux = aux->next;
			}
		}
		//linked list ins
		printf("Id no encontrado. Agregando en tabla.\n");
		aux->next = (struct Slot *)malloc(sizeof(struct Slot));
		aux = aux->next;
		aux->key = scopy;
		aux->next = NULL;
		return aux;
	}	
}
