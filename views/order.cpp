#include "views.h"
#include "../config.h"
#include "../utils.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "../i18n.cpp"

void views::order(HANDLE hConsole, int key, int& selectedOption, vector<OrderItem>& orderItems, Page& page, OrderItem& selectedItem) {
	switch (key) {
	case KEY_UP:
		selectedOption--;
		if (selectedOption < 1)
			selectedOption = 1;
		break;
	case KEY_DOWN:
		selectedOption++;
		if (selectedOption > orderItems.size() + 1)
			selectedOption = orderItems.size() + 1;
		break;
	case KEY_ESCAPE:
		page = pUsername;
		break;
	case KEY_ENTER:
		if (selectedOption == orderItems.size() + 1) {
			page = pSummary;
		} else {
			selectedItem = orderItems[selectedOption - 1];
			page = pFoodDetails;
		}
		break;
	default:
		break;
	}

	SetConsoleTextAttribute(hConsole, WHITE_COLOR);

	COORD firstPos = utils::gotoWriteCenter({ 0, 2 }, i18n::pl::RESTAURANT_MENU);
	std::cout << i18n::pl::RESTAURANT_MENU;

	utils::gotoxy(4, 4);
	std::cout << i18n::pl::FOOD_NAME;

	utils::gotoxy(33, 4);
	std::cout << "|";

	utils::gotoxy(47, 4);
	std::cout << i18n::pl::PRICE;

	utils::gotoxy(66, 4 );
	std::cout << "|";


	utils::gotoxy(88, 4);
	std::cout << i18n::pl::QUANTITY;


	for (int i = 3; i <= 95; i++) {
		utils::gotoxy(i, 5);
		std::cout << "_";
	}

	int i = 0;
	for (auto & item: orderItems) {
		int color = WHITE_COLOR;
		color = selectedOption - 1 == i ? RED_COLOR : WHITE_COLOR;
		SetConsoleTextAttribute(hConsole, color);
	
		utils::gotoxy(4, 7 + i);
		std::cout << item.name;


		utils::gotoxy(33, 7 + i);
		std::cout << "|";


		utils::gotoxy(48, 7 + i);
		std::cout << item.price;

		utils::gotoxy(66, 7 + i);
		std::cout << "|";

		utils::gotoxy(90, 7 + i);
		std::cout << item.quantity;

		i++;
	}

	int color = WHITE_COLOR;
	color = selectedOption == orderItems.size() + 1 ? RED_COLOR : WHITE_COLOR;
	SetConsoleTextAttribute(hConsole, color);

	utils::gotoWriteCenter({ 50, 20 }, i18n::pl::MAKE_ORDER);
	std::cout << i18n::pl::MAKE_ORDER;

	SetConsoleTextAttribute(hConsole, WHITE_COLOR);

	utils::gotoxy(78, 23);
	std::cout << i18n::pl::TOTAL;
	utils::gotoxy(86, 24);
	std::cout<< 0 << i18n::pl::CURRENCY;

	utils::gotoWriteCenter({50, 25 }, i18n::pl::PRESS_ESC_TO_GO_BACK);
	std::cout << i18n::pl::PRESS_ESC_TO_GO_BACK;
}
