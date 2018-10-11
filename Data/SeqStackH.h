#include <stdlib.h>
#define MAXSIZE 100

/*SeqStack Header DataType*/
typedef char SSHDT; 

typedef struct{
	SSHDT data[MAXSIZE];
	int top;
}SeqStack, *PSeqStack;

PSeqStack Init_SeqStack(void)
{
	PSeqStack S;
	S = (PSeqStack)malloc(sizeof(SeqStack));
	if(S){
		S->top = -1;
	}
	return S;
}

int Empty_SeqStack(PSeqStack S)
{
	if(S->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int Push_SeqStack(PSeqStack S, SSHDT x)
{
	if(S->top == MAXSIZE-1){
		return 0;
	}
	else{
		S->top++;
		S->data[S->top] = x;
		return 1;
	}
}

int Pop_SeqStack(PSeqStack S, SSHDT *x)
{
	if(Empty_SeqStack(S)){
		return 0;
	}
	else{
		*x = S->data[S->top];
		S->top--;
		return 1;
	}
}

int GetTop_SeqStack(PSeqStack S, SSHDT *x)
{
	if(Empty_SeqStack(S)){
		return 0;
	}
	else{
		*x = S->data[S->top];
		return 1;
	}
}

void Destroy_SeqStack(PSeqStack *S)
{
	if(*S){
		free(*S);
	}
	*S = NULL;
	return;
}
