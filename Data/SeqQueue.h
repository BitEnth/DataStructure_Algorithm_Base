/*
The sequential queue is a circular queue
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int Datatype;
typedef struct {
	Datatype data[MAXSIZE];
	int front, rear;
}SeqQueue, *PSeqQueue;

inline PSeqQueue Init_SeqQueue()
{
	PSeqQueue Q;
	Q = (PSeqQueue)malloc(sizeof(SeqQueue));
	if (Q) {
		Q->front = 0;
		Q->rear = 0;
	}
	return Q;
}

inline int Empty_SeqQueue(PSeqQueue Q)
{
	if (Q&&Q->front == Q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

inline int In_SeqQueue(PSeqQueue Q, Datatype x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		printf("The queue has been fully loaded.");
		return -1;
	}
	else {
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->data[Q->rear] = x;
		return 1;
	}
}

inline int Out_Sequeue(PSeqQueue Q, Datatype *x)
{
	if (Empty_SeqQueue(Q)) {
		printf("The Queue is empty.");
		return -1;
	}
	else {
		Q->front = (Q->front + 1) % MAXSIZE;
		*x = Q->data[Q->front];
		return 1;
	}
}

inline int Front_SeqQueue(PSeqQueue Q, Datatype *x)
{
	if (Q->front == Q->rear) {
		printf("The queue is empty.");
		return -1;
	}
	else {
		*x = Q->data[(Q->front + 1) % MAXSIZE];
		return 1;
	}
}

inline void Destroy_SeqQueue(PSeqQueue *Q)
{
	if (*Q) {
		free(*Q);
	}
	*Q = NULL;
}