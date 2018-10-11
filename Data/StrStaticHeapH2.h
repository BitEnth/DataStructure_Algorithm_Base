#include <stdio.h>
#include <stdlib.h>
#define SAMX 1024

typedef struct
{
	int length;
	int stradr;   /*beginning address*/
}Hstring;

char store[SMAX+1];
int free_p;

int Init_SSHH(void){
	store = (char*)malloc((SMAX+1)*sizeof(char));
	free_p = 0;
}

int Strlength(char *s){
	int i = 0;
	while(s[i]!='\0') i++;
	return i;
}

int StrAssign(Hstring *s1, char *s2)
{
	int i = 0, len;
	len = Strlength(s2);
	if(len<0||free_p+len-1>SMAX){
		return 0;
	}
	else{
		for(i=0;i<len;i++){
			store[free_p+i] = s2[i];
		}
		s1->stradr = free_p;
		s1->length = len;
		free_p = free_p + len;
		return 1;
	}
}

int StrCopy(Hstring *s1, Hstring s2)
{
	int i;
	if(free_p+s2.length-1>SMAX){
		return 0;
	}
	else{
		for(i = 0;i < s2.length;i++){
			store[free_p+i] = store[s2.stradr+i];
		}
		s1->length = s2.length;
		s1->stradr = free_p;
		free_p = free_p + s2.length;
		return 1;
	}
}

int StrSub(Hstring *t, Hstring s, int i, int len)
{
	int i;
	if(i<0||len<0||len>s.length-i+1){
		return 0;
	}
	else{
		t->length = len;
		t->stradr = s.stradr + i - 1;
		return 1;
	}
}

void StrConcat(Hstring s1, Hstring s2, Hstring *s)
{
	int free_temp = free_p;
	if(free_p + s1.length + s2.length-1 > SMAX){
		return 0;
	}
	else{
		StrCopy(s,s1);
		StrCopy(s,s2);
		s->length = s1.length + s2.length;
		s->stradr = free_temp;
		return 1;
	}
}
