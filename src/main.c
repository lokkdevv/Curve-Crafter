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

#define MAX_X 500
#define MIN_X -500

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("ERROR: You must enter atleast one expression\n");
		printf("EXAMPLE: %s \033[34m\"9*x\"\n", argv[0]);
		return 1;
	}

	int camera_x_offset = 0;
	int camera_y_offset = 0;

	int x = MIN_X;
	int num = 0;
	char** parsed;
	double result = 0;

	init_renderer();
	set_draw_interval(0);

	while (running)
	{
		if (exited()) running = 0;

		if (is_key_pressed(KEY_LEFT)) camera_x_offset += 2;
		if (is_key_pressed(KEY_RIGHT)) camera_x_offset -= 2;
		if (is_key_pressed(KEY_UP)) camera_y_offset += 1;
		if (is_key_pressed(KEY_DOWN)) camera_y_offset -= 1;
		
		clear_console(console_area);
	
		while (x < MAX_X)
		{
			num = 0;
			parsed = parse(argv[1], &num);

			char x_buffer[32];
			for (int i = 0; i < num; i++)
			{
				if (strcmp(parsed[i], "x") == 0)
				{
					parsed[i] = itoa(x, x_buffer, 10);
					break;
				}
			}
			x++;
			result = evaluate(parsed, num);
			COORD pos = {x + camera_x_offset, (-1*(short)(floor(result)) / 5) + camera_y_offset};
			draw_char("@", pos);
		}
		x = MIN_X;

		swap_buffers();
	}
	

	return 0;
}