#pragma once
#include <windows.h>

extern char running;

extern COORD origin;
extern DWORD written;

extern HANDLE Sbuffer1;
extern HANDLE Sbuffer2;
extern HANDLE front_buffer;
extern HANDLE back_buffer;

extern CONSOLE_CURSOR_INFO cci;

void init_buffers();
void swap_buffers(int);
void clear_con();
void init_win_cli();
void set_cursor_pos(int x, int y);

