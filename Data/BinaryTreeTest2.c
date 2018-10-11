#include "BinaryTreeH2.h"

int main(void){
	BTree t;
	t = CreatBinTree();
	char chinput;
	while(1){
		printf("1 for root node, 2 for left node, 3 for right node\n");
		printf("Please input the choice: ");
		chinput = getchar();
		switch(chinput){
		case '1':
			t = CreatBinTree();
		case '2':
			t->lchild = CreatBinTree();
			break;
		case '3':
			t->rchild = CreatBinTree();
			break;
		default:
			break;
		}
	}
	Level_Order(t);
	return 1;
}
