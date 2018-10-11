#include <stdio.h>
#include <stdlib.h>
/*N stands for the amount of leaf nodes*/
#define N 20

typedef int HTDT;

typedef struct{
	char ch;
	HTDT weight;
	int lchild, rchild, parent;
}HTnode;

typedef struct{
	char *code;
	char leaf;
	int length;
}CodeType;

void Hufcoding(HTnode huftree[], CodeType cd[], HTDT w[], int n)
{
	int i, j, k, s1, s2, s, m, f, c, sum;
	char temp[N];
	/*m is the symbol of the amount of nodes*/
	m = 2*n-1;
	for(i = 1;i <= n;i++){
		huftree[i].weight = w[i-1];
		huftree[i].lchild = -1;
		huftree[i].rchild = -1;
		huftree[i].parent = -1;
		printf("please input the character: ");
		huftree[i].ch = getchar();
	}
	for(i = n+1;i <= m; i++){
		huftree[i].weight = -1;
		huftree[i].lchild = -1;
		huftree[i].rchild = -1;
		huftree[i].parent = -1;
	}
	for(i = 1;i <= n-1;i++){
		/*sort for huftree[1..n+i-1], s1 and s2 are the subscripts of
		 * the least-weight node without parents */
		//Select(huftree, n+i-1, &s1, &s2);
		sum = huftree[s1].weight + huftree[s2].weight;
		huftree[n+i].weight = sum;
		huftree[s1].parent = n+i;
		huftree[s2].parent = n+i;
		huftree[n+i].lchild = s1;
		huftree[n+i].rchild = s2;
	}
	for(i = 1;i <= n;i++){
		c = 0;
		for(k = i, f = huftree[i].parent;f != -1;
			k = f, f = huftree[f].parent){
				if(huftree[f].lchild == k){
					temp[c] = '0';
					c++;
				}
				else{
					temp[c] = '1';
					c++;
				}
			}
		cd[i].code = malloc(c+1);
		cd[i].code[c] = '\0';
		c--;
		k = 0;
		while(c >= 0){
			cd[i].code[k++] = temp[c--];
		}
		cd[i].leaf = huftree[i].ch;
		cd[i].length = k;
	}
}
