#include <stdio.h>
#define MaxVertexNum_AOVN 30

typedef struct edgenode{
	int adjvertex;
	struct edgenode *next;
}EdgeNode_AOVN;

typedef struct vnode{
	int indegree;
	int vertex;
	EdgeNode_AOVN *firstedge;
}VertexNode_AOVN;

typedef struct{
	VertexNode_AOVN adjlist[MaxVertexNum_AOVN];
	int vertex_num_AOVN, edge_num_AOVN;
}ALGraph_AOVN;

void GetIndegree_AOVN(ALGraph_AOVN *G)
{
	int i;
	EdgeNode_AOVN *p;
	for(i = 0;i < G->vertex_num_AOVN;i++){
		G->adjlist[i].indegree = 0;
	}
	for(i = 0;i < G->vertex_num_AOVN;i++){
		for(p = G->adjlist[i].firstedge;p;p = p->next){
			G->adjlist[p->adjvertex].indegree++;
		}
	}
}

void TopSort_AOVN(ALGraph_AOVN G)
{
	int i, j, k;
	int count = 0;
	int top = -1;
	EdgeNode_AOVN *p;
	GetIndegree_AOVN(&G);
	for(i = 0;i < G.vertex_num_AOVN;i++){
		if(G.adjlist[i].indegree == 0){
			G.adjlist[i].indegree = top;
			top = i;
		}
	}
	while(top != -1){
		j = top;
		top = G.adjlist[top].indegree;
		printf("%d", G.adjlist[j].vertex);
		count++;
		for(p = G.adjlist[j].firstedge;p;p = p->next){
			k = p->adjvertex;
			G.adjlist[k].indegree--;
			if(G.adjlist[k].indegree == 0){
				G.adjlist[k].indegree = top;
				top = k;
			}
		}
	}
	if(count < G.vertex_num_AOVN){
		printf("The network has a cycle");
	}
}
