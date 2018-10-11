#include "SeqQueueH.h"
#include "GraphAdjListH.h"
#include "GraphAdjMatrixH.h"
#define True 1
#define False 0

int visited[MaxVertexNumGAL];

void BFS_GAL(ALGraph G, int v)
{
	EdgeNode_GAL *p;
	int u, w;
	PSeqQueue Q;
	Q = Init_SeqQueue();
	printf("%d", G.adjlist[v].vertex_GAL);
	visited[v] = True;
	In_SeqQueue(Q, v);
	printf("\nfront: %d, rear: %d\n", Q->front, Q->rear);
	while(!Empty_SeqQueue(Q)){
		Out_SeqQueue(Q, &u);
		printf("\nfront: %d, rear: %d, u: %d\n", Q->front, Q->rear, u);
		for(p = G.adjlist[u].firstedge;p;p = p->next){
			w = p->adjvertex;
			printf("w: %d\t", w);
			if(!visited[w]){
				printf("%d", G.adjlist[w].vertex_GAL);
				visited[w] = True;
				In_SeqQueue(Q, w);
				printf("\nfront: %d, rear: %d\n",Q->front, Q->rear);
			}
		}
	}
}

void BFS_GAM(MGraph G, int v)
{
	int i, j;
	i = 0;
	PSeqQueue Q;
	Q = Init_SeqQueue();
	printf("%d", G.vertexs_GAM[v]);
	visited[v] = True;
	In_SeqQueue(Q, v);
	while(!Empty_SeqQueue(Q)){
		Out_SeqQueue(Q, &i);
		for(j = 0;j < G.vertex_num_GAM;j++){
			if(G.arcs[i][j] == 1 && !visited[j]){
				printf("%d", G.vertexs_GAM[j]);
				visited[j] = True;
				In_SeqQueue(Q, j);
			}
		}
	}
}

void BFStraverse_GAM(MGraph G)
{
	int v;
	for(v = 0;v < G.vertex_num_GAM;v++){
		visited[v] = False;
	}
	for(v = 0;v < G.vertex_num_GAM;v++){
		if(!visited[v]){
			BFS_GAM(G, v);
		}
	}
}
