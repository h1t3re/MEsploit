#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/mem.h"

char *read_input()
{
	char *buffer;
	int buffer_len = 0;
        buffer = (char *)mem_remem_array(buffer, "char *", buffer_len);
	char c = ' ';
	while(((c = getchar()) != '\0') & (c != '\n'))
	{
		buffer[buffer_len] = c;
		buffer_len = buffer_len + 1;
		buffer = (char *)mem_remem_array(buffer, "char *", buffer_len + 1);
	}
	buffer[buffer_len] = '\0';
	return buffer;
}

char *read_file(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	if(fd == -1)
		return NULL;
	char *buffer;
	int buffer_len = 0;
	buffer = (char *)mem_remem_array(buffer, "char *", buffer_len);
	if(buffer == NULL)
		return NULL;
	while(read(fd, &buffer[buffer_len], sizeof(buffer[buffer_len])) > 0)
	{
		buffer_len = buffer_len + 1;
		buffer = (char *)mem_remem_array(buffer, "char *", buffer_len + 1);
		if(buffer == NULL)
			return NULL;
	}
	buffer[buffer_len] = '\0';
	close(fd);
	return buffer;
}
