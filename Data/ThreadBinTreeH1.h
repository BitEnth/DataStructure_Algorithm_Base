#include <stdio.h>

typedef char TBTDT;

typedef struct Threadnode{
	int ltag, rtag;
	TBTDT data;
	struct Threadnode *lchild, *rchild;
}Tnode, *PTnode;

void InThread(PTnode t, PTnode pre)
{
	if(t){
		InThread(t->lchild, pre);
		if(t->lchild == NULL){
			t->ltag = 1;
			t->lchild = pre;
		}
		if(t->rchild == NULL){
			t->rtag = 1;
		}
		if((pre) && (pre->rtag == 1)){
			pre->rchild = t;
		}
		pre = t;
		InThread(t->rchild, pre);	
	}
}

void InOrderTh(PTnode t)
{
	PTnode p;
	if(t){
		p = t;
		while(p->ltag == 0){
			p = p->lchild;
		}
		while(p){
			printf("%c\t", p->data);
			p = InPostNode(p);
		}
	}
}

PTnode InPreNode(PTnode p)
{
	PTnode pre;
	pre = p->lchild;
	if(p->ltag == 1){
		return pre;
	}
	else{
		while(pre->rtag == 0){
			pre = pre->rchild;
		}	
	}
	return pre;
}

PTnode InPostNode(PTnode p)
{
	PTnode post;
	post = p->rchild;
	if(p->rtag == 1){
		return post;
	}
	else{
		while(post->ltag == 0){
			post = post->lchild;
		}
	}
	return post;
}

PTnode InOrder_ThTree_Search(PTnode t, TBTDT x)
{
	PTnode p;
	p = t;
	if(p){
		while(p->ltag == 0){
			p = p->lchild;
		}
		while(p && p->data != x){
			p = InPostNode(p);
		}
	}
	return p;
}

void InsertThrRight(PTnode s, PTnode p)
{
	PTnode w;
	p->rchild = s->rchild;
	p->rtag = s->rtag;
	p->ltag = 1;
	p->lchild = s;
	s->rtag = 0;
	s->rchild = p;
	if(p->rtag == 0){
		w = InPostNode(p);
		w->lchild = p;
	}
}
