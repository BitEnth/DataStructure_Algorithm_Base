/* The header of sorting algorithm
 * Define the way of datas saving*/
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE_SORT 100

typedef int KeyType_sort;

typedef struct{
	KeyType_sort key;
	char info;
}DataType_sort;

typedef struct{
	/* r[0] is inactive*/
	DataType_sort r[MAXSIZE_SORT+1];
	int length;
}SqList_sort;

/* The length of key[] must be equal to info[]'s.*/
SqList_sort *CreatSqList_sort(int key[], char info[], int len)
{
	int i;
	SqList_sort *sql = (SqList_sort*)calloc(1, sizeof(SqList_sort));
	for(i = 0;i < len;i++){
		sql->r[i+1].key = key[i];
		sql->r[i+1].info = info[i];
	}
	sql->length = len;
	return sql;
}

void PrintSqList_sort(SqList_sort sql)
{
	int i;
	for(i = 1;i < sql.length+1;i++){
		printf("%c\t", sql.r[i].info);
		printf("%d\n", sql.r[i].key);
	}
}
