#include "../config.h"
#include <Windows.h>
#include <vector>
#include "../utils.h"
#include "../models/orderItem.cpp"

namespace views 
{
	void menu(HANDLE hConsole, int key, int& selectedMenu, Page& page, int& selectedOption);
	void author(HANDLE hConsole, int key, Page& page);
	void order(HANDLE hConsole, int key, int& selectedOption, std::vector<OrderItem> orders, Page& page, OrderItem& selectedItem);
	void foodDetails(HANDLE hConsole, int key, Page& page, OrderItem order);
	void username(HANDLE hConsole, int key, string& customerName, Page& page);
}