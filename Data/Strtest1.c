#include "StrH1.h"

int main(void)
{
	char *s;
	SeqString str;
	str.data[0] = 'u';
	str.data[1] = 'K';
	str.data[2] = 'o';
	s = str.data;
	str.Length = StrLength(s);
	printf("%d\n", str.Length);
	return 0;
}
