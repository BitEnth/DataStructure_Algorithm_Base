// PointerTest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int a[6] = { 1,2,3,5,8,13 };
	int *p = a;
	int **pp = &p;
	printf("*p指向的地址：%d\n", p);
	printf("数组的地址：%d\n", &a);
	printf("p本身的地址：%d\n", &p);
	printf("pp指向的p指针的地址：%d\n", pp);
	printf("*pp指向p所指向的地址，即数组地址：%d\n", *pp);
	printf("**pp指向数组值：%d\n", **pp);
	printf("%d\n", *p);
	printf("%d\n", *(p + 3));
	printf("%d\n", *p + 3);
	p = NULL;
	pp = NULL;
	//printf("a[0]=%d\n", *p);
	//printf("%d\n", *pp);
	printf("%d\n", &pp);
	printf("%d\n", p);
	printf("%d\n", &p);
    return 0;
}

