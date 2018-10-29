#include <time.h>
#include "SortInsert.h"

clock_t start, finish;
int total_time;

int main(void)
{
	int key[10] = {75, 88, 68, 92, 88, 62, 77, 96, 80, 72};
	char info[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	SqList_sort *sql = CreatSqList_sort(key, info, 10);
	PrintSqList_sort(*sql);
	printf("--------------------\n");
	start = clock();
	//StraightInsertSort(sql);
	BinaryInsertSort(sql);
	finish = clock();
	total_time = (finish-start);
	PrintSqList_sort(*sql);
	printf("cost time: %d", total_time);
	return 0;
}
