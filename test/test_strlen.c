#include <stdio.h>
#include "../include/stdlib.h"

int main()
{
	char *string = "123456789";
	int length = strlen(string);
	printf("strlen(\"%s\") = %d\n", string, length);
	return 0;
}
