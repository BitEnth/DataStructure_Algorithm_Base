/* Radix sort, distribution sort, bucket sort or bin sort*/
#include "SortHeader.h"
#define RADIX 10

/* Set bucket[0...9][...], namely, ten intervals:
 * [0, 1), [1, 2), ... ,[8, 9), [9, 10)*/
DataType_sort bucket[RADIX][MAXSIZE_SORT];
/* Record the length of each bucket*/
int count[RADIX];

int Reflect(KeyType_sort i, KeyType_sort m)
{
	int j;
	if(m != 0){
		j = i/m;
	}
	return j;
}

/* Put every element into relative bucket*/
void Distribute(DataType_sort r[], int len, int m)
{
	int i, j, k;
	k = 0;
	for(i = 1;i <= len;i++){
		j = Reflect(r[i].key, m);
		k = count[j];
		bucket[j][k] = r[i];
		count[j]++;
	}
}

/* Sort for every bucket. Due to less elements in a bucket, 
 * using straight insert sorting method to finish sorting*/
void BucketPartSort(DataType_sort r[][MAXSIZE_SORT], int len, int row)
{
	int i, j;
	DataType_sort tmp;
	for(i = 1;i < len;i++){
		tmp = r[row][i];
		j = i-1;
		while(j != -1 && tmp.key < r[row][j].key){
			r[row][j+1] = r[row][j];
			j--;
		}
		r[row][j+1] = tmp;
	}
}

void RadixSort(SqList_sort *sql, int m)
{
	int tmplen;
	int i, j, k;
	for(i = 0;i < RADIX;i++){
		count[i] = 0;
	}
	Distribute(sql->r, sql->length, m);
	for(i = 0;i < RADIX;i++){
		for(j = 0;j < 10;j++){
			printf(" %d ", bucket[i][j].key);
		}
		printf("\n %d \n", count[i]);
	}
	for(i = 0;i < RADIX;i++){
		tmplen = count[i];
		if(tmplen > 1){
			BucketPartSort(bucket, tmplen, i);
		}
	}
	/* Output elements of buckets to SqList*/
	for(i = 0, j = 1;i < RADIX;i++){
		tmplen = count[i];
		if(tmplen == 1){
			printf("bucket len = 1\n");
			printf(" %d ", bucket[i][0].key);
			sql->r[j] = bucket[i][0];
			j++;
			printf("\n");
		}
		else if(tmplen > 1){
			printf("bucket len != 1\n");
			for(k = 0;k < tmplen;k++){
				printf(" %d ", bucket[i][k].key);
				sql->r[j] = bucket[i][k];
				j++;
			}
			printf("\n");
		}
	}
}
