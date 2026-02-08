#include "linux_renderer.h"

char running;

int console_area;
float draw_interval;

Vec2 origin;
Vec2 console_size;

struct winsize ws;

void set_cursor_pos(Vec2 pos)
{
	printf("\033[%d;%dH", pos.Y + 1, pos.X + 1);
}

void draw_char(char character[], Vec2 pos)
{
	set_cursor_pos(pos);
	printf("%s", character);
	Vec2 temp = {0, 0};
	set_cursor_pos(temp);
}

void draw_chars(char character[], int size, Vec2 pos)
{
	size++;

	set_cursor_pos(pos);
	printf("%s", character);
	Vec2 temp = {0, 0};
	set_cursor_pos(temp);
}

void swap_buffers()
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	console_area = ws.ws_col * ws.ws_row;
	Vec2 temp = {ws.ws_col + 1, ws.ws_row + 1};
	console_size = temp;
	
	struct timespec ts;
	ts.tv_sec = 0;
	ts.tv_nsec = draw_interval / 3.75 * 1000000;
	nanosleep(&ts, NULL);
}

void clear_console()
{
	printf("\033[2J\033[H");
}

void init_renderer()
{
	printf("\033[?1049h");
	printf("\033[?25l");

	draw_interval = 60;

	running = 1;

	origin.X = 0;
	origin.Y = 0;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

	console_area = ws.ws_col * ws.ws_row;
	Vec2 temp = {ws.ws_col + 1, ws.ws_row + 1};
	console_size = temp;
}

void terminate_renderer()
{
	printf("\033[?1049l");
	printf("\033[?25h");
}

void set_draw_interval(float interval)
{
	draw_interval = interval;
}