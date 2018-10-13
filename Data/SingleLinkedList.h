/*
*H stands for the head pointer of Linked list
*The header file is based in a condition that the list must has a head node
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node {
	DataType data;
	struct node *next;
}LNode, *LinkList;

inline LinkList Init_LinkList(void)
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (H) {
		H->next = NULL;
		printf("Succeed in creating.");
	}
	return H;
}

inline void Destroy_LinkList(LinkList *H)
{
	LinkList p, q;
	p = *H;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	*H = NULL;
	printf("Succeed in free.");
	return;
}

inline int Length_Linklist(LinkList H)
{
	LinkList p = H;
	int count = -1;
	while (p) {
		p = p->next;
		count++;
	}
	return count;
}

inline LinkList Locate_LinkList_Pos(LinkList H, int i)
{
	LinkList p;
	int j;
	p = H, j = 0;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i || !p) {
		printf("Parameter i is wrong or the linked list doesn't exist.");
		return NULL;
	}
	return p;
}

inline LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	while (p&&p->data != x) {
		p = p->next;
	}
	return p;
}

inline int Insert_LinkList(LinkList H, int i, DataType x)
{
	LinkList p, q;
	p = Locate_LinkList_Pos(H, i - 1);
	if (!p) {
		printf("i is wrong.");
		return 0;
	}
	q = (LinkList)malloc(sizeof(LNode));
	if (!q) {
		printf("Fail to apply for RAM!");
		return 0;
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

inline int Del_LinkList(LinkList H, int i) 
{
	LinkList p, q;
	if (H == NULL || H->next == NULL) {
		printf("Linked list doesn't exist or empty list cannot be deleted.");
		return 0;
	}
	p = Locate_LinkList_Pos(H, i - 1);
	if (p == NULL || p->next == NULL) {
		printf("The parameter i is wrong");
		return 0;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

inline void Print_Linklist(LinkList H)
{
	printf("The list is:\n");
	H = H->next;
	while (H) {
		printf("%d", H->data);
		H = H->next;
	}
	printf("\n");
	return;
}

inline LinkList Creat_LinkList_Array(DataType a[], int length)
{
	/*The Linked list does contain the head node*/
	LinkList H, p, q;
	int i;
	//printf("%d\n", length);
	H = (LinkList)malloc(sizeof(LNode));
	//q = (LinkList)malloc(sizeof(LNode));
	H->next = NULL;
	//printf("\nH: %d\n", &H);
	//printf("the *next of H: %d\n", &(H->next));
	q = H;      //q与H栈内存地址不同，堆内存地址相同，即映射同一组变量
	//printf("\nq: %d\n", &q);
	//printf("the *next of q: %d\n", &(q->next));
	for (i = 0; i < length; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = a[i];
	    p->next = NULL;
		q->next = p;
		//q->data = p->data;
		q = p;
	}
	//printf("\n%d\n", H->next->data);
	return H;
}