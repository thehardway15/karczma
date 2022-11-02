#include <conio.h>
#include "./views/views.h"
#include "./config.h"
#include "./utils.h"
#include <Windows.h>
#include <string>
#include "./i18n.cpp"

using namespace std;

void views::username(HANDLE hConsole, int key, string& customerName, Page& page) {

	int color = WHITE_COLOR;
	string customerNameRequest = i18n::pl::PROVIDE_CUSTOMERNAME + ":";
	string wrongCharMessege = i18n::pl::WRONG_CHAR_MSG;
	string shortInputMessege = i18n::pl::SHORT_INPUT_MSG;
	string navigationMessegeNext = i18n::pl::PRESS_ENTER_TO_CONTINUE;
	string navigationMessegeBack = i18n::pl::PRESS_ESCAPE_TO_GO_BACK;

	COORD firstPos = utils::gotoWriteCenter({ 0, ((ROWS / 2) - 2) }, customerNameRequest);
	cout << customerNameRequest;

	utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 2), customerName);
	cout << customerName;

	COORD secondPos = utils::gotoxy(COLS / 2, ROWS - 5);
	utils::gotoWriteCenter(secondPos, navigationMessegeNext);
	cout << navigationMessegeNext;

	utils::gotoWriteCenter(utils::gotoNextLine(secondPos, 2), navigationMessegeBack);
	cout << navigationMessegeBack;

	switch (key) {
	case KEY_RETURN: {
		if (customerName.size() < 3) {

			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 4), shortInputMessege);

			color = RED_COLOR;
			SetConsoleTextAttribute(hConsole, color);

			cout << shortInputMessege;
			Sleep(1000);

			color = WHITE_COLOR;
			SetConsoleTextAttribute(hConsole, color);
		}
		else
			page = pMenu;
		break;
	}
	case KEY_ESCAPE: {
		page = pMenu;
		break;
	}
	case BACK_SPACE: {
		if (customerName.size() > 0)
			customerName.pop_back();
		break;
	}
	default: {
		if (isalpha(key) && customerName.size() <= USERNAME_CAP) {
			customerName += key;
		}
		else if (!isalpha(key) && key != KEY_DEFAULT && customerName.size() <= USERNAME_CAP) {

			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 4), wrongCharMessege);

			color = RED_COLOR;
			SetConsoleTextAttribute(hConsole, color);

			cout << wrongCharMessege;
			Sleep(1000);

			color = WHITE_COLOR;
			SetConsoleTextAttribute(hConsole, color);
		}
		break;
	}
	}
}