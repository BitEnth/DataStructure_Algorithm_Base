#include <stdio.h>
#define MAXSIZE 256
//char s[MAXSIZE];
typedef struct
{
	char data[MAXSIZE];
	int Length;
}SeqString;

int StrLength(char *s)
{
	int i = 0;
	while(s[i]!='\0') i++;
	return(i);
}

int StrConcat(char *s1, char *s2, char *s)
{
	int i = 0, j, len1, len2;
	len1 = StrLength(s1);
	len2 = StrLength(s2);
	if(len1 + len2 > MAXSIZE-1){
		return 0;
	}
	j = 0;
	while(s1[j]!='\0'){
		s[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while(s2[j]!='\0'){
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return 1;
}

int StrSub(char *t, char *s, int i, int len)
{
	int slen, j;
	slen = StrLength(s);
	if(i<1||i>slen||slen<0||slen-i+1){
		printf("Wrong parameter");
		return 0;
	}
	for(j = 0;j < len;j++){
		t[j] = s[i+j-1];
	}
	t[j]='\0';
	return 1;
}

int StrCmp(char *s1, char *s2)
{
	int i = 0;
	while(s1[i] == s2[i] && s1[i]!='\0'){
		i++;
	}
	return (s1[i] == s2[i]);
}
