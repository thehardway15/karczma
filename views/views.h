#include "../config.h"
#include <Windows.h>
#include <vector>
#include "../utils.h"
#include "../models/deliveryData.cpp"

namespace views 
{
	void menu(HANDLE hConsole, int key, int& selectedMenu, Page& page, int& selectedOption);
	void author(HANDLE hConsole, int key, Page& page);
    void restaurantDetails(HANDLE hConsole, int key, Page& page, const RestaurantDetails& details);
	void order(HANDLE hConsole, int key, int& selectedOption, std::vector<OrderItem>& orders, Page& page, OrderItem& selectedItem);
	void foodDetails(HANDLE hConsole, int key, Page& page, OrderItem order);
	void username(HANDLE hConsole, int key, string& customerName, Page& page);
	void deliveryChoice(HANDLE hConsole, int key, Page& page, int& deliveryChoiceSelectedOption);
	void deliveryAddress(HANDLE hConsole, int key, Page& pag, DeliveryStruct& deliveryData,
		int& addressChoiceSelectedOption, string& addressPlaceholder, string& datePlaceholder, string& hourPlaceholder);
	void tableChoice(HANDLE hConsole, int key, Page& page, int& table);
	void summary(HANDLE hConsole, int key, Page& page, string& customerName, std::vector<OrderItem>& items, bool& shouldStop, int& table, DeliveryStruct& deliveryData);
}