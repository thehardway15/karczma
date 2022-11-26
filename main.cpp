#include "utils.h"
#include "config.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "./views/views.h"
#include "./i18n.cpp"
#include <string>

using namespace std;

bool stop(false);

Page page = pMenu;

DeliveryStruct deliveryData{ "", 0, 0 };

string customerName = "";
string addressPlaceholder = "";
string datePlaceholder = "";
string hourPlaceholder = "";
string tablePlaceholder = "";
int table = 0;

void loop() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int selectedMenu = 0; // 0 - Info, 1 - Nowe Zamowienie, 2 - Autorzy
	int selectedOption = 1;
	int deliveryChoiceSelectedOption = 0;
	int addressChoiceSelectedOption = 0;
	int key = NULL_CHAR;
	OrderItem selectedOrderItem;

	vector<OrderItem> orderItems = utils::readOrderItems();
    RestaurantDetails details = utils::readRestaurantDetails();

    utils::drawBox(COLS, ROWS, '#');

	while(!stop) {
		utils::clearContent();

		switch (page) {
		case pMenu:  views::menu(hConsole, key, selectedMenu, page, selectedOption); break;
		case pAuthor: views::author(hConsole, key, page); break;
		case pUsername: views::username(hConsole, key, customerName, page); break;
		case pOrder: views::order(hConsole, key, selectedOption, orderItems, page, selectedOrderItem); break;
		case pFoodDetails: views::foodDetails(hConsole, key, page, selectedOrderItem); break;
		case pDeliveryChoice: views::deliveryChoice(hConsole, key, page, deliveryChoiceSelectedOption); break;
		case pDeliveryAddress: views::deliveryAddress(hConsole, key, page, deliveryData, addressChoiceSelectedOption,
			addressPlaceholder, datePlaceholder, hourPlaceholder); break;
		case pTableChoice: views::tableChoice(hConsole, key, page, table, tablePlaceholder); break;
		case pSummary: views::summary(hConsole, key, page, customerName, orderItems, stop, table, deliveryData); break;
        case pRestaurantDetails: views::restaurantDetails(hConsole, key, page, details); break;
		}

		SetConsoleTextAttribute(hConsole, WHITE_COLOR);
		utils::gotoWriteCenter({ 0 ,ROWS }, i18n::pl::PRESS_F4_TO_QUIT);
		cout << i18n::pl::PRESS_F4_TO_QUIT;

		key = utils::getch_noblock();
		
		if (key == KEY_EXIT)
			stop = true;

		Sleep(100);
	}
}



int main()
{
	thread t(loop);
	t.join();

	while (true)
		if (stop)
			break;
			
	return EXIT_SUCCESS;
}
