#include <stdlib.h>
#include <stdio.h>
#include "../../include/hexa_dump.h"

int main()
{
	int *hexa_array = (int *)malloc(4*sizeof(int));
	char *hexa = "123456789abcdef\0";
	int i = 0;
	int j = 3;
	while(i < 16)
	{
		j = 3;
		convert_hexa_to_binary(hexa_array, hexa[i]);
		while(j >= 0)
		{
			printf("%d", hexa_array[j]);
			j = j -1;
		}
		printf("\n");
		i = i +1;	
	}
	return 0;
}
