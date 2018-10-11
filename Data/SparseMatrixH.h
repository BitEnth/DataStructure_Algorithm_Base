#include <stdio.h>
#define MAXSIZE 1000

typedef int DataType;

typedef struct{
	/*i, j stand for the sequence number of a none-zero element*/
	int i, j;
	DataType v;
}triple;

typedef struct{
	triple data[MAXSIZE];
	/*m, n stand for row and column of sparse matrix*/
	/*t stands for the amount of none-zero elements*/
	int m, n, t;         
}tripletable;

tripletable transmatrix(tripletable a)
{
	tripletable b;
	int p, q, col;
	b.m = a.n;
	b.n = a.m;
	b.t = a.t;
	if(b.t){
		q = 0;
		for(col = 1;col <=a.n;col++){
			for(p = 0;p < a.t;p++){
				if(a.data[p].j == col){
					b.data[q].i = col;
					b.data[q].j = a.data[p].i;
					b.data[q].v = a.data[p].v;
					q++;
				}
			}
		}
	}
	return b;
}

tripletable fasttranstri(tripletable a)
{
	tripletable b;
	int p, q, col, k;
	int num[a.n + 1], pot[a.n + 1];
	b.m = a.n;
	b.n = a.m;
	b.t = a.t;
	if(b.t){
		for(col = 1;col <= a.n;col++){
			num[col] = 0;
		}
		for(k = 0;k < a.t;k++){
			num[a.data[k].j]++;
			pot[1] = 0;
		}
		for(col = 2;col <= a.n;col++){
			pot[col] = pot[col-1] + num[col-1];
		}
		for(p = 0;p < a.t;p++){
			col = a.data[p].j;
			q = pot[col];
			b.data[q].i = a.data[p].j;
			b.data[q].j = a.data[p].i;
			b.data[q].v = a.data[p].v;
			pot[col]++;
		}
	}
	return b;
}
