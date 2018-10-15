#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int DataType;
typedef struct {
	DataType data[MAXSIZE];
	int top;
}SeqStack, *PSeqStack;

inline PSeqStack Init_SeqStack(void)
{
	PSeqStack S;
	S = (PSeqStack)malloc(sizeof(SeqStack));
	if (S) {
		S->top = -1;
	}
	return S;
}

inline int Empty_SeqStack(PSeqStack S)
{
	if (S->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

inline int Push_SeqStack(PSeqStack S, DataType x) 
{
	if (S->top == MAXSIZE - 1) {
		return 0;
	}
	else {
		S->top++;
		S->data[S->top] = x;
		return 1;
	}
}

inline int Pop_SeqStack(PSeqStack S, DataType *x)
{
	if (Empty_SeqStack(S)) {
		return 0;
	}
	else {
		*x = S->data[S->top];
		S->top--;
		return 1;
	}
}

inline int GetTop_SeqStack(PSeqStack S, DataType *x)
{
	if (Empty_SeqStack(S)) {
		return 0;
	}
	else {
		*x = S->data[S->top];
		return 1;
	}
}

inline void Destroy_SeqStack(PSeqStack *S)
{
	if (*S) {
		free(*S);
	}
	*S = NULL;
	return;
}