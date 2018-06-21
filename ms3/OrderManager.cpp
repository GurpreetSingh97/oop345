#include <iostream>
#include <vector>
#include "OrderManager.h"
#include "ItemManager.h"
#include "CustomerOrder.h"

using namespace std;



//CustomerOrder&& OrderManager::extract() {
//	CustomerOrder a;
//	return move(a);
//}

void OrderManager::validate(const ItemManager& item, std::ostream& os) {
	
	for (size_t i = 0; i < vector<CustomerOrder>::size(); i++) { 
		for (size_t j = 0; j < vector<CustomerOrder>::at(i).noOrders(); j++) { 
			for (size_t k = 0; k < item.size(); k++) {

				if (vector<CustomerOrder>::at(i)[j] == item.at(k).getName()) {
					break;
				}
				if (k == item.size() - 1) {
				cout << vector<CustomerOrder>::at(i)[j] << " is unavailable." << endl;
				}  
			}
		}

	}

}



void OrderManager::display(std::ostream& os) const {
	for (size_t i = 0; i < vector<CustomerOrder>::size(); i++) {
		vector<CustomerOrder>::at(i).display(os);
	}
}