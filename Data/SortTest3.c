#include "SortExchange.h"

int main(void)
{
	int key[10] = {75, 87, 68, 92, 88, 61, 77, 96, 88, 72};
	char info[10] = {')', '!', '@', '#', '$', '%', '^', '&', '*', '('};
	SqList_sort *sql;
	sql = CreatSqList_sort(key, info, 10);
	PrintSqList_sort(*sql);
	printf("------------------\n");
	//BubbleSort(sql);
	QuickSort(sql, 1, 10);
	PrintSqList_sort(*sql);
	return 0;
}

