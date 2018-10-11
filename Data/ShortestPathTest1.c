/* The example used:
 * '.' stands for the arrow
 *    v1     v0
 *      \ /  |  \
 *       ..  .   .
 *       v2  v4--.v5
 *        \   |   .
 *         \  |  /
 *          . .
 *            v3 
 *
 * | 0 0 10  0 30 100 |
 * | 0 0  5  0  0   0 |
 * | 0 0  0 50  0   0 | 
 * | 0 0  0  0  0  10 |
 * | 0 0  0 20  0  60 |
 * | 0 0  0  0  0   0 |
 * 
 *                0  1     2  3  4  5
 * The result is  0  30000 10 50 30 60*/

#include "ShortestPathH.h"
#include <stdlib.h>

int main(void){
	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	CreatGraph(G);
	int P[G->vertex_num_GAM];
	int D[G->vertex_num_GAM];
	ShortestPath_DiJ(*G, 0, P, D);
	Print_Path_Dij(*G, 0, P, D);
	free(G);
	return 0;
}
