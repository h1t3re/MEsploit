#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *data = (char *)malloc((5828308+3978784)*sizeof(char));
	memset((void *)data, 0, (5828308+3978784)*sizeof(char));
	return 0;
}
