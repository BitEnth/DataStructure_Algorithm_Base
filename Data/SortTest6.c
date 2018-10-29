#include "SortMerge.h"

int main(void)
{
	int key[10] = {75, 87, 68, 92, 88, 61, 77, 96, 80, 72};
	char info[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	SqList_sort *sql = CreatSqList_sort(key, info, 10);
	PrintSqList_sort(*sql);
	printf("-----------\n");
	MergeSort(sql);
	PrintSqList_sort(*sql);
	return 0;
}
