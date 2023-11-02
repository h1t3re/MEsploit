#include <stdlib.h>
#include <stdio.h>
#include "../../include/input_output.h"

int main()
{
	char *buffer = read_input();
	printf("%s\n", buffer);
	free(buffer);
	char *file_c = read_file("test.txt");
	printf("%s\n", file_c);
	free(file_c);
	return 0;
}
