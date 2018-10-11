#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char *p_ch;
	int length;
}Hstring;

int StrAssign(Hstring *s1, char *s2)
{
	int i ,j;
	char *pc;
	if(s1->p_ch){
		free(s1->p_ch);
	}
	for(i = 0,pc = s2;*pc != '\0';i++,pc++);
	if(i == 0){
		s1->p_ch = 0;
		s1->length = 0;
		return 0;
	}
	if(!(s1->p_ch = (char*)malloc(i*sizeof(char)))){
		printf("Heap memory is not enough, fail to assign value!\n");
		return 0;
	}
	for(j = 0;j < i;j++){
		s1->p_ch[j] = s2[j];
	}
	s1->length = i;
	return 1;
}

int StrCopy(Hstring *s1, Hstring s2)
{
	int i;
	if(s2.length<=0){
		return 0;
	}
	if(!(s1->p_ch = (char*)malloc(s2.length*sizeof(char)))){
		printf("Heap memory is not enough, fail to assign value!\n");
		return 0;
	}
	for(i = 0;i < s2.length;i++){
		s1->p_ch[i] = s2.p_ch[i];
	}
	s1->length = s2.length;
	return 1;
}

int SubString(Hstring *Sub, Hstring S, int pos, int len)
{
	int i;
	if(pos<1||pos>S.length||len<0||len>(S.length-pos+1)){
		return 0;
	}
	if(Sub->p_ch){
		free(Sub->p_ch);
	}
	if(!len){
		Sub->p_ch = 0;
		Sub->length = 0;
	}
	else{
		Sub->p_ch = (char*)malloc(len*sizeof(char));
		for(i = 0;i < len;i++){
			Sub->p_ch[i] = S.p_ch[pos-1+i];
		}
		Sub->length = len;
	}
	return 1;
}

int StrConcat(Hstring *t, Hstring s1, Hstring s2)
{
	int i;
	if(t->p_ch){
		free(t->p_ch);
	}
	if(!(t->p_ch = (char*)malloc((s1.length+s2.length)*sizeof(char)))){
		printf("Heap memory is not enough, fail to concat!\n");
		return 0;
	}
	for(i = 0;i < s1.length;i++){
		t->p_ch[i] = s1.p_ch[i];
	}
	t->length = (s1.length+s2.length);
	for(i = s1.length;i < t->length;i++){
		t->p_ch[i] = s2.p_ch[i-s1.length];
	}
	return 1;
}

int StrInsert(Hstring *s, int pos, Hstring t)
{
	int i;
	if(pos<1||pos>(s->length+1)){
		return 0;
	}
	if(t.length == 0){
		return 1;
	}
	if(!(s->p_ch = (char*)realloc(s->p_ch, (s->length+t.length)*sizeof(char)))){
		printf("Heap memory is not enough, fail to insert!\n");
		return 0;
	}
	for(i = (s->length-1);i>=pos-1;i--){
		s->p_ch[i+t.length] = s->p_ch[i];
	}
	for(i = pos-1;i <= (pos+t.length-2);i++){
		s->p_ch[i] = t.p_ch[i-pos+1];
	}
	s->length = s->length+t.length;
	return 1;
}

int Init_String(Hstring *s)
{
	s->p_ch = 0;
	s->length = 0;
	return 1;
}

int Destroy_String(Hstring *s)
{
	if(s->length){
		free(s->p_ch);
		s->p_ch = 0;
		s->length = 0;
	}
	return 1;
}
