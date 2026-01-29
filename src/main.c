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

	HANDLE out_handle = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(out_handle);

	while (running)
	{
		if (esc_pressed())
			break;
		FillConsoleOutputCharacterA(out_handle, ' ', 5000, origin, &written);
		WriteConsoleOutputCharacterA(out_handle, "@", 1, pos, &written);
		Beep(6000, 1);
		pos.X++;
		Sleep(400);
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