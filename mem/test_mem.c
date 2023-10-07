#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mem.h"


int main()
{
	int *binary_array;
	convert_hexa_to_binary(binary_array, "ff", 2);
	for(int i = 0; i <= strlen("ff"); i++)
	{
		printf("%d ", binary_array[i]);
	}
	printf("\n");
	free(binary_array);
	return 0;
}
