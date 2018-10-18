/* The exmple(disgraph) used: 
 * '.' stands for the arrow
 *          0
 *       .   .
 *      / /   \ \
 *       .       .
 *      2 .----- 1
 * 
 * |0 4 11|
 * |6 0  2|
 * |3 0  0|
 * 
 * The result of D[][] and P[][]:
 * |0 4 6|
 * |5 0 2|
 * |3 7 0|
 * 
 * |0 0 1|
 * |2 1 1|
 * |2 0 2|
 * 
 * 0->0 0->1 0->1->2
 * 1->2->0 1->1 1->2
 * 2->0 2->0->1 2->2*/
#include "ShortestPathH.h"
#include <stdlib.h>

int main(void){
	int i, j;
	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	CreatAMGraph(G);
	/* the column of P and D must be the value of MaxVertexNum_SP,
	 * or others row of P and D will not be assigned except the first one*/
	int P[G->vertex_num_GAM][MaxVertexNum_SP];
	int D[G->vertex_num_GAM][MaxVertexNum_SP];
	for(i = 0;i < G->vertex_num_GAM;i++){
		for(j = 0;j < G->vertex_num_GAM;j++){
			D[i][j] = 0;
			P[i][j] = i;
		}
	}
	ShortestPath_Floyd(*G, P, D);
	for(i = 0;i < G->vertex_num_GAM;i++){
		for(j = 0;j < G->vertex_num_GAM;j++){
			printf("%d\t", D[i][j]);
		}
		printf("\n");
	}
	for(i = 0;i < G->vertex_num_GAM;i++){
		for(j = 0;j < G->vertex_num_GAM;j++){
			printf("%d\t", P[i][j]);
		}
		printf("\n");
	}
	for(i = 0;i < G->vertex_num_GAM;i++){
		for(j = 0;j < G->vertex_num_GAM;j++){
			Print_Path_Floyd(i, j, True, P);
		}
		printf("\n");
	}
	free(G);
}
