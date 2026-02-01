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
	/*int num = 0;
	char** parsed = parse(argv[1], &num);
	for (int i = 0; i < num; i++)
	{
		printf("token[%d]: %s\n", i, parsed[i]);
	}
	double result = evaluate(parsed, num);*/

	COORD player_pos = {5, 5};
	COORD player_pos2;
	COORD player_pos3;
	COORD ball_pos = {80, 6};

	init_renderer();
	
	while (running)
	{
		if (exited())
		break;
		
		if (is_key_pressed(KEY_UP))
		{
			player_pos.Y -= 1;
		}
		if (is_key_pressed(KEY_DOWN))
		{
			player_pos.Y += 1;
		}
		
		COORD player_pos2 = {player_pos.X, player_pos.Y + 1};
		COORD player_pos3 = {player_pos.X, player_pos.Y + 2};
		
		clear_console(console_area);
		
		draw_char("@", ball_pos);
		
		draw_char("#", player_pos);
		draw_char("#", player_pos2);
		draw_char("#", player_pos3);
		
		swap_buffers();
	}
	
	return 0;
}