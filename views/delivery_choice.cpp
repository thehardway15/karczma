#include <conio.h>
#include <iostream>
#include "../views/views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include <string>
#include "../i18n.cpp"

using namespace std;

void views::deliveryChoice(HANDLE hConsole, int key, Page& page, int& selectedOption) {

	int color;
	string deliveryChoiceRequest = i18n::pl::PROVIDE_DELIVERY_CHOICE;
	string takeawayChoice = i18n::pl::TAKEAWAY_CHOICE;
	string onTheSpotChoice = i18n::pl::ON_THE_SPOT_CHOICE;
	string navigationMessegeNext = i18n::pl::PRESS_ENTER_TO_CONTINUE;
	string navigationMessegeBack = i18n::pl::PRESS_RETURN_TO_BACK;

	switch (key) {
	case KEY_DOWN:
		if (selectedOption == 0) {
			selectedOption++;
		}
		break;
	case KEY_UP:
		if (selectedOption == 1) {
			selectedOption--;
		}
		break;
	case KEY_ESCAPE:
		page = pUsername;
		break;
	case KEY_ENTER:
		if (selectedOption == 0) {
			page = pTableChoice;
		}
		else {
			page = pDeliveryAddress;
		}
		break;
	default:
		break;
	}

	COORD firstPos = utils::gotoWriteCenter({ 0, ((ROWS / 2) - 2) }, deliveryChoiceRequest);
	cout << deliveryChoiceRequest << endl;

	utils::gotoNextLine(firstPos, 2);

	color = selectedOption == 0 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);
	cout << onTheSpotChoice;

	utils::gotoNextLine(firstPos, 4);

	color = selectedOption == 1 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);
	cout << takeawayChoice;

	COORD secondPos = utils::gotoxy(COLS / 2, ROWS - 5);
	utils::gotoWriteCenter(secondPos, navigationMessegeNext);
	SetConsoleTextAttribute(hConsole, WHITE_COLOR);
	cout << navigationMessegeNext;

	utils::gotoWriteCenter(utils::gotoNextLine(secondPos, 2), navigationMessegeBack);
	cout << navigationMessegeBack;
}