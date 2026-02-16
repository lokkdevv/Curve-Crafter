#include "linux_input.h"

static struct termios old_tio;
static int last_key = -1;

void init_input()
{
    tcgetattr(STDIN_FILENO, &old_tio);

    struct termios raw = old_tio;
    cfmakeraw(&raw);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);

    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void terminate_input()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

void poll_input()
{
    last_key = -1;

    unsigned char ch;
    if (read(STDIN_FILENO, &ch, 1) > 0)
        last_key = ch;
}

char exited()
{
    return last_key == KEY_ESC;
}

char is_key_pressed(char key)
{
    return last_key == key;
}

char is_key_just_pressed(char key)
{
    return last_key == key;
}
