#include <string>
#include <vector>

using namespace std;

struct OrderItem {
	int id;
	int quantity;
	int price;
	string name;
	vector<string> ingridients;
	string description;
	int preparationTime;
};