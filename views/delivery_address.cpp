#include <conio.h>
#include <iostream>
#include "../views/views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include <string>
#include "../i18n.cpp"

using namespace std;

extern struct deliveryStruct {
	string address;
	int date;
	int hour;
};

void views::deliveryAddress(HANDLE hConsole, int key, Page& page, deliveryStruct& deliveryData,
	int& selectedOption, string& addressPlaceholder, string& datePlaceholder, string& hourPlaceholder) {
	
	int color;
	int dupa;
	string provideAddressData = i18n::pl::PROVIDE_ADDRESS_DATA;
	string address = i18n::pl::ADDRESS;
	string date = i18n::pl::DATE;
	string hour = i18n::pl::HOUR;
	string navigationMessegeNext = i18n::pl::PRESS_ENTER_TO_CONFIRM;
	string navigationMessegeBack = i18n::pl::PRESS_RETURN_TO_BACK;
	string successfulInput = i18n::pl::SUCCESSFUL_INPUT;
	string wrongIntMsg = i18n::pl::WRONG_INT_MSG;

	COORD firstPos = utils::gotoWriteCenter({ 0, ((ROWS / 3) - 2) }, provideAddressData);
	cout << provideAddressData << endl;

	utils::gotoNextLine(firstPos, 2);

	color = selectedOption == 0 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);
	cout << address;

	utils::gotoRight(utils::gotoNextLine(firstPos, 2), address.size());
	cout << addressPlaceholder;

	utils::gotoNextLine(firstPos, 4);

	color = selectedOption == 1 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);
	cout << date;

	utils::gotoRight(utils::gotoNextLine(firstPos, 4), date.size());
	cout << datePlaceholder;

	utils::gotoNextLine(firstPos, 6);

	color = selectedOption == 2 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);
	cout << hour;

	utils::gotoRight(utils::gotoNextLine(firstPos, 6), hour.size());
	cout << hourPlaceholder;

	COORD secondPos = utils::gotoxy(COLS / 2, ROWS - 5);
	utils::gotoWriteCenter(secondPos, navigationMessegeNext);
	SetConsoleTextAttribute(hConsole, WHITE_COLOR);
	cout << navigationMessegeNext;

	utils::gotoWriteCenter(utils::gotoNextLine(secondPos, 2), navigationMessegeBack);
	cout << navigationMessegeBack;


	switch (key) {
	case KEY_DOWN:
		if (selectedOption < 2) {
			selectedOption++;
		}
		break;
	case KEY_UP:
		if (selectedOption > 0) {
			selectedOption--;
		}
		break;
	case KEY_ESCAPE:
		page = pUsername;
		break;
	case KEY_ENTER:
		if (selectedOption == 0) {
			deliveryData.address = addressPlaceholder;
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 8), successfulInput);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << successfulInput;
			Sleep(1000);
		}
		else if (selectedOption == 1 && stoi(datePlaceholder) <= 50) {
			deliveryData.date = stoi(datePlaceholder);
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 8), successfulInput);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << successfulInput;
			Sleep(1000);
		}
		else if (selectedOption == 1 && stoi(datePlaceholder) > 50){
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 8), wrongIntMsg);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << wrongIntMsg;
			Sleep(1000);
		}
		else if (selectedOption == 2 && stoi(hourPlaceholder) <= 24) {
			deliveryData.hour = stoi(hourPlaceholder);
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 8), successfulInput);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << successfulInput;
			Sleep(1000);
		}
		else if (selectedOption == 2 && stoi(hourPlaceholder) > 24) {
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 8), wrongIntMsg);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << wrongIntMsg;
			Sleep(1000);
		}
		break;
	case BACK_SPACE:
		if (selectedOption == 0 && size(addressPlaceholder) > 0) {
			addressPlaceholder.pop_back();
		}
		else if (selectedOption == 1 && size(datePlaceholder) > 0) {
			datePlaceholder.pop_back();
		}
		else if (selectedOption == 2 && size(hourPlaceholder) > 0) {
			hourPlaceholder.pop_back();
		}
		break;
	default:
		bool isDeliveryDataCompleted = deliveryData.address != "" && deliveryData.date > 0 && deliveryData.hour > 0;
		bool isValidAddressChar = isalnum(key) || key == KEY_SPACE;
		if (selectedOption == 0 && isValidAddressChar && size(addressPlaceholder) <= ADDRESS_CAP) {
			addressPlaceholder += key;
		}
		else if (selectedOption == 1 && isdigit(key)) {
			datePlaceholder += key;
		}
		else if (selectedOption == 2 && isdigit(key)) {
			hourPlaceholder += key;
		}
		else if (isDeliveryDataCompleted) {
			page = pMenu;
		}
		break;
	}
}
