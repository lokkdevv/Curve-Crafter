#include "math.h"


double square(double num)
{
	return num * num;
}
double cube(double num)
{
	return num * num * num;
}

char** parse(const char* expression, int* out_count)
{
	char** result = malloc(sizeof(char*) * MAX_INPUT_SIZE);
	int result_index = 0;

	for (int i = 0; expression[i] != '\0'; )
	{
		if (isspace(expression[i])) {
			i++;
			continue;
		}

		// Number token
		if (isdigit(expression[i])) {
			int start = i;
			while (isdigit(expression[i])) i++;

			int len = i - start;
			char* num = malloc(len + 1);
			memcpy(num, &expression[start], len);
			num[len] = '\0';

			result[result_index++] = num;
		}
		// Operator token
		else {
			char* op = malloc(2);
			op[0] = expression[i];
			op[1] = '\0';

			result[result_index++] = op;
			i++;
		}
	}

	result[result_index] = NULL;
	*out_count = result_index;
	return result;
}

double evaluate(char** tokens, int count)
{
	double result = 0;
	double temp_result = atof(tokens[0]);

	for (int i = 1; i < count; i += 2)
	{
		char op = tokens[i][0];
		double next = atof(tokens[i + 1]);

		if (op == '*')
		{
			temp_result *= next;
		}
		else if (op == '/')
		{
			temp_result /= next;
		}
		else if (op == '+')
		{
			result += temp_result;
			temp_result = next;
		}
		else if (op == '-')
		{
			result += temp_result;
			temp_result = -next;
		}
	}

	result += temp_result;
	return result;
}
