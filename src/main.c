#ifdef _WIN32

#include "input/win_input.h"
#include "renderer/win_renderer.h"

#else

#include "input/unix_input.h"
#include "renderer/unix_renderer.h"

#endif

int main()
{
	COORD pos = {0, 5};

	init_win_cli();

	while (running)
	{
		// Check for input to exit the application.
		if (esc_pressed())
			break;

		init_buffers();

		clear_con();
		WriteConsoleOutputCharacterA(back_buffer, "@", 1, pos, &written);
		pos.X++;

		swap_buffers(60.0);
	}

	return 0;
}