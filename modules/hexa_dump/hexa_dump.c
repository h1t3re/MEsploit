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

const int shift_mask_left(const int i)
{
	const int mask_shifted = 1 << i;
	return mask_shifted;
}

const int and_operation(const int number, const int mask_shifted)
{
	const int and_result = number & mask_shifted;
	return and_result;
}

const int result_shifted_right(const int result, const int i)
{
	const int result_shifted = result >> i;
	return result_shifted;
}

void convert_hexa_to_binary(int *array, char hexa)
{
	const int number = convert_hexa_to_int(hexa);
	int i = 0;
	while(i < 4)
	{
		const int mask_shifted = shift_mask_left(i);
		const int and_result = and_operation(number, mask_shifted);
		array[i] = result_shifted_right(and_result, i); 
		i = i +1;
	}
}
