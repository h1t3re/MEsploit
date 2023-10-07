#include <stdio.h>
#include <stdlib.h>
#include "include/input_output.h"
#include "include/spliter.h"

int main()
{
	char *buffer;
	char **array;
	int i = 0;
	while(1)
	{
		buffer = read_input();
		printf("%s\n", buffer);
		array = split(buffer, " ");
		while(array[i+1] != '\0')
		{
			printf("%s\n", array[i]);
			i = i + 1;
		}
		i = 0;
		free(buffer);
		free(array);
	}
	return 0;
}
