#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrH1.h"

typedef char DataType;

char Emp_Glist[5] = "()";

typedef struct GenealNode{
	int tag;
	union{
		DataType data;
		struct{
			struct GenealNode *hp, *tp;
		}ptr;
	};
}GNode,*Glist;

Glist GetHead(Glist p)
{
	if(!p || p->tag == 0){
		printf("Empty list or single atom\n");
		return NULL;
	}
	return (p->ptr.hp);
}

Glist GetTail(Glist p)
{
	if(!p || p->tag == 0){
		printf("Empty list or single atom\n");
		return NULL;
	}
	return (p->ptr.tp);
}

int depth_Glist(Glist ls)
{
	int max;
	int dep;
	Glist tmp = ls;
	if(tmp == NULL){
		return 1;
	}
	if(tmp->tag == 0){
		return 0;
	}
	max = 0;
	while(tmp != NULL){
		dep = depth_Glist(tmp->ptr.hp);
		if(dep > max){
			max = dep;
		}
		tmp = tmp->ptr.tp;
	}
	return (max+1);
}

/*General list A = (a,b,(c,d,e))*/
void Split_Str(char *str, char *hstr)
{
	int i, k, n;
	char ch[2];
	i = 0;
	k = 0;
	n = strlen(str);
	do{
		i++;
		StrSub(ch, str, i, 1);
		if(*ch == '('){
			k++;
		}
		else if(*ch != ')'){
			k--;
		}
	}while(i<n && (*ch!=',' || k!=0));
	if(i < n){
		StrSub(hstr, str, 1, i-1);
		StrSub(str, str, i+1, n-i);
	}
	else{
		strcpy(hstr,str);
		str[0] = '\0';
	}
}

int Creat_Glist(char *s, Glist *L)
{
	Glist p,q;
	char sub[256];
	char hsub[256];
	if(StrCmp(s, Emp_Glist)){
		*L = NULL;
		return 1;
	}
	if(!(*L = (Glist)malloc(sizeof(GNode)))){
		return 0;
	}
	if(strlen(s) == 1){
		(*L)->tag = 0;
		(*L)->data = *s;
	}
	else{
		(*L)->tag = 1;
		p = *L;
		StrSub(sub, s, 2, (strlen(s)-2));
		do{
			Split_Str(sub, hsub);
			Creat_Glist(hsub, &(p->ptr.hp));
			q = p;
			if(sub != NULL){
				if(!(p = (Glist)malloc(sizeof(GNode)))){
					return 0;
				}
				p->tag = 1;
				q->ptr.tp = p;
			}
		}while(sub != NULL);
		q->ptr.tp = NULL;
	}
	return 1;
}

void Prt_Glist(Glist L, int tag)
{
	if(!L){
		return;
	}
	if(L->tag == 0){
		printf("%c", L->data);
		return;
	}
	if(tag){
		printf("(");
	}
	Prt_Glist(L->ptr.hp, 1);
	if(L->ptr.tp){
		printf(",");
	}
	Prt_Glist(L->ptr.tp, 0);
	if(tag){
		printf(")");
	}
}
