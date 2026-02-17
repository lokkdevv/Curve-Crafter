#include "engine.h"

int engine_floor(double num)
{
	int temp = (int)num;
	return (temp > num) ? (temp - 1) : temp;
}

char* int_to_ascii(int num)
{
	char* output = malloc(MAX_OUTPUT_SIZE);
	char* result = malloc(MAX_OUTPUT_SIZE);
	int index = 0;

	int towat = (num < 0) ? -1 : 1;
	if (num == 0)
	{
		free(output);
		free(result);
		return "0";
	}
	while ((num < 0) ? (towat>=num) : (towat<=num))
	{
		output[index] = '0' + ((num%(towat*10) - num%towat) / towat);
		index++;
		towat *= 10;
	}

	// Handling negative numbers //
	if (num < 0) output[index++] = '-';
	///////////////////////////////
	
	// String reversing ///////////
	int y = index - 1;
	for (int i = 0; i < index + 1; i++) result[i] = output[y--];
	///////////////////////////////

	result[index + 1] = '\0';

	free(output);
	return result;
}