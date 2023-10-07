#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *mem_remem_array(void *array, char *type, int size)
{
	if(strcmp(type, "char *") == 0)
	{
		if(size == 0)
		{
			array = (char *)array;
			array = (char *)malloc(sizeof(char));
		}else
		{
			char *tmp;
			tmp = (char *)realloc((char *)array, size*sizeof(char));
			if(tmp == NULL)
				free(array);
			array = tmp;
		}
	}else if(strcmp(type, "int *") == 0)
	{
		if(size == 0)
		{
			array = (int *)array;
			array = (int *)malloc(sizeof(int));
		}else
		{
			int *tmp;
			tmp = (int *)realloc((int *)array, size*sizeof(int));
			if(tmp == NULL)
				free(array);
			array = tmp;
		}
	}else if(strcmp(type, "char **") == 0)
	{
		if(size == 0)
		{
			array = (char **)array;
			array = (char **)malloc(sizeof(char *));
		}else
		{
			char **tmp;
			tmp = (char **)realloc((char **)array, size*sizeof(char *));
			if(tmp == NULL)
				free(array);
			array = tmp;
		}
	}else if(strcmp(type, "int **") == 0)
	{
		if(size == 0)
		{
			array = (int **)array;
			array = (int **)malloc(sizeof(int *));
		}else
		{
			int **tmp;
			tmp = (int **)realloc((int **)array, size*sizeof(int *));
			if(tmp == NULL)
				free(array);
			array = tmp;
	}	}
	return array;
}

int hexa_int_converter(char *digit)
{
	for(int i = 0; i < 16; i++)
	{
		printf("%s = %d\n", digit, atoi(digit));
		if(atoi(digit[0]) != 0)
			return i;
		else
		{
			if(strncmp(digit, "a", 1) == 0)
				return 10;
			else if(strncmp(digit, "b", 1) == 0)
				return 11;
			else if(strncmp(digit, "c", 1) == 0)
				return 12;
			else if(strncmp(digit, "d", 1) == 0)
				return 13;
			else if(strncmp(digit, "e", 1) == 0)
				return 14;
			else if(strncmp(digit, "f", 1) == 0)
				return 15;
		}		
	}
	return 0;
}

void convert_hexa_to_binary(int *binary_array, char *hexa_number, int length)
{
	int bit_shifted;
	int and_result;
	binary_array = (int *)mem_remem_array(binary_array, "int *", 0);
	binary_array = (int *)mem_remem_array(binary_array, "int *", 4*strlen(hexa_number));
	
	for(int j = 0; j < length; j++)
	{
		for(int i = 0; i < 4; i++)
		{
			printf("%d\n", (4*j)+i);
			bit_shifted = 1 << i;
			and_result = hexa_int_converter(hexa_number[j]) & 1;
			binary_array[(4*j)+i] = and_result >> 1;
		}
	}
}
