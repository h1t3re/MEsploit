#include <stdio.h>
#include "stdlib.h"
#include <string.h>

int main()
{
	char *str0 = "string";
	char *str1 = "str";
	printf("strcmp(\"%s\", \"%s\") = %d\n", str0, str0, strcmp(str0, str0));
	printf("strcmp(\"%s\", \"%s\") = %d\n", str0, str1, strcmp(str0, str1));
	printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str0, strcmp(str1, str0));
	printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str1, strcmp(str1, str1));
	return 0;
}
