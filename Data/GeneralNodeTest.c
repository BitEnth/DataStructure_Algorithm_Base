#include "GeneralNodeH.h"

int main(void){
	//Glist L1 = (Glist)malloc(sizeof(GNode));
	//L1->tag = 1;
	//L1->data = 'a';
	Glist L1;
	Glist *L2;
	L2 = &L1;
	char s1[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	Creat_Glist(s1,L2);
	Prt_Glist(L1, 1);
	return 0;
}
