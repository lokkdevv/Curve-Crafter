#pragma once

#define _POSIX_C_SOURCE 199309L

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "../core/engine/engine.h"


extern char running;

extern int console_area;
extern float draw_interval;

extern Vec2 origin;
extern Vec2 console_size;

extern struct winsize ws;

// This function is only supposed to be called by the renderer, Not the User //
/**/ void set_cursor_pos(Vec2 pos);
////

void swap_buffers();
void init_single_buffer();
void clear_console(int con_area);
void init_renderer();
void draw_char(char character[], Vec2 pos);
void draw_chars(char character[], int size, Vec2 pos);
void set_draw_interval(float draw_interval);

void terminate_renderer();