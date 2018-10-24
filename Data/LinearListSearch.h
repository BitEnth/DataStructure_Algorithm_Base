#include "SearchHeader.h"

typedef struct{
	DataType_SH r[MAXSIZE_SH];
	int length;
}Sqlist;

int SeqSearch(Sqlist s, KeyType k)
{
	int i;
	for(i = 0;i < s.length;i++){
		if(s.r[i].key == k){
			return i;
		}
	}
	return -1;
}

int SeqSearch_Opt(Sqlist s, KeyType k)
{
	int n;
	int i = 0;
	n = s.length;
	s.r[n].key = k;
	while(s.r[i].key != k){
		i++;
	}
	if(i == n){
		return -1;
	}
	else{
		return i;
	}
}

/* It's suitable for the sequential list*/
int BinSearch(Sqlist s, KeyType k)
{
	int low, mid, high;
	low = 0;
	high = s.length-1;
	while(low <= high){
		mid = (low+high)/2;
		if(s.r[mid].key == k){
			return mid;
		}
		else if(s.r[mid].key > k){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return -1;
}

/* The first row of Index array involves the biggest key words, 
 * the second row involves the begining address of block containing key words.
 * Firstly, the list will be equally divided into three blocks. The maximum of 
 * each block must be sequential. Then put them into index array.
 * Secondly, search in corresponding block according to index array.
 * need adjustment-----index array*/
int BlockSearch(Sqlist s, KeyType k, int Index[2][MAXSIZE_SH])
{
	int i;
	int low, high;
	low = -1;
	high = -1;
	for(i = 0;i < MAXSIZE_SH;i++){
		if(k < Index[1][i]){
			low = Index[2][i];
			break;
		}
	}
	if(low == -1){
		return -1;
	}
	else{
		high = Index[2][i+1];
		for(i = low;i < high;i++){
			if(s.r[i].key == k){
				return i;
			}
		}
		return -1;
	}
}
