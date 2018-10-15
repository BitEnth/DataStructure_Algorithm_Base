#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
	DataType data;
	struct node *next;
}StackNode, *PStackNode;

typedef struct {
	PStackNode top;
}LinkStack, *PLinkStack;

inline PLinkStack Init_LinkStack(void)
{
	PLinkStack S;
	S = (PLinkStack)malloc(sizeof(LinkStack));
	if (S) {
		S->top = NULL;
	}
	return S;
}

inline int Empty_LinkStack(PLinkStack S)
{
	return (S->top == NULL);
}

inline int Push_LinkStack(PLinkStack S, DataType x)
{
	PStackNode p;
	p = (PStackNode)malloc(sizeof(StackNode));
	if (!p)
	{
		printf("Out of memory!");
		return 0;
	}
	p->data = x;
	p->next = S->top;
	S->top = p;
	return 1;
}

inline int Pop_LinkStack(PLinkStack S, DataType *x)
{
	PStackNode p;
	if (Empty_LinkStack(S)) {
		printf("The stack is empty, cannot pop out elements from the stack");
		return 0;
	}
	*x = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	return 1;
}

inline int GetTop_LinkStack(PLinkStack S, DataType *x)
{
	if (Empty_LinkStack(S)) {
		printf("The stack is empty");
		return 0;
	}
	*x = S->top->data;
	return 1;
}

inline void Destroy_LinkStack(PLinkStack *LS)
{
	PStackNode p, q;
	if (*LS) {
		p = (*LS)->top;
		while (p) {
			q = p;
			p = p->next;
			free(q);
		}
		free(*LS);
	}
	*LS = NULL;
	return;
}