#include <stdlib.h>
#include <unistd.h>
#include "../../include/strncmp.h"

char *read_input()
{
	char *buffer = (char *)malloc(2*sizeof(char));
	char *buffer_buffer_len_content = (char *)malloc(2*sizeof(char));
	char *end_of_line = (char *)malloc(2*sizeof(char));
	int buffer_len = 0;
	*buffer = ' ';
	*(buffer+1) = '\0';
	*end_of_line = '\n';
	*(end_of_line+1) = '\0';
	snprintf(buffer_buffer_len_content, 2*sizeof(char), "%c\0", *(buffer+buffer_len));
	while(strncmp(buffer_buffer_len_content, end_of_line) != 0)
	{
		read(1, &(*(buffer+buffer_len)), sizeof(char));
		snprintf(buffer_buffer_len_content, 2*sizeof(char), "%c\0", *(buffer+buffer_len));
		buffer_len = buffer_len + 1;
		buffer = (char *)realloc(buffer, (buffer_len+2)*sizeof(char));
		*(buffer+buffer_len) = '\0';
	}
	free(buffer_buffer_len_content);
	free(end_of_line);
	return buffer;
}

char *read_file(char *file_name)
{
	int fd = open(file_name, 'r');
	if(fd == -1)
		return NULL;
	char *buffer;
	int buffer_len = 0;
	buffer = (char *)malloc(sizeof(char));
	if(buffer == NULL)
		return NULL;
	while(read(fd, &(*(buffer+buffer_len)), sizeof(char)) > 0)
	{
		buffer_len = buffer_len + 1;
		buffer = (char *)realloc(buffer, (buffer_len+1)*sizeof(char));
		if(buffer == NULL)
			return NULL;
	}
	*(buffer+buffer_len) = '\0';
	close(fd);
	return buffer;
}
