#include "StrH1.h"
#include "StrMatch1.h"

int main(void)
{
    char s[] = {23,'B','B','C',' ','A','B','C','D','A','B',' ','A','B',
	             'C','D','A','B','C','D','A','B','D','E'};
	char t[] = {7,'A','B','C','D','A','B','D'};
	int len = StrLength(t);
	int next[len];
	int imatch;
	GetNext(t,next);
	imatch = StrIndex_KMP(s,t,1,next);
	printf("%s\n",s);
	printf("%s\n",t);
	printf("%d\n",imatch);
	return 0;
}
