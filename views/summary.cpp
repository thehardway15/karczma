#include "views.h"
#include "../config.h"
#include "../utils.h"
#include <Windows.h>
#include "../i18n.cpp"
#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;

void views::summary(HANDLE hConsole, int key, Page& page, string& customerName, std::vector<OrderItem>& items, bool& shouldStop, int& table, DeliveryStruct& deliveryData) {
	SetConsoleTextAttribute(hConsole, WHITE_COLOR);
	int price = 0;

    ofstream outfile("order-"+ customerName +".txt");

	std::vector<OrderItem> orderItems;
	for (const auto& item : items) {
		if (item.quantity > 0) {
			orderItems.push_back(item);
			price = price + (item.quantity * item.price);
		}
	}

	utils::gotoWriteCenter({ 0, 2 }, i18n::pl::SUMMARY);
	cout << i18n::pl::SUMMARY;

	for (int i = 30; i <= 70; i++) {
		utils::gotoxy(i, 5);
		std::cout << "_";
	}

	int i = 0;
	for (auto& item : orderItems) {
		utils::gotoxy(30, 7 + i);
		std::cout << "|";
		utils::gotoxy(32, 7 + i);
		std::cout << item.name;

		utils::gotoxy(50, 7 + i);
		std::cout << "|";

		utils::gotoxy(52, 7 + i);
		std::cout << item.price << i18n::pl::CURRENCY;

		utils::gotoxy(60, 7 + i);
		std::cout << "|";

		utils::gotoxy(62, 7 + i);
		std::cout << item.quantity << "x";

		utils::gotoxy(70, 7 + i);
		std::cout << "|";

        outfile << "|";
        outfile << item.name;
        outfile << "|";

        outfile << item.price << i18n::pl::CURRENCY;
        outfile << "|";

        outfile << item.quantity << "x" << std::endl;
        outfile << std::endl;

		i++;
	}

	short lastPostionY = 7 + orderItems.size();

	for (int i = 30; i <= 70; i++) {
		utils::gotoxy(i, lastPostionY);
		std::cout << "_";
	}

	lastPostionY += 3;

    outfile << "-----------------------" <<std::endl;

	if (table > 0) {
		utils::gotoWriteCenter({ 0, lastPostionY }, i18n::pl::DELIVERY_TO_TABLE);
		cout << i18n::pl::DELIVERY_TO_TABLE;
		lastPostionY += 1;
		string tableText = i18n::pl::TABLE_NUMBER + std::to_string(table);
		utils::gotoWriteCenter({ 0, lastPostionY}, tableText);
		cout << tableText;

        outfile << tableText <<std::endl;


    }
	else {
		string address = i18n::pl::ADDRESS + deliveryData.address;
		utils::gotoWriteCenter({ 0, lastPostionY }, address);
		std::cout << address;

        outfile << address <<std::endl;

		lastPostionY += 1;

		string date = i18n::pl::SUMMARY_DATE + std::to_string(deliveryData.date);
		utils::gotoWriteCenter({ 0, lastPostionY }, date);
		std::cout << date;

        outfile << date << std::endl;

		lastPostionY += 1;

		string hour = i18n::pl::SUMMARY_HOUR + std::to_string(deliveryData.hour);
		utils::gotoWriteCenter({ 0, lastPostionY }, hour);
		std::cout << hour;

        outfile << hour<< std::endl;
	}

	lastPostionY += 3;

	SetConsoleTextAttribute(hConsole, GREEN_COLOR);

	string total = i18n::pl::SUMMARY_TOTAL_PAY + std::to_string(price) + " " + i18n::pl::CURRENCY;

	utils::gotoWriteCenter({ 0, lastPostionY}, total);
	std::cout << total;

    outfile << total<< std::endl;

    SetConsoleTextAttribute(hConsole, WHITE_COLOR);

	utils::gotoWriteCenter({ 0, 22 }, i18n::pl::SAVE_BILL_TO_FILE);
	cout << i18n::pl::SAVE_BILL_TO_FILE;

	utils::gotoWriteCenter({ 0, 24}, i18n::pl::PRESS_ANY_KEY_TO_EXIT);
	cout << i18n::pl::PRESS_ANY_KEY_TO_EXIT;

    outfile.close();

	if (key >= 0) {
		shouldStop = true;
	}
}