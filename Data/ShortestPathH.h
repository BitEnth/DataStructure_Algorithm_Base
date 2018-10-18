/* Dijkstra algorithm
 * Floyd algorithm*/
#include "GraphAdjMatrixH.h"
#define INFINITY_SP 30000
#define MaxVertexNum_SP 30
#define True 1
#define False 0

/* Due to the GraphAdjMatrixH.h, the initial value of G->arcs[i][j] is 
 * equal to zero. It needs to be changed in Dijkstra algorithm.
 * call by reference*/
int Init_GAM(MGraph *G)
{
	int i, j;
	for(i = 0;i < G->vertex_num_GAM;i++){
		for(j = 0;j < G->vertex_num_GAM;j++){
			if(i != j && G->arcs[i][j] == 0){
				G->arcs[i][j] = INFINITY_SP;
			}
		}
	}
	printf("\n");
	Print_GraphAM(G);
	return 1;
}

/* P[v] stands for the previous vertex of v
 * D[v] stands for the edge with smallest weight from v0 to v
 * final[v] is the signal that the shortest path has been found if True
 * -1 stands for the fact that there is no previous vertex of v
 * 
 * The mechanism of dijkstra algorithm:
 * Step 1, we need to find out the shortest path between v0 and other 
 * vertexs which is directly linked to v0. Meanwhile, we record the 
 * distance(D[]) and previous vertex(P[]). Then the final[] value whose 
 * weight is lowest become true.
 * Step 2, we use the aforesaid vertex(v1) to find which vertex is directly
 * linked to it. if we find one(v2), we will compare the distance D(v0->v2)
 * with D(v0->v1)+D(v1->v2). If latter is lower, we need to change D[v2]
 * and P[v2]
 * Step 3, we will search the smallest value in array D[], whose final[]
 * is not true at the same time. Then we repeat step 2, update D[] and 
 * P[] till all vertexs are be traversed.*/
void ShortestPath_DiJ(MGraph G, int v0, int P[], int D[])
{
	int i, w, v;
	int min;
	int final[MaxVertexNum_SP];
	Init_GAM(&G);
	for(v = 0;v <= G.vertex_num_GAM-1;v++){
		final[v] = False;
		D[v] = G.arcs[v0][v];
		P[v] = -1;
		if(D[v] < INFINITY_SP){
			P[v] = v0;
		}
	}
	D[v0] = 0;
	final[v0] = True;
	for(i = 1;i <= G.vertex_num_GAM;i++){
		v = -1;
		min = INFINITY_SP;
		for(w = 0;w <= G.vertex_num_GAM-1;w++){
			if((!final[w]) && (D[w] < min)){
				v = w;
				min = D[w];
			}
		}
		if(v == -1){
			break;
		}
		final[v] = True;
		for(w = 0;w <= G.vertex_num_GAM-1;w++){
			if((!final[w]) && (min + G.arcs[v][w] < D[w])){
				D[w] = min + G.arcs[v][w];
				P[w] = v;
			}
		}
	}
}

void Print_Path_Dij(MGraph G, int v0, int P[], int D[])
{
	int v, i;
	printf("The shortest path from Vertex %d to the other Vertex:\n", v0);
	for(v = 0;v <= G.vertex_num_GAM-1;v++){
		printf("%d %d", D[v], P[v]);
		printf("\n");
	}
	for(v = 0;v < G.vertex_num_GAM;v++){
		if(P[v] == -1){
			printf("There is no edge between %d and %d\n", v0, G.vertexs_GAM[v]);
		}
		else if(P[v] == 0){
			printf("%d->%d the shortest path %d\n", v0, G.vertexs_GAM[v], D[v]);
		}
		else{
			i = v;
			while(P[i] != 0){
				printf("%d<-", G.vertexs_GAM[i]);
				i = P[i];
			}
			printf("%d<-%d", G.vertexs_GAM[i], v0);
			printf(" the shortest path: %d\n", D[v]);
		}
	}
}


/* P[v][w] stands for the bridge vertex of v to w in the shortest path
 * D[v][w] stands for the value of shortest path between v and w
 * P[v][w] is initiated by v, and u is regarded as the bridge vertex
 * if v->u->w is shorter than v->w, P[v][w] will be assigned to u and update
 * the value of D[v][w]. replacing the previous value v. 
 * Then every vertex will be scanned as bridge vertex till finding out all the
 * shortest path of two vertexs*/
void ShortestPath_Floyd(MGraph G, int P[][MaxVertexNum_SP], int D[][MaxVertexNum_SP])
{
	int v, w, u;
	Init_GAM(&G);
	for(v = 0;v < G.vertex_num_GAM;v++){
		for(w = 0;w < G.vertex_num_GAM;w++){
			D[v][w] = G.arcs[v][w];
			P[v][w] = v;
		}
	}
	/*u must be before v and w*/
	for(u = 0;u < G.vertex_num_GAM;u++){
		for(v = 0;v < G.vertex_num_GAM;v++){
			for(w = 0;w < G.vertex_num_GAM;w++){
				if(D[v][u] + D[u][w] < D[v][w]){
					D[v][w] = D[v][u] + D[u][w];
					P[v][w] = u;
				}
				printf(" D:%d P:%d",D[v][w], P[v][w]);
			}
			printf("\n");
		}
		printf("\n");
	}
	for(v = 0;v < G.vertex_num_GAM;v++){
		for(w = 0;w < G.vertex_num_GAM;w++){
			printf("%d\t", D[v][w]);
		}
		printf("\n");
	}
	printf("\n");
	for(v = 0;v < G.vertex_num_GAM;v++){
		for(w = 0;w < G.vertex_num_GAM;w++){
			printf("%d\t", P[v][w]);
		}
		printf("\n");
	}
	printf("\n");
}

/* v, w stand for two vertexs, respectively. num stands for the amount 
 * of vertexs 
 * if there exists the direct link between two vertexs, then flag is true
 * and print v0->v2; if not, then flag is false and print v0->v1->v2
 * the variable in 'printf' function can be changed to G.vertexs_GAM, 
 * and then change the inputinng parameter of Print_Path_Floyd or change
 * the value of P[][] in ShortestPath_Floyd*/
void Print_Path_Floyd(int v, int w, int flag, int P[][MaxVertexNum_SP])
{
	if(P[v][w] == v){
		if(flag){
			printf(" %d->%d ", v, w);
		}
		else{
			printf("->%d", w);
		}
		
	}
	else{
		int i = P[v][w];
		if(flag){
			printf(" %d", v);
		}
		Print_Path_Floyd(v, i, False, P);
		Print_Path_Floyd(i, w, False, P);
	}
}
