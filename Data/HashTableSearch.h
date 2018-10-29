/* No test*/
#include "SearchHeader.h"
#include <stdio.h>
#include <stdlib.h>
#define NULLKEY -1

typedef struct{
	DataType_SH elem[MAXSIZE_SH];
	int length;
}HashTable;

/* divided and keep remainder
 * len is equal to HashTable.length*/
int Hash_DR(KeyType k, int len)
{
	int hash;
	len -= 2;
	hash = k%len + 1063;
	return hash;
}

int Hash_FR(KeyType k)
{
	int hash;
	srand(k);
	hash = rand();
	return hash;
}

int HashSearch(HashTable *ht, KeyType k)
{
	int d, i;
	d = Hash_DR(k, ht->length);
	for(i = 0;i < ht->length;i++){
		if(ht->elem[d].key == k){
			return d;
		}
		if(ht->elem[d].key == NULLKEY){
			return -1;
		}
		d = (d+1) % (ht->length);
	}
	return -1;
}

void HashInsert(HashTable *ht, KeyType k)
{
	int d, j;
	d = Hash_DR(k, ht->length);
	if(ht->elem[d].key == NULLKEY){
		ht->elem[d].key = k;
	}
	else{
		j = d;
		d = (d+1) % (ht->length);
		while((d != j) && ht->elem[d].key != NULLKEY){
			d = (d+1) % (ht->length);
		}
		if(ht->elem[d].key == NULLKEY){
			ht->elem[d].key = k;
		}
		else{
			printf("overflow!");
		}
	}
}
