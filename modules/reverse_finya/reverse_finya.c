#include "../include/stdlib.h"
#include <stdio.h>


typedef struct Arrays{
	int *array;
	int length;
}Array;

int *negative_of_array(int *array, int architecture)
{
	int i = 0;
	int *array1 = (int *)malloc(architecture*sizeof(int));
	while(i < architecture-1)
	{
		array1[i] = -array[i];
		i = i +1;
	}
	return array1;
}

void reverse_finya(Array *array, int architecture, int mask, int iteration)
{
	int i = architecture -1;
	int *array1 = (int *)malloc((architecture+1)*sizeof(int));
	while(1)
	{
		while(i < architecture-1)
		{
			array = negative_of_array(array->array, architecture*array->length);
			convert_integer_to_binary(array1, array->array[i], mask, architecture);
			reverse_finya(array, architecture, -1, iteration+1);
			i = i +1;
		}
		i = 0;
		while(i < architecture-1)
		{
			printf("%d ", array1[i]);
			i = i +1;
		}
		printf("\n");
		i = 0;
		if(iteration == 100)
			return 0; 
	}
}

void start_finya(int *array, int architecture, int mask, int iteration)
{
	int *array1 = (int *)malloc(architecture*sizeof(int));
	int i = 0;
	int j = 0;
	while(i <= architecture)
	{
		convert_integer_to_binary(array1, array[i], mask, architecture);
		start_finya(array1, architecture, mask, iteration+1);
		i = i +1;
		while(j <= architecture)
		{
			printf("%d ", array[j]);
			j = j +1;
		}
		printf("\n");
		if(iteration == 100)
			return 0;
	}
}

Array *finya(char *buffer, int architecture, int mask)
{
	Array *array0 = (Array *)malloc(sizeof(struct Arrays));
	array0->array = (int *)malloc((architecture+1)*sizeof(int));
	int i = architecture-1;
	int *tmp = NULL;
	int j = 0;
	int v = 0;
	int number = 0;
	char *c = (char *)malloc(2*sizeof(char));
	while(1)
	{
		while(buffer[j] != '\0')
		{	
			printf("ok");
			snprintf(c, sizeof(char), "%c\0", buffer[j]);
			number = convert_char_to_int(c);
			convert_integer_to_binary(array0->array, number, mask, architecture);
			start_finya(array0->array, architecture, mask, 0);
			if(tmp == NULL)
			{	
				tmp = concatenate_int_arrays(tmp, 0, array0->array, architecture);
				array0->length = array0->length +1;
			}
			else{
				array0->length = array0->length +1;
				tmp = concatenate_int_arrays(tmp, architecture*(array0->length+1), array0, architecture);
			}
			j = j +1;
		}
		j = 0;
	}
	return array0;
}

int main()
{
	Array *array;
	int architecture = 32;
	char *buffer;
	int i = 0;
	while(1)
	{
		buffer = read_io();
		printf("%s\n",  buffer);
		array = finya(buffer, architecture, -1);
		printf("ok");
		reverse_finya(array, architecture, -1, 0);
	}
	return 0;
}
