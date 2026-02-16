#pragma once

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <stdio.h>

// Key definitions (ASCII)
#define KEY_ESC    27
#define KEY_SPACE  32

#define KEY_A 'a'
#define KEY_B 'b'
#define KEY_C 'c'
#define KEY_D 'd'
#define KEY_E 'e'
#define KEY_F 'f'
#define KEY_G 'g'
#define KEY_H 'h'
#define KEY_I 'i'
#define KEY_J 'j'
#define KEY_K 'k'
#define KEY_L 'l'
#define KEY_M 'm'
#define KEY_N 'n'
#define KEY_O 'o'
#define KEY_P 'p'
#define KEY_Q 'q'
#define KEY_R 'r'
#define KEY_S 's'
#define KEY_T 't'
#define KEY_U 'u'
#define KEY_V 'v'
#define KEY_W 'w'
#define KEY_X 'x'
#define KEY_Y 'y'
#define KEY_Z 'z'

void init_input();
void poll_input();
void terminate_input();

char exited();
char is_key_pressed(char key);
char is_key_just_pressed(char key);
