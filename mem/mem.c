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

int hexa_to_int_converter(char *digit)
{
	for(int i = 0; i < 16; i++)
	{
		if(strncmp(digit, "0", 1) == 0)
			return 0;
		else if(strncmp(digit, "1", 1) == 0)
			return 1;
		else if(strncmp(digit, "2", 1) == 0)
			return 2;
		else if(strncmp(digit, "3", 1) == 0)
			return 3;
		else if(strncmp(digit, "4", 1) == 0)
			return 4;
		else if(strncmp(digit, "5", 1) == 0)
			return 5;
		else if(strncmp(digit, "6", 1) == 0)
			return 6;
		else if(strncmp(digit, "7", 1) == 0)
			return 7;
		else if(strncmp(digit, "8", 1) == 0)
			return 8;
		else if(strncmp(digit, "9", 1) == 0)
			return 9;
		else if(strncmp(digit, "a", 1) == 0)
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
	return 0;
}

void convert_hexa_to_binary(int *binary_array, char *hexa_number, int length)
{
	int bit_shifted;
	int and_result;
	
	for(int i = 0; i < 4; i++)
	{
		bit_shifted = 1 << i;
		and_result = hexa_to_int_converter(hexa_number) & bit_shifted;
		binary_array[i] = and_result >> i;
	}
}
