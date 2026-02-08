#pragma once
#include <windows.h>
#include "../core/engine/engine.h"

extern char running;

extern int console_area;
extern float draw_interval;

extern Vec2 origin;
extern Vec2 console_size;
extern DWORD written;

extern HANDLE Sbuffer1;
extern HANDLE Sbuffer2;
extern HANDLE front_buffer;
extern HANDLE back_buffer;

extern CONSOLE_SCREEN_BUFFER_INFO csbi;
extern CONSOLE_CURSOR_INFO cci;

void swap_buffers();
void clear_console();
void init_renderer();
void draw_char(char character[], Vec2 pos);
void draw_chars(char character[], int size, Vec2 pos);
void set_draw_interval(float draw_interval);

void terminate_renderer();