/*The first char array element stands for the length of array*/
#include <stdbool.h>

/*Bruce-Force Algorithm*/
int StrIndex_BF(char *s, char *t)
{
	int i = 1, j = 1;    /* i = 0, j = 0*/
	while(i<=s[0] && j<t[0]){
		if(s[i] == t[j]){
			i++;
			j++;
		}
		else{
			i = i-j+2;
			j = 1;
		}
	}
	if(j>t[0]){
		return (i-t[0]);
	}
	else{
		return -1;
	}
}

/*KMP Algorithm*/
int StrIndex_KMP(char *s, char *t, int pos, int next[])
{
	int i = pos, j = 1;
	while(i<=s[0] && j<=t[0]){
	    if(j == 0 || s[i] == t[j]){
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}
	if(j>t[0]){
		return (i-t[0]);
	}
	else{
		return -1;
	}
}

void GetNext(char *t, int next[])
{
	int i = 1,j = 0;
	next[1] = 0;
	while(i<t[0]){
		if(j == 0 || t[i] == t[j]){
			++i;
			++j;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}

void GetNext_Recursion(char *t, int next[], int L)
{
	if(L == 1){
		next[1] = 0;
		return;
	}
	GetNext_Recursion(t, next, L-1);
	int k = next[L-1];
	while(true){
		if(t[k] == t[L-1]){
			next[L] = k+1;
			return;
		}
		k = next[k];
		if(k == 0){
			next[L] = 1;
			return;
		}
	}
}
