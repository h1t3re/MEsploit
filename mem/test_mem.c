#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mem.h"


int main()
{
	int *binary_array;
	binary_array = (int *)mem_remem_array(binary_array, "int *", 0);
	binary_array = (int *)mem_remem_array(binary_array, "int *", 4);
	char *hexa_number = "f\0";
	convert_hexa_to_binary(binary_array, hexa_number, 1);
	for(int i = 0; i < strlen("f")*4; i++)
	{
		printf("%d ", binary_array[i]);
	}
	printf("\n");
	free(binary_array);
	return 0;
}
