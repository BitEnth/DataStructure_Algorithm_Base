#include "SortHeader.h"

void BubbleSort(SqList_sort *s)
{
	int i, j;
	int flag;
	for(i = 1;i < s->length;i++){
		flag = 0;
		for(j = 2;j <= 1+s->length-i;j++){
			if(s->r[j].key < s->r[j-1].key){
				s->r[0] = s->r[j];
				s->r[j] = s->r[j-1];
				s->r[j-1] = s->r[0];
				flag = 1;
			}
		}
		if(!flag){
			break;
		}
	}
}

/* s->length = high - low + 1
 * namely, at the first low is the beginning of s, high is the end of s.
 * For Example, in s[10], low = 1, high = 10
 * That is to say, s[1].key must be the pivotkey at the beginning.*/
int QuickSort_FirstStep(SqList_sort *s, int low, int high)
{
	KeyType_sort pivotkey;
	s->r[0] = s->r[low];
	pivotkey = s->r[low].key;
	while(low < high){
		while(low < high && s->r[high].key >= pivotkey){
			high--;
		}
		s->r[low] = s->r[high];
		while(low < high && s->r[low].key <= pivotkey){
			low++;
		}
		s->r[high] = s->r[low];
	}
	s->r[low] = s->r[0];
	return low;
}

void QuickSort(SqList_sort *s, int low, int high)
{
	int pivotloc;
	if(low < high){
		pivotloc = QuickSort_FirstStep(s, low, high);
		QuickSort(s, low, pivotloc-1);
		QuickSort(s, pivotloc+1, high);
	}
}
