#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
	DataType data;
	struct node *next;
}Qnode, *PQNode;
typedef struct {
	PQNode front, rear;
}LinkQueue, *PLinkQueue;

inline PLinkQueue Init_LinkQueue()
{
	PLinkQueue Q;
	Q = (PLinkQueue)malloc(sizeof(LinkQueue));
	if (Q) {
		Q->front = NULL;
		Q->rear = NULL;
	}
	return Q;
}

inline int Empty_LinkQueue(PLinkQueue Q)
{
	if (Q && Q->front == NULL && Q->rear == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

inline int Init_LinkQueue(PLinkQueue Q, DataType x)
{
	PQNode p;
	p = (PQNode)malloc(sizeof(Qnode));
	if (!p) {
		printf("Out of memory!");
		return 0;
	}
	p->data = x;
	p->next = NULL;
	if (Empty_LinkQueue(Q)) {
		Q->rear = p;
		Q->front = p;
	}
	else {
		Q->rear->next = p;
		Q->rear = p;
	}
}

inline int Out_LinkQueue(PLinkQueue Q, DataType *x)
{
	PQNode p;
	if (Empty_LinkQueue(Q)){
		printf("The queue is empty.");
		return 0;
	}
	*x = Q->front->data;
	p = Q->front;
	Q->front = Q->front->next;
	free(p);
	if (!Q->front) {
		Q->rear = NULL;
	}
	return 1;
}