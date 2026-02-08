#include "win_renderer.h"

char running;

int console_area;
float draw_interval;

Vec2 origin;
Vec2 console_size;
DWORD written;

HANDLE Sbuffer1;
HANDLE Sbuffer2;
HANDLE front_buffer;
HANDLE back_buffer;

CONSOLE_SCREEN_BUFFER_INFO csbi;
CONSOLE_CURSOR_INFO cci;

void draw_char(char character[], Vec2 pos)
{
	COORD temp = {pos.X, pos.Y};
	WriteConsoleOutputCharacterA(back_buffer, character, 1, temp, &written);
}

void draw_chars(char character[], int size, Vec2 pos)
{
	COORD temp = {pos.X, pos.Y};
	WriteConsoleOutputCharacterA(back_buffer, character, size, temp, &written);
}

void swap_buffers()
{
	GetConsoleScreenBufferInfo(back_buffer, &csbi);
	console_area = (csbi.srWindow.Right + 1) * (csbi.srWindow.Bottom + 1);
	Vec2 temp = {csbi.srWindow.Right + 1, csbi.srWindow.Bottom + 1};
	console_size = temp;
	
	front_buffer = back_buffer;
	SetConsoleActiveScreenBuffer(front_buffer);
	SetConsoleCursorInfo(front_buffer, &cci);
	back_buffer = (front_buffer == Sbuffer1) ? Sbuffer2 : Sbuffer1;
	Sleep(draw_interval / 3.75);
}

void init_single_buffer()
{
	back_buffer = front_buffer;
	SetConsoleActiveScreenBuffer(back_buffer);
	SetConsoleCursorInfo(front_buffer, &cci);
}

void clear_console(int con_area)
{
	COORD temp = {origin.X, origin.Y};
	FillConsoleOutputCharacterA(back_buffer, ' ', con_area, temp, &written);
}

void init_renderer()
{
	draw_interval = 60;

	running = 1;

	origin.X = 0;
	origin.Y = 0;

	Sbuffer1 = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	Sbuffer2 = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	front_buffer = Sbuffer1;
	back_buffer = NULL;

	cci.bVisible = 0;
	cci.dwSize = 1;

	GetConsoleScreenBufferInfo(back_buffer, &csbi);
	console_area = (csbi.srWindow.Right + 1) * (csbi.srWindow.Bottom + 1);
	Vec2 temp = {csbi.srWindow.Right + 1, csbi.srWindow.Bottom + 1};
	console_size = temp;
}

void set_draw_interval(float interval)
{
	draw_interval = interval;
}

void terminate_renderer()
{
	//             I DO NOTHING             //
}