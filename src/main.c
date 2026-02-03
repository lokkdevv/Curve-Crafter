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
		printf("EXAMPLE: %s \"9*x\"\n", argv[0]);
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
	
		// Drawing the axies ////////////////////
		// X AXIS
		for (int i = 0; i < console_size.X; i++)
		{
			Vec2 x_axis_pos = {i, (console_size.Y / 2) + camera_y_offset};
			draw_char("#", x_axis_pos);
		}
		// Y AXIS
		for (int i = 0; i < console_size.Y; i++)
		{
			Vec2 y_axis_pos = {(console_size.X / 2) + camera_x_offset, i};
			draw_char("#", y_axis_pos);
		}
		/////////////////////////////////////////

		// Plotting /////////////////////////////
		while (x < MAX_X)
		{
			num = 0;
			parsed = parse(argv[1], &num);

			for (int i = 0; i < num; i++)
			{
				if (strcmp(parsed[i], "x") == 0)
				{
					char x_buffer[32];
					parsed[i] = itoa(x, x_buffer, 10);
				}
			}
			x++;
			result = evaluate(parsed, num);
			Vec2 pos = {x + camera_x_offset + console_size.X/2, (-1*(short)(floor(result))) + camera_y_offset + console_size.Y/2};
			draw_char("*", pos);
		}
		x = MIN_X;
		/////////////////////////////////////////

		swap_buffers();
	}
	

	return 0;
}