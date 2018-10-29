#include "SortSelection.h"

int main(void)
{
	int key[8] = {53, 36, 30, 91, 47, 36, 24, 85};
	char info[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	SqList_sort *sql = CreatSqList_sort(key, info, 8);
	PrintSqList_sort(*sql);
	printf("-------------\n");
	HeapSort(sql);
	PrintSqList_sort(*sql);
	return 0;
}

