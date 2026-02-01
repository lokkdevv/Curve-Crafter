#ifdef _WIN32

#include <stdio.h>
#include "input/win_input.h"
#include "renderer/win_renderer.h"
#include "core/math/math.h"

#else

#include "input/unix_input.h"
#include "renderer/unix_renderer.h"

#endif

int main(int argc, char** argv)
{

	int num = 0;
	char** parsed = parse(argv[1], &num);
	double result = evaluate(parsed, num);


	/*
	COORD player_pos = {5, 5};
	
	init_renderer();
	
	while (running)
	{
		if (exited())
			break;
			
		if (is_key_pressed(KEY_RIGHT))
		{
			player_pos.X += 1;
		}
		if (is_key_pressed(KEY_LEFT))
		{
			player_pos.X -= 1;
		}
		if (is_key_pressed(KEY_UP))
		{
			player_pos.Y -= 1;
		}
		if (is_key_pressed(KEY_DOWN))
		{
			player_pos.Y += 1;
		}
		
		
		clear_console();

		draw_char("#", player_pos);

		
		swap_buffers();
	}
	*/
	return 0;
}