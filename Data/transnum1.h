#pragma once
#include "linkstack.h"

inline int conversion(int n, int r)
{
	PLinkStack S;
	DataType x;
	if (!r) {
		printf("The basical number cannot be zero!");
		return 0;
	}
	S = Init_LinkStack();
	if (!S) {
		printf("Fail to build up a stack!");
		return 0;
	}
	while (n) {
		Push_LinkStack(S, n%r);
		n = n / r;
	}
	while (!Empty_LinkStack(S)) {
		Pop_LinkStack(S, &x);
		printf("%d", x);
	}
	Destroy_LinkStack(&S);
}