#ifdef _WIN32

#include "../input/win_input.h"
#include "../renderer/win_renderer.h"

#else

#include "../input/unix_input.h"
#include "../renderer/unix_renderer.h"

#endif

int main()
{
	char game_started = 0;

	COORD player1_pos = {5, 10};
	COORD player2_pos = {160, 10};

	COORD ball_pos = {80, 6};

	init_renderer();
	
	while (running)
	{
		// Correct PLAYER2 x position
		player2_pos.X = console_size.X - 5;

		// Exit if ESC pressed
		if (exited()) break;
		
		if (is_key_just_pressed(KEY_SPACE)) game_started = 1;

		if (!game_started)
		{
			ball_pos.X = console_size.X / 2 - 1;
			ball_pos.Y = console_size.Y / 2 - 1;
			COORD text_pos = {ball_pos.X - ball_pos.X / 4, ball_pos.Y};
			clear_console(console_area);
			draw_chars("Press 'SPACE' to start the game.", 32, text_pos);
		}
		
		else if (game_started)
		{
			// PLAYER1 input /////////////////////
			if (is_key_pressed(KEY_Z)) player1_pos.Y -= 1;
			if (is_key_pressed(KEY_S)) player1_pos.Y += 1;
			//////////////////////////////////////
	
			// PLAYER2 input /////////////////////
			if (is_key_pressed(KEY_UP)) player2_pos.Y -= 1;
			if (is_key_pressed(KEY_DOWN)) player2_pos.Y += 1;
			//////////////////////////////////////
	
			// Bounds Checking ///////////////////
			if (player1_pos.Y < 1) player1_pos.Y = 1;
			if (player1_pos.Y > console_size.Y - 2) player1_pos.Y = console_size.Y - 2;
			if (player2_pos.Y < 1) player2_pos.Y = 1;
			if (player2_pos.Y > console_size.Y - 2) player2_pos.Y = console_size.Y - 2;
			//////////////////////////////////////
	
			// Update the players ////////////////
			// top and bottom position ///////////
			COORD player1_pos_top = {player1_pos.X, player1_pos.Y - 1};
			COORD player1_pos_bottom = {player1_pos.X, player1_pos.Y + 1 };
			COORD player2_pos_top = {player2_pos.X, player2_pos.Y - 1};
			COORD player2_pos_bottom = {player2_pos.X, player2_pos.Y + 1};
			//////////////////////////////////////

			clear_console(console_area);
			
			draw_char("@", ball_pos);
			
			draw_char("#", player1_pos_top);
			draw_char("#", player1_pos);
			draw_char("#", player1_pos_bottom);
	
			draw_char("#", player2_pos_top);
			draw_char("#", player2_pos);
			draw_char("#", player2_pos_bottom);
		}
		
		swap_buffers();
	}
	
	return 0;
}