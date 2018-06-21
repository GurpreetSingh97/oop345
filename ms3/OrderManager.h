#pragma once
// Manager Milestone - OrderManager Interface
// OrderManager.h
// Chris Szalwinski
// v1.0 - 14/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <vector>

class ItemManager;
class CustomerOrder;

class OrderManager : public std::vector<CustomerOrder> {
public:

	/*!
	This funcrion moves a customerOrder from back of the class container
	*/
	CustomerOrder&& extract();

	/*!
	This function validates whether the item ordered by the customer is available or not.
	If not puts a message in the os object.
	*/
	void validate(const ItemManager&, std::ostream&);

	/*!
	This function inserts the description of each customer order in the base class container
	*/
	void display(std::ostream&) const;
};