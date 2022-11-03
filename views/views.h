#include "../config.h"
#include <iostream>
#include <Windows.h>

namespace views 
{
	void menu(HANDLE hConsole, int key, int& selectedMenu, Page& page);
	void author(HANDLE hConsole, int key, Page& page);
	void username(HANDLE hConsole, int key, std::string& customername, Page& page);
}