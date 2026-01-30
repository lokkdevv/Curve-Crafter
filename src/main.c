#ifdef _WIN32

// #include <stdio.h>
#include "input/win_input.h"
#include "renderer/win_renderer.h"

#else

#include "input/unix_input.h"
#include "renderer/unix_renderer.h"

#endif

int main()
{
	COORD pos = {0, 5};
	
	init_renderer();
	// set_fps(30);
	
	while (running)
	{
		if (esc_pressed())
			break;

		init_buffers();
		clear_console();

		draw_char("*", pos);
		pos.X++;

		swap_buffers();
	}

	return 0;
}