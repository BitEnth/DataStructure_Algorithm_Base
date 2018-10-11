#include <stdio.h>
//#include <stdlib.h>

int main(void)
{
	char data[5] = {'K', 't', '0', '*', '~'};
	char data1 = 'w';
	char *p1 = data;
	char *p2 = &data1;
	printf("%d\n", &data1);
	printf("%d\n", p2);
	p2 = NULL;
	//free(p2);
	printf("%d\n", &p2);
	printf("%d\n",p2);
	printf("%s\n", p1);
	printf("%c\n",*p1);
	printf("%d\n",*(p1+1));
	printf("%d\n",'t');
	printf("%s", data);
	return 0;
}
