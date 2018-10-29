#include "SortRadix.h"

int main(void)
{
	int key[10] = {179, 208, 306, 93, 859, 984, 55, 9, 271, 33};
	char info[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	SqList_sort *sql = CreatSqList_sort(key, info, 10);
	PrintSqList_sort(*sql);
	printf("-------------\n");
	RadixSort(sql, 100);
	PrintSqList_sort(*sql);
	return 0;
}
