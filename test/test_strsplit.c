#include <stdio.h>
#include "../include/stdlib.h"

int main()
{
	char *string = strdup("0 1 2 3 4 5 6 7 8 9\0");
	char *spliter = strdup(" \0");
	int i = 0;
	char **result;
	printf("strsplit(\"%s\", \"%s\") =\n", string, spliter);
	result = strsplit(string, spliter);
	while(result[i] != '\0')
	{
		printf("%s\n", result[i]);
		i = i +1;
	}
	return 0;
}
