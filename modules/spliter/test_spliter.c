#include <stdlib.h>
#include "../../include/input_output.h"
#include "../../include/spliter.h"
#include <stdio.h>

int main()
{
	char *buffer = read_input();
	printf("%s\n", buffer);
	int i = 0;
	char **array = split(buffer, " ");
	while(array[i] != '\0')
	{
		printf("%s\n", array[i]);
		i = i +1;
	}	
	return 0;
}
