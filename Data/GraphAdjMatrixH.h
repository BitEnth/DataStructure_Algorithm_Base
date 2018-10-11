/*Adjacency matrix*/
#include <stdio.h>
#define MaxVertexNumGAM 30

typedef int VertexType_GAM;
typedef int EdgeType_GAM;

typedef struct{
	VertexType_GAM vertexs_GAM[MaxVertexNumGAM];
	EdgeType_GAM arcs[MaxVertexNumGAM][MaxVertexNumGAM];
	int vertex_num_GAM, edge_num_GAM;
}MGraph;

void CreatGraph(MGraph *G)
{
	int i, j, k;
	scanf("%d, %d",&(G->vertex_num_GAM), &(G->edge_num_GAM));
	for(i = 0;i < G->vertex_num_GAM;i++){
		scanf("%d", &(G->vertexs_GAM[i]));
	}
	for(i = 0;i < G->vertex_num_GAM;i++){
		for(j = 0;j < G->vertex_num_GAM;j++){
			G->arcs[i][j] = 0;
		}
	}
	for(k = 0;k < G->edge_num_GAM;k++){
		scanf("%d, %d", &i, &j);
		G->arcs[i][j] = 1;   /*none oriented graph*/
	}
}
