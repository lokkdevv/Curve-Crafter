#include "cli_os_layer.h"
#include "input.h"


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

		swap_buffers(16);
	}

	return 0;
}
