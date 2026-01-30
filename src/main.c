#ifdef _WIN32

#include <stdio.h>
#include "input/win_input.h"
#include "renderer/win_renderer.h"

#else

#include "input/unix_input.h"
#include "renderer/unix_renderer.h"

#endif

int main()
{
	COORD player_pos = {5, 5};
	
	init_renderer();
	// set_fps(30);
	
	while (running)
	{
		if (exited())
			break;

		init_buffers();
		clear_console();

		if (is_key_pressed(KEY_D))
		{
			player_pos.X += 1;
		}
		if (is_key_pressed(KEY_Q))
		{
			player_pos.X -= 1;
		}
		if (is_key_pressed(KEY_Z))
		{
			player_pos.Y -= 1;
		}
		if (is_key_pressed(KEY_S))
		{
			player_pos.Y += 1;
		}
		draw_char("@", player_pos);
		
		
		swap_buffers();
	}

	return 0;
}