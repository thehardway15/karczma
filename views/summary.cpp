#include "views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include "../i18n.cpp"

using namespace std;

void views::summary(HANDLE hConsole, int key, Page& page, string& customerName, std::vector<OrderItem>& items, bool& shouldStop) {
	utils::gotoWriteCenter({ 0, 2 }, i18n::pl::SUMMARY);
	cout << i18n::pl::SUMMARY;

	utils::gotoWriteCenter({ 0, 22 }, i18n::pl::SAVE_BILL_TO_FILE);
	cout << i18n::pl::SAVE_BILL_TO_FILE;

	utils::gotoWriteCenter({ 0, 24}, i18n::pl::PRESS_ANY_KEY_TO_EXIT);
	cout << i18n::pl::PRESS_ANY_KEY_TO_EXIT;

	if (key >= 0) {
		shouldStop = true;
	}
}