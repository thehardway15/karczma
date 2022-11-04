#include "views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include "../i18n.cpp"

using namespace std;

void views::foodDetails(HANDLE hConsole, int key, Page& page, OrderItem orderItem) {
	if (key == KEY_ESCAPE)
		page = pOrder;

	utils::gotoWriteCenter({ 50, 2 }, orderItem.name);
	std::cout << orderItem.name;

	utils::gotoxy(30, 5);
	std::cout << i18n::pl::INGREDIENTS;

	int i = 0;
	COORD lastPos;

	for (auto& item : orderItem.ingredients) {
		lastPos = utils::gotoxy(30, 7 + i);
		std::cout << item;
		i++;
	}
	
	utils::gotoxy(60, 5);
	std::cout << i18n::pl::PREPARATION_TIME;

	utils::gotoxy(60, 7);
	std::cout << orderItem.preparationTime << "h";

	utils::gotoWriteCenter({ lastPos.X, lastPos.Y + 2 }, i18n::pl::DESCRIPTION);
	std::cout << i18n::pl::DESCRIPTION;


	utils::gotoWriteCenter({ lastPos.X, lastPos.Y + 4 }, orderItem.description);
	std::cout << orderItem.description;

	

	utils::gotoWriteCenter({ 50,25 }, i18n::pl::PRESS_ESC_TO_GO_BACK);
	std::cout << i18n::pl::PRESS_ESC_TO_GO_BACK;
}