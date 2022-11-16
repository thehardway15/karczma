#include <string>
#include <vector>

using namespace std;

struct OrderItem {
	int id;
	int quantity;
	int maxQuantity;
	int price;
	string name;
	vector<string> ingredients;
	string description;
	int preparationTime;
};