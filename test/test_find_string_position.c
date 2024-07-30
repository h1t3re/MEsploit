#include <stdio.h>
#include "../include/stdlib.h"

int main()
{
	char *string = strdup("0123456789\0");
	printf("find_string_position(\"%s\", \"%s\") = %d\n", string, strdup("8\0"), find_string_position(string, strdup("8\0"), 1));
	return 0;
}
