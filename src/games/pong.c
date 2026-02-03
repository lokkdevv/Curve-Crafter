#ifdef _WIN32

#include "../input/win_input.h"
#include "../renderer/win_renderer.h"
#include <stdlib.h>
#include <time.h>

#else

#include "../input/linux_input.h"
#include "../renderer/linux_renderer.h"
#include <stdlib.h>
#include <time.h>

#endif

#define BALL_SPEED 1

int main()
{
	// Set random starting Direction for the Ball //
	Vec2 ball_dir = {0, 0};
	srand(time(NULL));
	ball_dir.X = rand() % 2;
	if (ball_dir.X == 0) ball_dir.X = -BALL_SPEED;
	else ball_dir.X = BALL_SPEED;
	////////////////////////////////////////////////

	char game_started = 0;

	Vec2 player1_pos = {5, 10};
	Vec2 player2_pos = {160, 10};

	Vec2 ball_pos = {80, 6};

	init_renderer();
	
	while (running)
	{
		// Seed random number
		srand(time(NULL));

		// Exit if ESC pressed
		if (exited()) break;
		
		if (is_key_just_pressed(KEY_SPACE)) game_started = 1;

		if (!game_started)
		{
			ball_pos.X = console_size.X / 2 - 1;
			ball_pos.Y = console_size.Y / 2 - 1;

			player1_pos.Y = console_size.Y / 2 - 1;
			player2_pos.Y = console_size.Y / 2 - 1;
			player2_pos.X = console_size.X - 5;

			Vec2 text_pos = {ball_pos.X - ball_pos.X / 4, ball_pos.Y};
			Vec2 text_pos_2 = {ball_pos.X - (ball_pos.X / 2 - ball_pos.X / 10), ball_pos.Y + 2};
			clear_console(console_area);
			draw_chars("Press 'SPACE' to start the game.", 32, text_pos);
			draw_chars("Do not resize the terminal windows after pressing 'SPACE'.", 58, text_pos_2);
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
			
			// Player Bounds Checking ////////////
			if (player1_pos.Y < 1) player1_pos.Y = 1;
			if (player1_pos.Y > console_size.Y - 2) player1_pos.Y = console_size.Y - 2;
			if (player2_pos.Y < 1) player2_pos.Y = 1;
			if (player2_pos.Y > console_size.Y - 2) player2_pos.Y = console_size.Y - 2;
			//////////////////////////////////////
	
			// Update the players ////////////////
			// top and bottom position ///////////
			Vec2 player1_pos_top = {player1_pos.X, player1_pos.Y - 1};
			Vec2 player1_pos_bottom = {player1_pos.X, player1_pos.Y + 1 };
			Vec2 player2_pos_top = {player2_pos.X, player2_pos.Y - 1};
			Vec2 player2_pos_bottom = {player2_pos.X, player2_pos.Y + 1};
			//////////////////////////////////////

			// P1 Collision Detection ////////////
			if (ball_dir.X < 0 && (ball_pos.X <= player1_pos.X) && (ball_pos.Y <= player1_pos_bottom.Y) && (ball_pos.Y >= player1_pos_top.Y))
			{
				if (ball_pos.Y < player1_pos.Y) ball_dir.Y = -1;
				else if (ball_pos.Y > player1_pos.Y) ball_dir.Y = 1;
				else ball_dir.Y = 0;
				
				ball_dir.X = -ball_dir.X;
			}
			//////////////////////////////////////

			// P2 Collision Detection ////////////
			else if (ball_dir.X > 0 && (ball_pos.X >= player2_pos.X) && (ball_pos.Y <= player2_pos_bottom.Y) && (ball_pos.Y >= player2_pos_top.Y))
			{
				if (ball_pos.Y < player2_pos.Y) ball_dir.Y = -1;
				else if (ball_pos.Y > player2_pos.Y) ball_dir.Y = 1;
				else ball_dir.Y = 0;

				ball_dir.X = -ball_dir.X;
			}
			//////////////////////////////////////
			
			// Ball Bounds Checking //////////////
			if (ball_pos.Y < 1) ball_dir.Y = -ball_dir.Y;
			if (ball_pos.Y > console_size.Y - 2) ball_dir.Y = -ball_dir.Y;

			if (ball_pos.X < 0 || ball_pos.X > console_size.X) game_started = 0;
			//////////////////////////////////////

			// Update Ball position //////////////
			ball_pos.X += ball_dir.X;
			ball_pos.Y += ball_dir.Y;
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