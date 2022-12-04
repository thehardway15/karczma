#include "views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include "../i18n.cpp"

using namespace std;

void views::restaurantDetails(HANDLE hConsole, int key, Page &page, const RestaurantDetails& details) {
    if (key == KEY_ESCAPE)
		page = pMenu;


    short lastPositionY =  (ROWS / 2);
	string header = i18n::pl::RESTAURANT_DETAILS;
	utils::gotoWriteCenter({ 0, lastPositionY }, header);
    cout << header;

    lastPositionY += 1;
    utils::gotoWriteCenter({ 0, lastPositionY }, details.name);
    cout << details.name;

    lastPositionY += 1;
    utils::gotoWriteCenter({ 0, lastPositionY }, details.location);
	cout << details.location;

    lastPositionY += 1;
    utils::gotoWriteCenter({ 0, lastPositionY }, details.creationDate);
	cout << details.creationDate;

    lastPositionY += 1;
    utils::gotoWriteCenter({ 0, lastPositionY }, details.description);
    cout << details.description;




	utils::gotoWriteCenter({50,25}, i18n::pl::PRESS_ESC_TO_GO_BACK);
	cout << i18n::pl::PRESS_ESC_TO_GO_BACK;
}