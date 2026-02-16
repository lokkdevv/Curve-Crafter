#include "win_input.h"

void init_input(){}
void poll_input(){}
void terminate_input(){}

char exited()
{
	return (GetAsyncKeyState(KEY_ESC) & KEY_JUST_PRESSED) != 0;
}

char is_key_pressed(char KEY)
{
	return (GetAsyncKeyState(KEY) & KEY_PRESSED) != 0;
}

char is_key_just_pressed(char KEY)
{
	return (GetAsyncKeyState(KEY) & KEY_JUST_PRESSED) != 0;
}