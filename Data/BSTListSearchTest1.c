#include "BSTListSearch.h"
#include <stdio.h>

void InOrder_BSTLS(PBinSeqTree b)
{
	if(b){
		InOrder_BSTLS(b->lchild);
		printf("%d\t", b->elem.key);
		InOrder_BSTLS(b->rchild);
	}
}

int Creat_BST(PBinSeqTree *t, int len, KeyType k[])
{
	int i;
	for(i = 0;i < len;i++){
		BSTInsert(t, k[i]);
	}
	return 1;
}

/* For the length of array, it would be better to get in main function 
 * which firstly defines the array, not in Creat_BST function. */
int main(void){
	PBinSeqTree *t = (PBinSeqTree*)calloc(1, sizeof(PBinSeqTree));
	int a[10] = {34, 18, 76, 52, 13, 67, 82, 58, 73, 19};
	int len = sizeof(a)/sizeof(a[0]);
	Creat_BST(t, len, a);
	InOrder_BSTLS(*t);
	printf("\n");
	BSTDelete(t, 76);
	InOrder_BSTLS(*t);
	return 0;
}

