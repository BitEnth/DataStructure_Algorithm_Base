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

void Print_GraphAM(MGraph *G)
{
	int i, j;
	for(i = 0;i < G->vertex_num_GAM;i++){
		for(j = 0;j < G->vertex_num_GAM;j++){
				printf(" %d ", G->arcs[i][j]);
		}
		printf("\n");
	}
}

void CreatAMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("Please input the amount of vertexs and edges: "); 
	scanf("%d, %d",&(G->vertex_num_GAM), &(G->edge_num_GAM));
	for(i = 0;i < G->vertex_num_GAM;i++){
		printf("\nPlease input the sequence number of the %d vertex: ", i);
		scanf("%d", &(G->vertexs_GAM[i]));
	}
	for(i = 0;i < G->vertex_num_GAM;i++){
		for(j = 0;j < G->vertex_num_GAM;j++){
			G->arcs[i][j] = 0;
		}
	}
	for(k = 0;k < G->edge_num_GAM;k++){
		printf("\nPlease input two numbers of vertexs: ");
		scanf("%d, %d", &i, &j);
		printf("\nPlease input the weight: ");
		scanf("%d", &w);
		G->arcs[i][j] = w;
		/*The next handle will be added if creating undisgraph*/
		//G->arcs[j][i] = w;
	}
	Print_GraphAM(G);
}


