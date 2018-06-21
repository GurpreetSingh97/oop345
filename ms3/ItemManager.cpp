#include <iostream>
#include <vector>
#include "ItemManager.h"

using namespace std;

void ItemManager::display(std::ostream& os, bool boolean) const {
	
	for (size_t i = 0; i <vector<Item>::size(); i++) {
		vector<Item>::at(i).display(os);
	}
}