#ifdef _WIN32

#include <stdio.h>
#include "input/win_input.h"
#include "renderer/win_renderer.h"
#include "core/math/math.h"
#include "math.h"

#else

#include <stdio.h>
#include "input/linux_input.h"
#include "renderer/linux_renderer.h"
#include "core/math/math.h"
#include "math.h"

#endif

#define MAX_X 300
#define MIN_X -300

//////////////////////////////////////////////////////
// WARNING: Only use functions from the game engine //
//////////////// Do Not Use variables ////////////////
//////////////////////////////////////////////////////

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("ERROR: You must enter atleast one expression\n");
		printf("EXAMPLE: %s \"9*x\"\n", argv[0]);
		return 1;
	}

	char first_time = 1;

	int camera_x_offset = 0;
	int camera_y_offset = 0;

	int x;
	int num;
	char** parsed;
	double result = 0;

	init_input();
	init_renderer();
	set_draw_interval(0);


	while (running)
	{
		poll_input();

		if (exited()) running = 0;

		if (is_key_pressed(KEY_Q)) camera_x_offset += 2;
		if (is_key_pressed(KEY_D)) camera_x_offset -= 2;
		if (is_key_pressed(KEY_Z)) camera_y_offset += 1;
		if (is_key_pressed(KEY_S)) camera_y_offset -= 1;
		x = - console_size.X - camera_x_offset;

		clear_console();
	
		// Drawing the axies ////////////////////
		// X AXIS
		for (int i = 0; i < console_size.X; i++)
		{
			Vec2 x_axis_pos = {i, (console_size.Y / 2) + camera_y_offset};
			draw_char("-", x_axis_pos);
		}
		// Y AXIS
		for (int i = 0; i < console_size.Y; i++)
		{
			Vec2 y_axis_pos = {(console_size.X / 2) + camera_x_offset, i};
			draw_char("|", y_axis_pos);
		}
		/////////////////////////////////////////

		Vec2 old_pos = {0, 0};
		// Plotting /////////////////////////////
		while (x < /*MAX_X*/ console_size.X - camera_x_offset)
		{
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
			Vec2 pos = {(x + camera_x_offset + console_size.X/2), (-1*(short)(floor(result))) + camera_y_offset + console_size.Y/2};
			draw_char("*", pos);
			
			#ifdef SMOOTH
			if (first_time)
			{
				old_pos = pos;
				first_time = 0;
				continue;
			}

			int stepY = (old_pos.Y < pos.Y) ? 1 : -1;
			int stepX = (old_pos.X < pos.X) ? 1 : -1;

			while (old_pos.Y != pos.Y)
			{
				Vec2 new_pos = {old_pos.X, old_pos.Y};
				draw_char("*", new_pos);
				old_pos.Y += stepY;
			}
			while (old_pos.X != pos.X)
			{
				Vec2 new_pos = {old_pos.X, old_pos.Y};
				draw_char("*", new_pos);
				old_pos.X += stepX;
			}
			old_pos = pos;
			#endif
			
		}
		x = MIN_X;
		first_time = 1;
		/////////////////////////////////////////

		swap_buffers();
	}

	terminate_input();
	terminate_renderer();

	return 0;
}
