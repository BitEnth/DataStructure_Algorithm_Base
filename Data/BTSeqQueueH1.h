#include <stdio.h>
#include <stdlib.h>
#include "BinaryTreeH1.h"

/*Cycling Queue, with level search*/
typedef struct{
	BTree bdata[MaxTreeNodeNum];
	int front, rear;
}BTSQ, *PBTSQ;

PBTSQ Init_BTSQ(void)
{
	PBTSQ Q;
	Q = (PBTSQ)malloc(sizeof(BTSQ));
	if(Q){
		Q->front = 0;
		Q->rear = 0;
	}
	return Q;
}

int Empty_BTSQ(PBTSQ Q)
{
	if(Q && Q->front == Q->rear){
		return 1;
	}
	else{
		return 0;
	}
}

int In_BTSQ(PBTSQ Q, BTree x)
{
	if((Q->rear+1)%MaxTreeNodeNum == Q->front){
		printf("The Queue is full!");
		return -1;
	}
	else{
		//Q->bdata[Q->rear] = x;
		Q->rear = (Q->rear+1)%MaxTreeNodeNum;
		Q->bdata[Q->rear] = x;
		return 1;
	}
}

int Out_BTSQ(PBTSQ Q, BTree x)
{
	if(Empty_BTSQ(Q)){
		printf("The Queue is empty!");
		return -1;
	}
	else{
		//x = Q->bdata[Q->front];
		Q->front = (Q->front+1)%MaxTreeNodeNum;
		x = Q->bdata[Q->front];
	}
	return 1;
}

int Front_BTSQ(PBTSQ Q, BTree x)
{
	if(Q->front == Q->rear){
		printf("The Queue is empty!");
		return -1;
	}
	else{
		x = Q->bdata[(Q->front+1)%MaxTreeNodeNum];
		return 1;
	}
}

void Destroy_BTSQ(PBTSQ *Q)
{
	if(*Q){
		free(*Q);
	}
	*Q = NULL;
}

void Level_Order(BTree t)
{
	//PBTSQ Q;
	//Q = Init_BTSQ();
	//BTree Temp = t;
	printf("%c\t", t->data);
	//while(!(Q->front == Q->rear)){
		//Visit(Temp->data);
		//if(Temp->lchild){
			//In_BTSQ(Q, Temp->lchild);
		//}
		//if(Temp->rchild){
			//In_BTSQ(Q, Temp->rchild);
		//}
		//Out_BTSQ(Q, Temp);
	//}
	//Destroy_BTSQ(&Q);
}
