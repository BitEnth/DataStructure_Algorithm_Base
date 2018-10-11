#include "BreadthFirstSearchH.h"

int main(void){
	ALGraph G;
	CreatALGraph_undis(&G);
	BFS_GAL(G, 0);
	return 0;
}
