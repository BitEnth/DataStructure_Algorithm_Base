#include "BinaryTreeH1.h"
//#include "BTSeqQueueH1.h"
#include <stdlib.h>

int main(void)
{
	BTree b1, b2, b3, b4, b5, b6, b7, b8;
	//BTree b0;
	//Init_Bnode(b0);
	//b0->lchild = &b1;
	b1 = (BTree)malloc(sizeof(Bnode));
	b2 = (BTree)malloc(sizeof(Bnode));
	b3 = (BTree)malloc(sizeof(Bnode));
	b4 = (BTree)malloc(sizeof(Bnode));
	b5 = (BTree)malloc(sizeof(Bnode));
	b6 = (BTree)malloc(sizeof(Bnode));
	b7 = (BTree)malloc(sizeof(Bnode));
	b8 = (BTree)malloc(sizeof(Bnode));
	b1->data = 'A';
	b1->lchild = b2;
	b1->rchild = b3;
	b2->data = 'B';
	b2->lchild = b4;
	b3->data = 'C';
	b3->lchild = b5;
	b3->rchild = b6;
	b4->data = 'D';
	b4->rchild = b7;
	b5->data = 'E';
	b6->data = 'F';
	b6->lchild = b8;
	b7->data = 'G';
	b8->data = 'H';
	PreOrder_Recursion(b1);
	//PreOrder_SeqStack(b1);
	printf("\n");
	InOrder_Recursion(b1);
	printf("\n");
	PostOrder_Recursion(b1);
	printf("\n");
	Level_Order(b1);
	return 1;
}
