#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node{
	int row, col;
	struct node *down, *right;
	union{
		struct node *next;
		DataType value;
	}
}crosslist;

crosslist *creatclinkmat(){
	int m, n, t, k, i, j, v, s;
	crosslist *p, *q, *head, *cp[100];
	printf("Please input the amount of the row, column and none-zeros");
	scanf("%d, %d, %d", &m, &n, &t);
	s = m > n ? m:n;
	p = (crosslist*)malloc(sizeof(crosslist));
	p->row = m;
	p->col = n;
	head = p;
	cp[0] = p;
	for(i = 1;i <= s;i++){
		p = (crosslist*)malloc(sizeof(crosslist));
		p->row = 0;
		p->col = 0;
		cp[i] = p;
		p->right = p;
		p->down = p;
		cp[i-1]->next = p;
	}
	cp[s]->next = head;
	for(k = 0;k < t;k++){
		printf("Input a triple group without zero\n");
		scanf("%d %d %d",&i, &j, &v);
		p = (crosslist*)malloc(sizeof(crosslist));
		p->row = i;
		p->col = j;
		p->value = v;
		q = cp[i];
		while((q->right!=cp[i])&&(q->right->col<j)){
			q = q->right;
		}
		p->right = q->right;
		q->right = p;
		q = cp[j];
		while((q->down!=cp[j])&&(q->down->row<i)){
			q = q->down;
		}
		p->down = q->down;
		q->down = p;
	}
	return head;
}
