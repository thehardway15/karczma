#include "views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include "../i18n.cpp"

using namespace std;

void views::restaurantDetails(HANDLE hConsole, int key, Page &page, const RestaurantDetails& details) {
    if (key == KEY_ESCAPE)
		page = pMenu;


	string header = i18n::pl::RESTAURANT_DETAILS;
	COORD firstPos = utils::gotoWriteCenter({ 0, ((ROWS / 2) - 2) }, header);
	cout << header;
	utils::gotoNextLine(firstPos, 1);
	cout << details.name;

	utils::gotoNextLine(firstPos, 2);
	cout << details.location;

	utils::gotoNextLine(firstPos, 3);
	cout << details.creationDate;


	utils::gotoWriteCenter({50,25}, i18n::pl::PRESS_ESC_TO_GO_BACK);
	cout << i18n::pl::PRESS_ESC_TO_GO_BACK;
}