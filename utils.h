#include <Windows.h>
#include <iostream>

namespace utils
{
	int getch_noblock();
	void drawBox(int width, int height, char fillChar);
	void clearScreen();
	void clearContent();
	COORD gotoxy(int x, int y);
	COORD gotoCenter();
	COORD gotoNextLine(COORD current, short line = 1);
	COORD gotoWriteCenter(COORD current, std::string s);
	COORD gotoRight(COORD current, short padding = 1);
}