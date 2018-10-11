/* Orthogonal list*/
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNumGOL 30

typedef int InfoType_GOL;
typedef int VertexType_GOL;

/* tailvertex stands for the node which points out
 * headvertex stands for the node which points in
 * hlink points to the list which has the same node pointing in
 * tlink points to the list which has the same node pointing out*/
typedef struct ArcNode{
	int tailvertex, headvertex;
	struct ArcNode *hlink, *tlink;
	InfoType_GOL info;
}ArcNode;

typedef struct VertexNode{
	VertexType_GOL vertex_GOL;
	ArcNode *firstin, *firstout;
}VertNode_GOL;

typedef struct{
	VertNode_GOL xlist[MaxVertexNumGOL];
	int vertex_num_GOL, edge_num_GOL;
}OLGraph;

void CreatOLGraph(OLGraph *G)
{
	int i, j, k;
	scanf("%d, %d", &(G->vertex_num_GOL), &(G->edge_num_GOL));
	for(i = 0;i < G->vertex_num_GOL;i++){
		scanf("%d", &(G->xlist[i].vertex_GOL));
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	i = 0;
	j = 0;
	/*to need adjustment*/
	for(k = 0;k < G->edge_num_GOL;k++){
		scanf("%d, %d", &i, &j);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->tailvertex = i;
		p->headvertex = j;
		p->tlink = G->xlist[i].firstout;
		p->hlink = G->xlist[j].firstin;
		G->xlist[i].firstout = p;
		G->xlist[j].firstin = p;
	}
}
