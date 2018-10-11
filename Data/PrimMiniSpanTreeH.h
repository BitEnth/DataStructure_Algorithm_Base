#include <stdio.h>
#include "GraphAdjMatrixH.h"
#define INFINITY_PMST 3000
#define MaxVertexNum_PMST 30

typedef struct{
	int adjvertex;
	int lowcost;
}CloseEdge;

void MiniSpanTree_PRIM(MGraph G, int u, CloseEdge ce[])
{
	int i, j, w, k;
	for(i = 0;i < G.vertex_num_GAM;i++){
		if(i != u){
			ce[i].adjvertex = u;
			ce[i].lowcost = G.arcs[u][i];
		}
	}
	ce[u].lowcost = 0;
	for(i = 0; i < G.vertex_num_GAM-1;i++){
		w = INFINITY_PMST;
		for(j = 0;j < G.vertex_num_GAM;j++){
			if(ce[j].lowcost !=0 && ce[j].lowcost < w){
				w = ce[j].lowcost;
				k = j;
			}
		}
		ce[k].lowcost = 0;
		for(j = 0;j < G.vertex_num_GAM;j++){
			if(G.arcs[k][j] < ce[j].lowcost){
				ce[j].adjvertex = k;
				ce[j].lowcost = G.arcs[k][j];
			}
		}
	}
	for(i = 0;i < G.vertex_num_GAM;i++){
		if(i != u){
			printf("%d->%d, %d\n", i, ce[i].adjvertex, G.arcs[i][ce[i].adjvertex]);
		}
	}
}
