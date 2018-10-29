#include "SortHeader.h"

void PrintDataTypeSort(DataType_sort d[], int len)
{
	int i;
	for(i = 1;i <= len;i++){
		printf(" %d ", d[i].key); 
	}
}

/* r[u...v] + r[v+1...t] => rf[u...t]*/
void Merge(DataType_sort r[], DataType_sort rf[], int u, int v, int t)
{
	int i, j, k;
	for(i = u, j = v+1, k = u;i <= v && j <= t;k++){
		if(r[i].key <= r[j].key){
			rf[k] = r[i];
			i++;
		}
		else{
			rf[k] = r[j];
			j++;
		}
	}
	/* Copy the rest elements of r[] to rf[]
	 * rf[k] = r[i]; k++, i++;*/
	while(i <= v){
		rf[k++] = r[i++];
	}
	while(j <= t){
		rf[k++] = r[j++];
	}
	printf("Merge after\n");
	PrintDataTypeSort(rf, t-u+1);
	printf("\n");
	i = 0;
	while(i < t){
		i++;
		r[i] = rf[i];
	}
}

/* p[n...t]*/
void MSort(DataType_sort p[], DataType_sort p1[], int n, int t)
{
	if(t > n){
		int m = (n+t)/2;
		MSort(p, p1, n, m);
		printf("Left Merge\n");
		PrintDataTypeSort(p, 10);
		printf("\n");
		PrintDataTypeSort(p1, 10);
		printf("\n");
		MSort(p, p1, m+1, t);
		printf("Right Merge\n");
		PrintDataTypeSort(p, 10);
		printf("\n");
		PrintDataTypeSort(p1, 10);
		printf("\n");
		Merge(p, p1, n, m, t);
	}
}

void MergeSort(SqList_sort *s)
{
	DataType_sort p1[MAXSIZE_SORT];
	int i;
	for(i = 0;i < MAXSIZE_SORT;i++){
		p1[i].key = 0;
	}
	MSort(s->r, p1, 1, s->length);
}

