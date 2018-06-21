#include<iostream>
#include <vector>
#include <iomanip>
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"

using namespace std;

size_t CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder(const std::string& str) {
	nOrders = 0;
	order = nullptr;

	size_t next_pos = 0;
	bool more = true;
	Utilities obj;

	vector<string> array;
	
	name = obj.nextToken(str, next_pos, more);
	if (name.empty()) {
		throw std::string(" No Name could be extracted!!! ");
	}

	if (more == true) {
		product = obj.nextToken(str, next_pos, more);
	}

	while (more == true) {
		array.push_back(obj.nextToken(str, next_pos, more));
	}

	nOrders = array.size();
	
	order = new CustomerItem[nOrders];
	
	for (vector<int>::size_type i = 0; i < nOrders; i++) {
		order[i] = CustomerItem(array[i]);
	}

	if (field_width < obj.getFieldWidth()) {
		field_width = obj.getFieldWidth();
	}

}


CustomerOrder::CustomerOrder(const CustomerOrder& customerOrder) {
	throw std::string("Error, Copy Constructor can not be called!!!");
}

CustomerOrder::CustomerOrder(CustomerOrder&& customerOrder) NOEXCEPT { 
	
	order = nullptr;
	*this = move(customerOrder);
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& customerOrder) NOEXCEPT {
	if (this != &customerOrder) {
		
		//same as destructor
		if (order) {
			delete[] order;
			order = nullptr;
			nOrders = 0;
		}

		name = customerOrder.name;
		product = customerOrder.product;
		order = customerOrder.order;
		nOrders = customerOrder.nOrders;
		customerOrder.nOrders = 0;

		customerOrder.order = nullptr;
	}
	return move(*this);
}

CustomerOrder::~CustomerOrder() {
	
	if (order) {
		delete[] order;
		order = nullptr;
		nOrders = 0;
		
	}
}


bool CustomerOrder::empty() const {
	bool answer = false;
	if (name.empty() == true) {
		answer = true;
	}
	return answer;
}

unsigned int CustomerOrder::noOrders() const {
	return nOrders;
}

const std::string& CustomerOrder::operator[](unsigned int i) const {
	if (nOrders <= i) {
		throw std::string("Index out of bound!!!");
	}

	return order[i].getName();
}

void CustomerOrder::fill(Item& item) {
	for (unsigned int i = 0; i < nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			order[i].fill(item.getCode());
			//
			item++;
		}
	}
}

void CustomerOrder::remove(Item& item) {
	for (unsigned int i = 0; i < nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			order[i].clear();
		}
	}
}



void CustomerOrder::display(std::ostream& os) const {
	os << std::left << std::setfill(' ') << std::setw(field_width) << name << " : " << std::left << std::setfill(' ') << std::setw(field_width) << product << endl;
	
	for (unsigned int i = 0; i <nOrders ; i++) {
		//order[].display(os);
		order[i].display(os);
	}

}
