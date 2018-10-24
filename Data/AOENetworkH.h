#include <stdio.h>
#define MaxVertexNum_AOEN 30

typedef struct enode{
	int adjvertex;
	int info;
	struct enode *next;
}EdgeNode_AOEN;

typedef struct vnode{
	int indegree;
	int vertex;
	EdgeNode_AOEN *firstedge;
}VertexNode_AOEN;

typedef struct{
	VertexNode_AOEN adjlist[MaxVertexNum_AOEN];
	int vertex_num_AOEN, edge_num_AOEN;
}ALGraph_AOEN;

void GetIndegree_AOEN(ALGraph_AOEN *G)
{
	int i;
	EdgeNode_AOEN *p;
	for(i = 0;i < G->vertex_num_AOEN;i++){
		G->adjlist[i].indegree = 0;
	}
	for(i = 0;i < G->vertex_num_AOEN;i++){
		for(p = G->adjlist[i].firstedge;p;p = p->next){
			G->adjlist[p->adjvertex].indegree++;
		}
	}
}

/* ve[] stands for the earliest time when each vertex's activity happens
 * tpord[] is a kind of topological sequence
 * if G is not a cycle, return 1. Or return 0*/
int TopOrder_AOEN(ALGraph_AOEN G, int tpord[], int ve[])
{
	int i, j, k;
	int count = 0;
	int top = -1;
	EdgeNode_AOEN *p;
	GetIndegree_AOEN(&G);
	for(i = 0;i < G.vertex_num_AOEN;i++){
		if(G.adjlist[i].indegree == 0){
			G.adjlist[i].indegree = top;
			top = i;
		}
	}
	while(top != -1){
		j = top;
		top = G.adjlist[top].indegree;
		tpord[count++] = G.adjlist[j].vertex;
		for(p = G.adjlist[j].firstedge;p;p = p->next){
			k = p->adjvertex;
			G.adjlist[k].indegree--;
			if(G.adjlist[k].indegree == 0){
				G.adjlist[k].indegree = top;
				top = k;
			}
			if(ve[j]+p->info > ve[k]){
				ve[k] = ve[j]+p->info;
			}
		}
	}
	if(count < G.vertex_num_AOEN){
		return 0;
	}
	else{
		return 1;
	}
}

int CriticalPath(ALGraph_AOEN G)
{
	int i, j, k, e, l;
	int ve[MaxVertexNum_AOEN];
	int vl[MaxVertexNum_AOEN];
	int order[MaxVertexNum_AOEN];
	EdgeNode_AOEN *p;
	int count = G.vertex_num_AOEN;
	if(TopOrder_AOEN(G, order, ve) == 0){
		return 0;
	}
	for(i = 0;i < G.vertex_num_AOEN;i++){
		vl[i] = ve[G.vertex_num_AOEN-1];
	}
	for(i = count;i > 0;i--){
		j = order[i-1];
		for(p = G.adjlist[j].firstedge;p;p = p->next){
			k = p->adjvertex;
			if(vl[k]-p->info < vl[j]){
				vl[j] = vl[k]-p->info;
			}
		}
	}
	for(j = 0;j < G.vertex_num_AOEN;j++){
		for(p = G.adjlist[j].firstedge;p;p = p->next){
			k = p->adjvertex;
			e = ve[j];
			l = vl[k]-p->info;
			if(e == 1){
				printf("%d->%d", j, k);
			}
		}
	}
	return 1;
}
