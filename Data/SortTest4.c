#include "SortSelection.h"

int main(void)
{
	int key[10] = {75, 87, 68, 92, 88, 61, 77, 87, 80, 72};
	char info[10] = {'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};
	SqList_sort *sql = CreatSqList_sort(key, info, 10);
	PrintSqList_sort(*sql);
	printf("-----------\n");
	SimpleSelectSort(sql);
	PrintSqList_sort(*sql);
	return 0;
}
