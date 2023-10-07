#include <string.h>
#include "../include/mem.h"

char **split(char *buffer, char *separator)
{
	char **array;
	int array_len = 0;
	int j = 0;
	array = (char **)mem_remem_array(array, "char **", array_len);
	array[array_len] = (char *)mem_remem_array(array[array_len], "char *", j);
	for(int i = 0; i <= strlen(buffer); i++)
	{
		while(buffer[i] != *separator)
		{
			array[array_len][j] = buffer[i];
			j = j + 1;
			array[array_len] = (char *)mem_remem_array(array[array_len], "char *", j+1);
			i = i + 1;
		}
		if(buffer[i] == *separator){
			array[array_len][j] = '\0';
			array_len = array_len + 1;
			array = (char **)mem_remem_array(array, "char **", array_len+1);
			if(array == NULL)
				return NULL;
			j = 0;
			array[array_len] = (char *)mem_remem_array(array[array_len], "char *", j);
			if(array[array_len] == NULL)
				return NULL;
		}
	}
	array_len = array_len + 1;
	array = (char *)mem_remem_array(array, "char **", array_len+1);
	array[array_len] = '\0';
	return array;
}
