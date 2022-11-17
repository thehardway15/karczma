#include <conio.h>
#include <iostream>
#include "../views/views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include <string>
#include "../i18n.cpp"

using namespace std;

void views::tableChoice(HANDLE hConsole, int key, Page& page, int& table) {

	string navigationMessegeNext = i18n::pl::PRESS_ENTER_TO_CONTINUE;
	string navigationMessegeBack = i18n::pl::PRESS_RETURN_TO_BACK;
	string tableChoiceRequest = i18n::pl::PROVIDE_TABLE_NUMBER;
	string successfulInput = i18n::pl::SUCCESSFUL_INPUT;
	string wrongCharMsg = i18n::pl::WRONG_CHAR_MSG;
	string tableNumberRequired = i18n::pl::TABLE_NUMBER_REQUIRED;

	COORD firstPos = utils::gotoWriteCenter({ 0, ((ROWS / 2) - 2) }, tableChoiceRequest);
	SetConsoleTextAttribute(hConsole, WHITE_COLOR);
	cout << tableChoiceRequest << endl;

	utils::gotoNextLine(firstPos, 2);


	switch (key) {
	case KEY_ESCAPE:
		page = pMenu;
		break;
	case KEY_ENTER:
		if (table > 0) {
			page = pOrder;
			break;
		}
		else {
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 4), tableNumberRequired);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << tableNumberRequired;
			Sleep(1000);
		}
	default:
		if (isdigit(key) && key > 0) {
			table = key;
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 4), successfulInput);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << successfulInput;
			Sleep(1000);
		}
		else if (!isdigit(key) && key != KEY_DEFAULT) {
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 4), wrongCharMsg);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << wrongCharMsg;
			Sleep(1000);
		}
		break;
	}
}