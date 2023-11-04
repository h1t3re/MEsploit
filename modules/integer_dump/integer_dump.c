const int shift_mask_left(const int i)
{
	const int mask_shifted = 1 << i;
	return mask_shifted;
}

const int shift_result_right(const int result, const int i)
{
	const int result_shifted = result >> i;
	return result_shifted;
}

const int and_operation(const int number, const int mask_shifted)
{
	const int and_result = number & mask_shifted;
	return and_result;
}


void convert_integer_to_binary(int *array, const int number)
{
	int i = 0;
	while(i < 32)
	{
		const int mask_shifted = shift_mask_left(i);
		const int and_result = and_operation(number, mask_shifted);
		array[i] = shift_result_right(and_result, i);
		i = i +1;
	}
}
