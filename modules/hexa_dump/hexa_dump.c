#include <stdlib.h>
#include <stdio.h>

int convert_hexa_to_int(char hexa)
{
	if(hexa == '0')
		return 0;
	if(hexa == '1')
		return 1;
	if(hexa == '2')
		return 2;
	if(hexa == '3')
		return 3;
	if(hexa == '4')
		return 4;
	if(hexa == '5')
		return 5;
	if(hexa == '6')
		return 6;
	if(hexa == '7')
		return 7;
	if(hexa == '8')
		return 8;
	if(hexa == '9')
		return 9;
	if(hexa == 'a')
		return 10;
	if(hexa == 'b')
		return 11;
	if(hexa == 'c')
		return 12;
	if(hexa == 'd')
		return 13;
	if(hexa == 'e')
		return 14;
	if(hexa == 'f')
		return 15;
}
void convert_hexa_to_binary(int *array, char hexa)
{
	int number = convert_hexa_to_int(hexa);
	int mask_shifted = 0;
	int and_result = 0;
	int i = 0;
	while(i < 4)
	{
		mask_shifted = 1 << i;
		and_result = number & mask_shifted;
		array[i] = and_result >> i; 
		i = i +1;
	}
}
