#include "win_renderer.h"

char running;

float fps;

COORD origin;
DWORD written;

HANDLE Sbuffer1;
HANDLE Sbuffer2;
HANDLE front_buffer;
HANDLE back_buffer;

CONSOLE_CURSOR_INFO cci;

void draw_char(char character[], COORD pos)
{
	WriteConsoleOutputCharacterA(back_buffer, character, 1, pos, &written);
}

void draw_chars(char character[], int size, COORD pos)
{
	WriteConsoleOutputCharacterA(back_buffer, character, size, pos, &written);
}

void init_buffers()
{
	SetConsoleCursorInfo(front_buffer, &cci);
	back_buffer = (front_buffer == Sbuffer1) ? Sbuffer2 : Sbuffer1;
}

void swap_buffers()
{
	front_buffer = back_buffer;
	SetConsoleActiveScreenBuffer(front_buffer);
	Sleep(fps / 3.75);
}

void clear_console()
{
	FillConsoleOutputCharacterA(back_buffer, ' ', 5000, origin, &written);
}

void init_renderer()
{
	fps = 60;

	running = 1;

	origin.X = 0;
	origin.Y = 0;

	Sbuffer1 = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	Sbuffer2 = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	front_buffer = Sbuffer1;
	back_buffer = NULL;

	cci.bVisible = 0;
	cci.dwSize = 1;
}

void set_fps(float input_fps)
{
	fps = input_fps;
}