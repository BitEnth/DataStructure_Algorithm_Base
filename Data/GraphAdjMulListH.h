/* Adjacency Multilist*/

#define MaxVertexNumGAML 30

typedef int InfoType_GAML;
typedef int VertexType_GAML;

typedef enum{
	unvisited, visited
}Visitif;

typedef struct EdgeNode{
	Visitif mark;
	int ivertex, jvertex;
	struct EdgeNode *ilink, *jlink;
	InfoType_GAML info;
}EdgeNode_GAML;

typedef struct VertexNode{
	VertexType_GAML vertex_GAML;
	EdgeNode_GAML *firstedge;
}VertNode_GAML;

typedef struct{
	VertNode_GAML adjmullist[MaxVertexNumGAML];
	int vertex_num_GAML, edge_num_GAML;
}AMLGraph;
