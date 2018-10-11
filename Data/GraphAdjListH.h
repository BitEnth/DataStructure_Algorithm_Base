/*Adjacency list*/
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNumGAL 30

typedef int VertexType_GAL;
//typedef int EdgeType_GAL;
typedef int InfoType_GAL;

typedef struct node{
	int adjvertex;
	InfoType_GAL info;
	struct node *next;
}EdgeNode_GAL;

typedef struct vnode{
	VertexType_GAL vertex_GAL;
	EdgeNode_GAL *firstedge;
}VertNode_GAL;

typedef struct{
	VertNode_GAL adjlist[MaxVertexNumGAL];
	int vertex_num_GAL, edge_num_GAL;
}ALGraph;

/*oriented graph or digraphs*/
void CreatALGraph_dis(ALGraph *G)
{
	int i, j, k;
	EdgeNode_GAL *p;
	printf("the amount of vertex and of edge are: ");
	scanf("%d, %d", &(G->vertex_num_GAL), &(G->edge_num_GAL));
	for(i = 0;i < G->vertex_num_GAL;i++){
		printf("the sequence number or subscript of vertex: ");
		scanf("%d", &(G->adjlist[i].vertex_GAL));
		G->adjlist[i].firstedge = NULL;
	}
	/*to need adjustment*/
	for(k = 0;k < G->edge_num_GAL;k++){
		printf("the sequence number of vi and vj: ");
		scanf("%d, %d", &i, &j);
		p = (EdgeNode_GAL*)malloc(sizeof(EdgeNode_GAL));
		p->adjvertex = j;
		p->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = p;
	}
}

/*undisgraphs*/
void CreatALGraph_undis(ALGraph *G)
{
	int i, j, k, numtemp;
	EdgeNode_GAL *p;
	printf("the amount of vertex and of edge are: ");
	scanf("%d, %d", &(G->vertex_num_GAL), &(G->edge_num_GAL));
	for(i = 0;i < G->vertex_num_GAL;i++){
		printf("the sequence number or subscript of vertex: ");
		scanf("%d", &(G->adjlist[i].vertex_GAL));
		G->adjlist[i].firstedge = NULL;
	}
	for(i = 0; i < G->vertex_num_GAL;i++){
		printf("the edge amount of number %d vertex: ", i);
		scanf("%d", &numtemp);
		p = (EdgeNode_GAL*)malloc(numtemp*sizeof(EdgeNode_GAL));
		for(k = 0; k < numtemp;k++){
			printf("the adjacency vertex number is: ");
			scanf("%d", &j);
			p[k].adjvertex = j;
			p[k].next = NULL;
			p[k].info = 0;
			printf("%d\n", p[k].adjvertex);
		}
		if(p){
			G->adjlist[i].firstedge = &p[0];
			printf("%d\n", p[0].adjvertex);
		}
		for(k = 0;k < numtemp-1;k++){
			p[k].next = &p[k+1];
			printf("%d\n", p[k].adjvertex);
		}
		p[numtemp-1].next = NULL;
		printf("%d\n", p[numtemp-1].adjvertex);
	}
}
