#pragma once

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 50


double square(double num);
double cube(double num);

char** parse(const char* expression, int* out_count);
double evaluate(char** tokens, int count);