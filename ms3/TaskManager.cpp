#include <algorithm>
#include <vector>


#include "Task.h"
#include "TaskManager.h"
#include "ItemManager.h"

using namespace std;

void TaskManager::validate(std::ostream& os) {
	
	for(size_t i = 0; i <vector<Task>::size(); i++) {
		for(size_t j = 0; j <vector<Task>::size(); j++) {
			if(i!=j) {  
				vector<Task>::at(i).validate(vector<Task>::at(j));
			}
		}
	}
}


void TaskManager::validate(const ItemManager& item, std::ostream& os) {
	int i = 0;

	for (size_t i = 0; i < item.size(); i++) {
		for (size_t k = 0; k < vector<Task>::size(); k++) {
			if (item.at(i).getName() == vector<Task>::at(k).getName()) {
				break;
			} 
			if (i == vector<Task>::size() - 1) {
				os << item.at(i).getName() << " is unavailable." << endl;
			}
		}
	}


	for (size_t j = 0; j < item.size(); j++) {
		for (size_t k = 0; k < vector<Task>::size(); k++) {
			if (item.at(j).getRemover() == vector<Task>::at(k).getName()) {
				break;
			}  
			if (k == vector<Task>::size() - 1) {
				os << item.at(j).getRemover() << " is unavailable." << endl;
			} 
		}
	}
}



void TaskManager::display(std::ostream& os) const {
	for (size_t i = 0; i < vector<Task>::size(); i++) {
		vector<Task>::at(i).display(os);
	}
}
