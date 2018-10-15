// Structest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


typedef struct node {
	int data;
	struct node *next;
}Node, *Pnode;

int main()
{
	Pnode p1 = (Pnode)malloc(sizeof(Node));
	Pnode p2 = (Pnode)malloc(sizeof(Node));
	Pnode p3 = (Pnode)malloc(sizeof(Node));
	Pnode p4 = p1;
	p1->data = 1;
	p2->data = 2;
	p3->data = 5;
	p2->next = p3;
	p1->next = p2->next;
	printf("%d", p2);
	printf("\n%d", &p2);
	printf("\n%d", &p1);
	printf("\n%d", &p4);
	printf("\n%d", *p2);
	printf("\n%d", p3);
	printf("\n%d", &p3);
	printf("\n%d", p2->next);
	printf("\n%d", p1->next);
    return 0;
}

