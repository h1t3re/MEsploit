#include "../include/stdlib.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{	
	int i = 0;
	char *file_name = strdup("./data.txt\0");
	char *mode = strdup("r\0");
	char *buffer = read_file(file_name, mode);
	char *key = strdup("2.\0");
	char *end = strdup("3.\0");
	char *data = get_data_by_key_until_end(buffer, key, end);
	printf("buffer is :\n");
	printf("%s\n", buffer);
	printf("the key is \"%s\"\n", key);
	printf("the end is \"%s\"\n", end);
	printf("data is : \n");
	printf("%s\n", data);
	return 0;
}
