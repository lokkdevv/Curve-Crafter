#pragma once
#include <stdlib.h>

#define MAX_OUTPUT_SIZE 256

typedef struct Vec2 {
	short X;
	short Y;
} Vec2;

int engine_floor(double num);
char* int_to_ascii(int num);