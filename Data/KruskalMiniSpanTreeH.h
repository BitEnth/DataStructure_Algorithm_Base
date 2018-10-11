#include <stdlib.h>
#define MaxVertexNum_GEL 30
#define MaxEdge_KMST 100

typedef int WeightType_GEL;
typedef int VertexType_GEL;

typedef struct ENode{
	int vertex1, vertex2;
	WeightType_GEL weight;
}Enode_GEL;

/*Edge List Graph*/
typedef struct{
	int vertex_num_GEL, edge_num_GEL;
	VertexType_GEL vertexs_GEL[MaxVertexNum_GEL];
	Enode_GEL edges_GEL[MaxVertexNum_GEL];
}ELGraph;

int cmp_KMST(const void *a, const void *b)
{
	return (*(Enode_GEL *)a).weight > (*(Enode_GEL *)b).weight ? 1 : -1;
}

void MiniSpanTree_Kruskal(ELGraph G, Enode_GEL eg[])
{
	int i, j, k;
	int f[MaxVertexNum_GEL];
	for(i = 0;i < G.vertex_num_GEL;i++){
		f[i] = i;
	}
	/*sort for the weight from smaller to bigger*/
	qsort(G.edges_GEL, MaxVertexNum_GEL, sizeof(Enode_GEL),cmp_KMST);
	j = 0;
	k = 0;
	while(k < G.vertex_num_GEL-1){
		s1 = f[G.edges_GEL[j].vertex1];
		s2 = f[G.edges_GEL[j].vertex2];
		if(s1 != s2){
			eg[k].vertex1 = G.edges_GEL[j].vertex1;
			eg[k].vertex2 = G.edges_GEL[j].vertex2;
			eg[k].weight = G.edges_GEL[j].weight;
			k++;
			for(i = 0;i < G.vertex_num_GEL;i++){
				if(f[i] == s2){
					f[i] = s1;
				}
			}
		}
		j++;
	}
	
}
