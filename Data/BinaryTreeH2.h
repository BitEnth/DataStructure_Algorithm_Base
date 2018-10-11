#include "BinaryTreeH1.h"

int Count_Tree_v(BTree t)
{
	int count = 0;
	if(t){
		Count_Tree_v(t->lchild);
		Visit(t->data);
		count = count + 1;
		Count_Tree_v(t->rchild);
	}
	return count;
}

int Count_Tree_lr(BTree t)
{
	int lcount, rcount;
	if(t == NULL){
		return 0;
	}
	lcount = Count_Tree_lr(t->lchild);
	rcount = Count_Tree_lr(t->rchild);
	return (lcount + rcount + 1);
}

int Height_Tree(BTree t)
{
	int h1, h2;
	if(t == NULL){
		return 0;
	}
	else{
		h1 = Height_Tree(t->lchild);
		h2 = Height_Tree(t->rchild);
		if(h1 > h2){
			return (h1 + 1);
		}
		return (h2 + 1);
	}
}

BTree CopyTree(BTree t)
{
	BTree p, q, s;
	if(t == NULL){
		return NULL;
	}
	p = CopyTree(t->lchild);
	q = CopyTree(t->rchild);
	s = (BTree)malloc(sizeof(Bnode));
	s->data = t->data;
	s->lchild = p;
	s->rchild = q;
	return s;
}

/*the input format is AB#D##CE...(preorder) , # stands for empty node
 * the data must be int in Linux, or will be disturbed by mutithreading*/
BTree CreatBinTree(void)
{
	BTree t;
	char ch;
	printf("Please input the data of node: ");
	ch = getchar();
	if(ch == '#'){
		t = NULL;
	}
	else{
		t = (BTree)malloc(sizeof(Bnode));
		t->data = ch;
		//t->lchild = CreatBinTree();
		//t->rchild = CreatBinTree();
	}
	return t;
}

/*L stands for level, num[i] is equal to the number of nodes in L level*/
void Levcount(BTree t, int L, int num[])
{
	if(t){
		Visit(t->data);
		num[L]++;
		Levcount(t->lchild, L+1, num);
		Levcount(t->rchild, L+1, num);
	}
}
