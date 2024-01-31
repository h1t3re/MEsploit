#include <stdlib.h>
#include <stdio.h>

int main()
{
	char c = 'c';
	char t = ' ';
	int n = 0;
	n = c - '0' + 48;
	t = n - 48 + '0';
	printf("%d\n", c - '0' + 48);
	printf("%c\n", t);	
	return 0;
}
