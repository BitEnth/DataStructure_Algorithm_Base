#include "SortHeader.h"

void SimpleSelectSort(SqList_sort *s)
{
	int i, j, t;
	for(i = 1;i < s->length;i++){
		for(j = i+1, t = i;j <= s->length;j++){
			if(s->r[t].key > s->r[j].key){
				t = j;
			}
		}
		s->r[0] = s->r[t];
		s->r[t] = s->r[i];
		s->r[i] = s->r[0];
	}
}

/* s->r[n....m], i begins from 1.
 * Big Top Heap: r[i]>=r[2i] && r[i]>=r[2i+1]
 * Small Top Heap: r[i]<=r[2i] && r[i]<=r[2i+1]*/
void HeapAdjust(SqList_sort *s, int n, int m)
{
	int i, j;
	DataType_sort rc;
	rc = s->r[n];
	i = n;
	for(j = 2*i;j <= m;j = j*2)
	{
		if(j < m && s->r[j].key < s->r[j+1].key){
			j = j+1;
		}
		/*big top heap. if small top heap, then change to '<'*/
		if(rc.key > s->r[j].key){
			break;
		}
		s->r[i] = s->r[j];
		i = j;
	}
	s->r[i] = rc;
}

void HeapSort(SqList_sort *s)
{
	int i;
	/* adjust the array constantly to advance big values
	 * the first one must be biggest value*/
	for(i = s->length/2;i > 0;i--){
		HeapAdjust(s, i, s->length);
	}
	/* retreat the first value to the end of array.
	 * Then adjust the rest of array.*/
	for(i = s->length;i > 1;i--){
		s->r[0] = s->r[1];
		s->r[1] = s->r[i];
		s->r[i] = s->r[0];
		HeapAdjust(s, 1, i-1);
	}
}

