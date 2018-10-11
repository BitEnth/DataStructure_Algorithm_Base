/* The Test Example(Undisgraph):
 *         v0        
 *          |
 *      /       \
 *     v1       v2
 *    /  \     /  \
 *   v3   v4  v5--v6
 *    \  /
 *     v7   
 * the result of depth-first search is v0->v1->v3->v7->v4->v2->v5->v6
 * the result of breadth-first search is v0->v1->v2->v3->v4->v5->v6->v7*/
#include "DepthFirstSearchH.h"

int main(void)
{
	ALGraph alg;
	CreatALGraph_undis(&alg);
	DFStraverse(alg);
	return 0;
}
