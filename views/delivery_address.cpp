#include <conio.h>
#include <iostream>
#include "../views/views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include <string>
#include "../i18n.cpp"

using namespace std;

void views::deliveryAddress(HANDLE hConsole, int key, Page& page, DeliveryStruct& deliveryData,
	int& addressChoiceSelectedOption, string& addressPlaceholder, string& datePlaceholder, string& hourPlaceholder) {
	
	int color;
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

	color = addressChoiceSelectedOption == 0 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);
	cout << address;

	utils::gotoRight(utils::gotoNextLine(firstPos, 2), address.size());
	cout << addressPlaceholder;

	utils::gotoNextLine(firstPos, 4);

	color = addressChoiceSelectedOption == 1 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);
	cout << date;

	utils::gotoRight(utils::gotoNextLine(firstPos, 4), date.size());
	cout << datePlaceholder;

	utils::gotoNextLine(firstPos, 6);

	color = addressChoiceSelectedOption == 2 ? RED_COLOR : WHITE_COLOR;
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
		if (addressChoiceSelectedOption < 2) {
			addressChoiceSelectedOption++;
		}
		break;
	case KEY_UP:
		if (addressChoiceSelectedOption > 0) {
			addressChoiceSelectedOption--;
		}
		break;
	case KEY_ESCAPE:
		page = pUsername;
		break;
	case KEY_ENTER: {
		string errorMessage = "";
		if (addressPlaceholder.size() == 0) {
			errorMessage = i18n::pl::EMPTY_ADDRESS;
		} else if (datePlaceholder.size() == 0 || stoi(datePlaceholder) > 50) {
			errorMessage = i18n::pl::WRONG_DATE;
		} else if (hourPlaceholder.size() == 0 || stoi(hourPlaceholder) > 24) {
			errorMessage = i18n::pl::WRONG_HOUR;
		}

		if (errorMessage.size() > 0) {
			utils::gotoWriteCenter(utils::gotoNextLine(firstPos, 8), errorMessage);
			SetConsoleTextAttribute(hConsole, RED_COLOR);
			cout << errorMessage;
			Sleep(1000);
		} else {
			deliveryData.address = addressPlaceholder;
			deliveryData.date = stoi(datePlaceholder);
			deliveryData.hour = stoi(hourPlaceholder);
			page = pOrder;
		}
		break;
	}
	case BACK_SPACE:
		if (addressChoiceSelectedOption == 0 &&  addressPlaceholder.size() > 0) {
			addressPlaceholder.pop_back();
		}
		else if (addressChoiceSelectedOption == 1 && datePlaceholder.size() > 0) {
			datePlaceholder.pop_back();
		}
		else if (addressChoiceSelectedOption == 2 && hourPlaceholder.size() > 0) {
			hourPlaceholder.pop_back();
		}
		break;
	default:
		bool isValidAddressChar = isalnum(key) || key == KEY_SPACE;
		if (addressChoiceSelectedOption == 0 && isValidAddressChar && addressPlaceholder.size() <= ADDRESS_CAP) {
			addressPlaceholder += key;
		}
		else if (addressChoiceSelectedOption == 1 && isdigit(key)) {
			datePlaceholder += key;
		}
		else if (addressChoiceSelectedOption == 2 && isdigit(key)) {
			hourPlaceholder += key;
		}
		break;
	}
}
