#include "views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include "../i18n.cpp"

using namespace std;

void views::resturantDetails(HANDLE hConsole, int key, Page& page) {
	if (key == KEY_ESCAPE)
		page = pMenu;


	string header = i18n::pl::AUTHORS + ":";
	COORD firstPos = utils::gotoWriteCenter({ 0, ((ROWS / 2) - 2) }, header);
	cout << header;
	COORD namedPos = utils::gotoRight(firstPos, -7);
	utils::gotoNextLine(namedPos);
	cout << "1. Damian Wisniewski";

	utils::gotoNextLine(namedPos, 2);
	cout << "2. Dawid Blumczynski";

	utils::gotoNextLine(namedPos, 3);
	cout << "3. Marcin Kaczmarzyk";

	utils::gotoNextLine(namedPos, 4);
	cout << "4. Konrad Molinski";

	utils::gotoWriteCenter({50,25}, i18n::pl::PRESS_ESC_TO_GO_BACK);
	cout << i18n::pl::PRESS_ESC_TO_GO_BACK;
}