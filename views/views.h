#include "../config.h"
#include <Windows.h>

namespace views 
{
	void menu(HANDLE hConsole, int key, int& selectedMenu, Page& page);
	void author(HANDLE hConsole, int key, Page& page);
}