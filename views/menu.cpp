#include "views.h"
#include "../config.h"
#include "../utils.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "../i18n.cpp";


using namespace std;

void views::menu(HANDLE hConsole, int key, int& selectedMenu, Page& page) {
	switch (key) {
	case KEY_UP:
		selectedMenu--;
		if (selectedMenu < 0)
			selectedMenu = 0;
		break;
	case KEY_DOWN:
		selectedMenu++;
		if (selectedMenu > 2)
			selectedMenu = 2;
		break;
	case KEY_RETURN:
		switch (selectedMenu) {
		case 0: page = pInfo; break;
		case 1: page = pOrder; break;
		case 2: page = pAuthor; break;
		}
		break;
	default:
		break;
	}

	int color = WHITE_COLOR;

	color = selectedMenu == 0 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);

	COORD firstPos = utils::gotoWriteCenter({ 0, ((ROWS / 2) - 1) }, i18n::pl::ABOUT);
	cout << i18n::pl::ABOUT;

	color = selectedMenu == 1 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);

	utils::gotoNextLine(firstPos);
	cout << i18n::pl::ORDER;

	color = selectedMenu == 2 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);
;
	utils::gotoNextLine(firstPos, 2);
	cout << i18n::pl::AUTHORS;

	SetConsoleTextAttribute(hConsole, WHITE_COLOR);
}
