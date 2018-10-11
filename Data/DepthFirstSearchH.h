#include "GraphAdjListH.h"
#define False 0
#define True 1

int visited[MaxVertexNumGAL];

void DFS(ALGraph G, int v)
{
	EdgeNode_GAL *p;
	int w;
	printf("%d", G.adjlist[v].vertex_GAL);
	visited[v] = True;
	for(p = G.adjlist[v].firstedge;p;p = p->next){
		w = p->adjvertex;
		if(!visited[w]){
			DFS(G, w);
		}
	}
}

void DFStraverse(ALGraph G)
{
	int v;
	for(v = 0;v < G.vertex_num_GAL;v++){
		visited[v] = False;
	}
	for(v = 0;v < G.vertex_num_GAL;v++){
		if(!visited[v]){
			DFS(G, v);
		}
	}
}
