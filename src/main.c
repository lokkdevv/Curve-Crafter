#ifdef _WIN32

#include <stdio.h>
#include "input/win_input.h"
#include "renderer/win_renderer.h"
#include "core/math/math.h"
#include "math.h"

#else

#include "input/unix_input.h"
#include "renderer/unix_renderer.h"

#endif

#define MAX_X 300
#define MIN_X -5

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("ERROR: Incorrect use of application!\n");
		return 1;
	}

	int x = MIN_X;
	int num = 0;
	char** parsed;

	// printf("%.2f\n", result);
	init_renderer();

	while (running)
	{
		if (exited()) running = 0;
		

		if (x > MAX_X)
		{
			x = MAX_X;
		}

		num = 0;
		parsed = parse(argv[1], &num);

		char x_storage[32] = "";
		for (int i = 0; i < num; i++)
		{
			if (strcmp(parsed[i], "x") == 0)
			{
				parsed[i] = itoa(x, x_storage, 10);
				break;
			}
		}
		x++;
		double result = evaluate(parsed, num);

		COORD pos = {x + 10, (short)(floor(result)) / 5};
		draw_char("@", pos);
		swap_buffers();
	}
	

	return 0;
}