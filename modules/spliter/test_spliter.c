#include <stdlib.h>
#include "../../include/input_output.h"
#include "../../include/spliter.h"
#include "../../include/strncmp.h"
#include <stdio.h>

int main()
{
	char *buffer = read_input();
	printf("%s\n", buffer);
	int i = 0;
	char **array = split(buffer, " ");
	while(strncmp(array[i], "\0") != 0)
	{
		printf("%s", array[i]);
		printf("\n\n");
		i = i +1;
	}	
	return 0;
}
