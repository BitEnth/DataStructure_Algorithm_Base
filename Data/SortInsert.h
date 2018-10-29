#include "SortHeader.h"

void StraightInsertSort(SqList_sort *s)
{
	int i, j;
	for(i = 2;i <= s->length;i++){
		s->r[0] = s->r[i];
		j = i-1;
		while(s->r[0].key < s->r[j].key){
			s->r[j+1] = s->r[j];
			j--;
		}
		s->r[j+1] = s->r[0];
	}
}

void BinaryInsertSort(SqList_sort *s)
{
	int low, high, mid;
	int i, j;
	for(i = 2;i <= s->length;i++){
		s->r[0] = s->r[i];
		low = 1;
		high = i-1;
		while(low <= high){
			mid = (low + high)/2;
			if(s->r[0].key >= s->r[mid].key){
				low = mid + 1;
			}
			else{
				high = mid -1;
			}
		}
		for(j = i-1;j >= high+1;j--){
			s->r[j+1] = s->r[j];
		}
		s->r[high+1] = s->r[0];
	}
}

void ShellInsert(SqList_sort *s, int gap)
{
	int i, j;
	for(i = gap+1;i <= s->length;i++){
		if(s->r[i].key < s->r[i-gap].key){
			s->r[0] = s->r[i];
			for(j = i-gap;j > 0 && s->r[0].key < s->r[j].key;j = j-gap){
				s->r[j+gap] = s->r[j];
			}
			s->r[j+gap] = s->r[0];
		}
	}
}

void ShellSort(SqList_sort *s, int gaps[], int len)
{
	int k;
	for(k = 0;k < len;k++){
		ShellInsert(s, gaps[k]);
	}
}
