#include <stdlib.h>
#include <stdio.h>
#include "../../include/strncmp.h"
#include "../../include/strlen.h"

int main()
{
	char *tmp = "equal\0";
	char *array = (char *)malloc(strlen(tmp)*sizeof(char));
	int result = 0;
	int i = 0;
	while(i < strlen(tmp))
	{
		array[i] = tmp[i];
		i = i +1;
	}
	result = strncmp(array, array);
	printf("%d\n", result);
	result = strncmp(array, "equal\0");
	printf("%d\n", result);
	result = strncmp(array, "aqual\0");
	printf("%d\n", result);
	free(array);
	return 0;
}
