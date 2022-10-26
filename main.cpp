#include "utils.h"
#include "config.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <Windows.h>
#include <conio.h>
#include "./views/views.h"
#include "./i18n.cpp"

using namespace std;

atomic_bool stop(false);

Page page = pMenu;

void loop() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int selectedMenu = 0; // 0 - Info, 1 - Zamowienie, 2 - Autorzy
	int key = NULL_CHAR;

	utils::drawBox(COLS, ROWS, '#');

	while(!stop) {
		utils::clearContent();

		switch (page) {
		case pMenu:  views::menu(hConsole, key, selectedMenu, page); break;
		case pAuthor: views::author(hConsole, key, page); break;
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
