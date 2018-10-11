#include "StrHeapH1.h"

int main(void)
{
	char str1[5] = {'A','h','9','t','%'};
	char str2[3] = {'+','^','?'};
	Hstring *s1_p;
	Hstring *s2_p;
	Hstring s2;
	Hstring s1;
	s1_p = &s1;
	s2_p = &s2;
	Init_String(s1_p);
	Init_String(s2_p);
	StrAssign(s1_p, str1);
	printf("%s\n", s1_p->p_ch);
	s2.p_ch = str2;
	s2.length = 3;
	StrInsert(s1_p,3,s2);
	printf("%s\n",s1_p->p_ch);
	Destroy_String(s1_p);
	//Destroy_String(s2_p);    //???duble free.
	return 0;
}
