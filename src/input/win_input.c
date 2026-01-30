#include "win_input.h"

char esc_pressed()
{
	// ASCII code 27 represents the esc key.

	if (_kbhit())
	{
		if (_getch() == KEY_ESC)
		{
			return 1;
		}
		return 0;
	}
	return 0;
}

char key_pressed(char KEY)
{
	if (!_kbhit())
	{
		return 0;
	}
	if (_getch() == KEY)
	{
		return 1;
	}
	return 0;
}

char arrow_key_pressed(char KEY)
{
	if (!_kbhit())
	{
		return 0;
	}

	if ( _getch() == KEY_ARROW)
	{
		if (_getch() == KEY)
		{
			return 1;
		}
	}
	return 0;
}