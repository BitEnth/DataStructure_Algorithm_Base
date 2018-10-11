#include <stdio.h>
#include <stdlib.h>
#define MAXSIZESQ 100

typedef int SQDT;

/*Cycling Queue, with level search*/
typedef struct{
	SQDT data[MAXSIZESQ];
	int front, rear;
}SeqQueue, *PSeqQueue;

PSeqQueue Init_SeqQueue(void)
{
	PSeqQueue Q;
	Q = (PSeqQueue)malloc(sizeof(SeqQueue));
	if(Q){
		Q->front = 0;
		Q->rear = 0;
	}
	return Q;
}

int Empty_SeqQueue(PSeqQueue Q)
{
	if(Q && Q->front == Q->rear){
		return 1;
	}
	else{
		return 0;
	}
}

int In_SeqQueue(PSeqQueue Q, SQDT x)
{
	if((Q->rear+1)%MAXSIZESQ == Q->front){
		printf("The Queue is full!");
		return -1;
	}
	else{
		//Q->bdata[Q->rear] = x;
		Q->rear = (Q->rear+1)%MAXSIZESQ;
		Q->data[Q->rear] = x;
		return 1;
	}
}

/* x must be a pointer, or x will not be changed if it's a variable
 * Call by value, Call by reference*/
int Out_SeqQueue(PSeqQueue Q, SQDT *x)
{
	if(Empty_SeqQueue(Q)){
		printf("The Queue is empty!");
		return -1;
	}
	else{
		//x = Q->bdata[Q->front];
		Q->front = (Q->front+1)%MAXSIZESQ;
		*x = Q->data[Q->front];
	}
	return 1;
}

int Front_SeqQueue(PSeqQueue Q, SQDT *x)
{
	if(Q->front == Q->rear){
		printf("The Queue is empty!");
		return -1;
	}
	else{
		*x = Q->data[(Q->front+1)%MAXSIZESQ];
		return 1;
	}
}

void Destroy_SeqQueue(PSeqQueue *Q)
{
	if(*Q){
		free(*Q);
	}
	*Q = NULL;
}
