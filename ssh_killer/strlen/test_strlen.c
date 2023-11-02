#include "strlen.h"
#include <stdio.h>

int main()
{
	int length = strlen("\0");
	printf("%d\n", length);
	return 0;
}
