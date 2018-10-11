#include <stdio.h>
#include <stdlib.h>
#define MaxTreeNodeNum 100

typedef char DataType;

/*Sequential Storage*/
typedef struct{
	DataType data[MaxTreeNodeNum];
	int n;
}QBTree;

/*Dynamic Linked Storage*/
typedef struct bnode{
	DataType data;
	struct bnode *lchild, *rchild;   /*probably adding *parent*/
}Bnode, *BTree;

int Init_Bnode(BTree t)
{
	if(!(t = (BTree)malloc(sizeof(Bnode)))){
		return 0;
	}
	t->data = ' ';
	t->lchild = NULL;
	t->rchild = NULL;
	return 1;
}

int Creat_Bnode(BTree t, DataType c)
{
	Init_Bnode(t);
	t->data = c;
	return 1;
}

void Visit(DataType da)
{
	printf("%c\t", da);
}

void PreOrder_Recursion(BTree t)
{
	if(t){
		Visit(t->data);
		PreOrder_Recursion(t->lchild);
		PreOrder_Recursion(t->rchild);
	}
}

void PreOrder_LikeStack(BTree t)
{
	BTree p = t;
	//BTree p1 = t->rchild;
	//BTree *p3 = &p1;
	BTree ptemp = (BTree)malloc(sizeof(Bnode));
	while(p){
		Visit(p->data);
		ptemp = p;
		if(p->lchild){
			p = p->lchild;
		}
		else if(p->rchild){
			p = p->rchild;
		}
		else{
			p = ptemp;
		}
	}
}

void InOrder_Recursion(BTree t)
{
	if(t){
		InOrder_Recursion(t->lchild);
		Visit(t->data);
		InOrder_Recursion(t->rchild);
	}
}

void PostOrder_Recursion(BTree t)
{
	if(t){
		PostOrder_Recursion(t->lchild);
		PostOrder_Recursion(t->rchild);
		Visit(t->data);
	}
}

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
	//if(Q);
	if(Q->front == Q->rear){
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
/*every value should be assigned respectively, do not together directly*/
		Q->front = (Q->front+1)%MaxTreeNodeNum;
		x->data = Q->bdata[Q->front]->data;
		x->lchild = Q->bdata[Q->front]->lchild;
		x->rchild = Q->bdata[Q->front]->rchild;
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
	PBTSQ Q;
	Q = Init_BTSQ();
	//printf("%d, %d\n", Q->front, Q->rear);
	/*give Temp a new piece of memory, do not use "Temp = t"*/
	BTree Temp = (BTree)malloc(sizeof(Bnode));
	Temp->data = t->data;
	Temp->lchild = t->lchild;
	Temp->rchild = t->rchild;
	//printf("%d, %d\n", Q->front, Q->rear);
	Visit(Temp->data);
	while(1){
		if(Temp->lchild){
			In_BTSQ(Q, Temp->lchild);
			//printf("in queue %d, %d\n", Q->front, Q->rear);
		}
		if(Temp->rchild){
			In_BTSQ(Q, Temp->rchild);
			//printf("in queue %d, %d\n", Q->front, Q->rear);
		}
		Out_BTSQ(Q, Temp);
		Visit(Temp->data);
		//printf("out queue %d, %d\n", Q->front, Q->rear);
		if(Q->front == Q->rear){
			break;
		}
	}
	Destroy_BTSQ(&Q);
}
