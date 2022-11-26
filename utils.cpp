#include "utils.h"
#include "config.h"
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include "include/json.hpp"

using json = nlohmann::json;

using namespace std;

/* Overloading * operator */
string operator * (string a, unsigned int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}

int utils::getch_noblock() {
    if (_kbhit())
        return _getch();
    else
        return -1;
}

void utils::drawBox(int width, int height, char fillChar) {
  utils::clearScreen();

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (i == 0 || i == height - 1)
      {
        cout << fillChar;
      }
      else if (j == 0 || j == width - 1)
      {
        cout << fillChar;
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }
}

void utils::clearContent() {
    for (int i = 1; i < ROWS - 1; i++) {
        utils::gotoxy(1, i);
        string empty = " ";
        cout << (empty * (COLS - 2));
    }
}

void utils::clearScreen() {
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

COORD utils::gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
    return pos;
}

COORD utils::gotoCenter() {
    return utils::gotoxy(COLS / 2, ROWS / 2);
}

COORD utils::gotoNextLine(COORD current, short line) {
    return utils::gotoxy(current.X, current.Y + line);
}

COORD utils::gotoWriteCenter(COORD current, std::string s) {
    return utils::gotoxy((COLS / 2) - (s.size() / 2), current.Y);
}

COORD utils::gotoRight(COORD current, short padding) {
    return utils::gotoxy(current.X + padding, current.Y);
}


//TODO Fix description centering in food details view
vector<OrderItem> utils::readOrderItems(){
    vector<OrderItem> orderItems;

    ifstream f("restaurant_menu.json");
    json data = json::parse(f);

    for (auto & menuItem : data) {
        vector<string> ingredients;
        for(auto & ingredient : menuItem["ingredients"]){
            ingredients.push_back(ingredient);
        }
        OrderItem orderItem = OrderItem {menuItem["id"],menuItem["quantity"],menuItem["maxQuantity"], menuItem["price"],menuItem["name"],
                                         ingredients,menuItem["description"], menuItem["preparationTime"]};
        orderItems.push_back(orderItem);
    }

    return orderItems;
}

RestaurantDetails utils::readRestaurantDetails() {
    ifstream f("restaurant_details.json");
    json data = json::parse(f);

    return RestaurantDetails {data["name"], data["location"], data["creationDate"], data["description"]};
}


