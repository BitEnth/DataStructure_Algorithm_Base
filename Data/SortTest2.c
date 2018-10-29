#include <time.h>
#include "SortInsert.h"

clock_t start, finish;
int total;

int main(void)
{
	int key[14] = {39, 80, 76, 41, 13, 29, 50, 78, 30, 11, 100, 7, 41, 86};
	char info[14] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'};
	int gaps[3] = {5, 3, 1};
	SqList_sort *sql = CreatSqList_sort(key, info, 14);
	PrintSqList_sort(*sql);
	printf("-----------------\n");
	start = clock();
	ShellSort(sql, gaps, 3);
	finish = clock();
	total = finish-start;
	PrintSqList_sort(*sql);
	printf("cost time: %d", total);
	return 0;
}
