#ifdef _WIN32

#include "../input/win_input.h"
#include "../renderer/win_renderer.h"

#else

#include "../input/unix_input.h"
#include "../renderer/unix_renderer.h"

#endif

int main()
{
	COORD player1_pos = {5, 5};
	COORD player2_pos = {160, 5};

	COORD ball_pos = {80, 6};

	init_renderer();
	
	while (running)
	{
		// Correct PLAYER2 x position
		player2_pos.X = console_size.X - 5;

		// Exit if ESC pressed
		if (exited()) break;
		
		// PLAYER1 input /////////////////////
		if (is_key_pressed(KEY_W))
		{
			player1_pos.Y -= 1;
		}
		if (is_key_pressed(KEY_S))
		{
			player1_pos.Y += 1;
		}
		//////////////////////////////////////

		// PLAYER2 input /////////////////////
		if (is_key_pressed(KEY_UP))
		{
			player2_pos.Y -= 1;
		}
		if (is_key_pressed(KEY_DOWN))
		{
			player2_pos.Y += 1;
		}
		//////////////////////////////////////

		COORD player1_pos2 = {player1_pos.X, player1_pos.Y + 1};
		COORD player1_pos3 = {player1_pos.X, player1_pos.Y + 2};

		COORD player2_pos2 = {player2_pos.X, player2_pos.Y + 1};
		COORD player2_pos3 = {player2_pos.X, player2_pos.Y + 2};
		
		clear_console(console_area);
		
		draw_char("@", ball_pos);
		
		draw_char("#", player1_pos);
		draw_char("#", player1_pos2);
		draw_char("#", player1_pos3);

		draw_char("#", player2_pos);
		draw_char("#", player2_pos2);
		draw_char("#", player2_pos3);
		
		swap_buffers();
	}
	
	return 0;
}