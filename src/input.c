#include "input.h"

char esc_pressed()
{
	// ASCII code 27 represents the esc key.

	if (_kbhit())
	{
		if (_getch() == 27)
		{
			return 1;
		}
		return 0;
	}
	return 0;
}