/*Binary Sequential Tree List Seaarch*/
#include "SearchHeader.h"
#include <stdlib.h>

typedef struct BSTNode{
	DataType_SH elem;
	struct BSTNode *lchild;
	struct BSTNode *rchild;
}BinSeqTree, *PBinSeqTree;

PBinSeqTree BSTSearch(PBinSeqTree t, KeyType k)
{
	if(t == NULL){
		return NULL;
	}
	if(t->elem.key == k){
		return t;
	}
	else if(t->elem.key > k){
		return BSTSearch(t->lchild, k);
	}
	else{
		return BSTSearch(t->rchild, k);
	}
}

void BSTInsert(PBinSeqTree *t, KeyType k)
{
	PBinSeqTree r;
	if(*t == NULL){
		r = (PBinSeqTree)malloc(sizeof(BinSeqTree));
		r->elem.key = k;
		r->lchild = NULL;
		r->rchild = NULL;
		*t = r;
		return;
	}
	else{
		if(k < ((*t)->elem.key)){
			BSTInsert(&((*t)->lchild), k);
		}
		else{
			BSTInsert(&((*t)->rchild), k);
		}
	}
}

/* It can work out when creat the binary sequential tree through array 
 * or BSTInsert and Creat_BST function, not a created and special tree, 
 * otherwise something wrong will take place.
 * This function can maintain the depth of tree.*/
int BSTDelete(PBinSeqTree *bt, KeyType k)
{
	PBinSeqTree f, p, q, s;
	p = *bt;
	f = NULL;
	while(p && p->elem.key != k){
		f = p;
		if(p->elem.key > k){
			p = p->lchild;
		}
		else{
			p = p->rchild;
		}
	}
	if(p == NULL){
		return 0;
	}
	if(p->lchild == NULL){
		if(f == NULL){
			/*when the deleting node is root node*/
			*bt = p->rchild;
		}
		else if(f->lchild == p){
			f->lchild = p->rchild;
		}
		else{
			f->rchild = p->rchild;
		}
		free(p);
	}
	else{
		q = p;
		s = p->lchild;
		/* from left child tree of p to find out the biggest key value
		 * Also, we can find the least key value from right tree of p to
		 * replace p, namely, s = p->rchild.*/
		while(s->rchild){
			q = s;
			s = s->rchild;
		}
		if(q == p){
			q->lchild = s->lchild;
		}
		else{
			q->rchild = s->lchild;
		}
		p->elem.key = s->elem.key;
		free(s);
		return 1;
	}
	return 0;
}
