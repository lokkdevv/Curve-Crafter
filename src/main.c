#include <windows.h>
#include <conio.h>

char running = 1;

char esc_pressed();
void set_cursor_pos(int x, int y);

int main()
{
	COORD pos = {0, 5};
	COORD origin = {0, 0};
	DWORD written;

	HANDLE Sbuffer1 = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	HANDLE Sbuffer2 = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	HANDLE front_buffer = Sbuffer1;
	HANDLE back_buffer = NULL;

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;

	while (running)
	{
		// Check for input to exit the application.
		if (esc_pressed())
			break;

		SetConsoleCursorInfo(front_buffer, &cci);
		back_buffer = (front_buffer == Sbuffer1) ? Sbuffer2 : Sbuffer1;
		
		FillConsoleOutputCharacterA(back_buffer, ' ', 5000, origin, &written);
		WriteConsoleOutputCharacterA(back_buffer, "@", 1, pos, &written);
		pos.X++;

		front_buffer = back_buffer;
		SetConsoleActiveScreenBuffer(front_buffer);

		Sleep(16);
	}

	return 0;
}

void set_cursor_pos(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};

	SetConsoleCursorPosition(out_handle, pos);
}

char esc_pressed()
{
	// ASCII code 27 represents the esc key.

	if (_kbhit())
	{
		if (_getch() == 27)
		{
			return 1;
		}
		return 0;
	}
	return 0;
}