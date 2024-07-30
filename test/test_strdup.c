#include <stdio.h>
#include "../include/stdlib.h"

int main()
{
	char *string = "duplicate";
	char *dup = strdup(string);
	printf("strdup(\"%s\") at address %p = \"%s\" at address %p\n", string, string, dup, dup);
	return 0;
}
