/* No test*/
#include "SearchHeader.h"
#include <stdio.h>

typedef struct avlnode{
	DataType_SH elem;
	/* balance factor: the depth difference of left tree and right tree
	 * bf = D(LT)-D(RT)*/
	int bf;
	struct avlnode *lchild, *rchild;
}AVLNode, *AVLTree;

/* When a node inserts into the left tree of A's left child*/
AVLTree LL_Rotate(AVLTree a)
{
	AVLTree b;
	b = a->lchild;
	a->lchild = b->rchild;
	b->rchild = a;
	a->bf = 0;
	b->bf = 0;
	return b;
}

/* When a node inserts into the right tree of A's right child*/
AVLTree RR_Rotate(AVLTree a)
{
	AVLTree b;
	b = a->rchild;
	a->rchild = b->lchild;
	b->lchild = a;
	a->bf = 0;
	b->bf = 0;
	return b;
}

/* When a node inserts into the left tree of A's right child*/
AVLTree LR_Rotate(AVLTree a)
{
	AVLTree b, c;
	b = a->lchild;
	c = b->rchild;
	a->lchild = c->rchild;
	b->rchild = c->lchild;
	c->lchild = b;
	c->rchild = a;
	if(c->bf == 1){
		a->bf = -1;
		b->bf = 0;
	}
	else if(c->bf == -1){
		a->bf = 0;
		b->bf = 1;
	}
	else{
		a->bf = 0;
		b->bf = 0;
	}
	c->bf = 0;
	return c;
}

AVLTree RL_Rotate(AVLTree a)
{
	AVLTree b, c;
	b = a->rchild;
	c = b->lchild;
	a->rchild = c->lchild;
	b->lchild = c->rchild;
	c->lchild = a;
	c->rchild = b;
	if(c->bf == 1){
		a->bf = 0;
		b->bf = -1;
	}
	else if(c->bf == -1){
		a->bf = 1;
		b->bf = 0;
	}
	else{
		a->bf = 0;
		b->bf = 0;
	}
	c->bf = 0;
	return c;
}

void AVLInsert(AVLTree *pavlt, AVLTree s)
{
	AVLTree f, a, b, p, q;
	if(*pavlt == NULL){
		*pavlt = s;
		return;
	}
	a = *pavlt;
	f = NULL;
	p = *pavlt;
	q = NULL;
	while(p != NULL){
		if(p->elem.key == s->elem.key){
			return;
		}
		if(p->bf != 0){
			a = p;
			f = q;
		}
		q = p;
		if(s->elem.key < p->elem.key){
			p = p->lchild;
		}
		else{
			p = p->rchild;
		}
	}
	if(s->elem.key < q->elem.key){
		q->lchild = s;
	}
	else{
		q->rchild = s;
	}
	p = a;
	while(p != s){
		if(s->elem.key < p->elem.key){
			p->bf++;
			p = p->lchild;
		}
		else{
			p->bf--;
			p = p->rchild;
		}
	}
	if(a->bf > -2 && a->bf < 2){
		return;
	}
	if(a->bf == 2){
		b = a->lchild;
		if(b->bf == 1){
			p = LL_Rotate(a);
		}
		else{
			p = LR_Rotate(a);
		}
	}
	else{
		b = a->rchild;
		if(b->bf == 1){
			p = RL_Rotate(a);
		}
		else{
			p = RR_Rotate(a);
		}
	}
	if(f == NULL){
		*pavlt = p;
	}
	else if(f->lchild == a){
		f->lchild = p;
	}
	else{
		f->rchild = p;
	}
}

/*B- Tree & B+ Tree*/
