#pragma once
#include <windows.h>


extern char running;

extern float fps;

extern COORD origin;
extern DWORD written;

extern HANDLE Sbuffer1;
extern HANDLE Sbuffer2;
extern HANDLE front_buffer;
extern HANDLE back_buffer;

extern CONSOLE_CURSOR_INFO cci;

void init_buffers();
void swap_buffers();
void clear_console();
void init_renderer();
void draw_char(char character[], COORD pos);
void draw_chars(char character[], int size, COORD pos);
void set_fps(float fps);