#pragma once
// CustomerOrder Milestone - CustomerOrder Interface
// CustomerOrder.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>
#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

class Item;
class CustomerItem;

class CustomerOrder {
	std::string name;          // name of the customer
	std::string product;       // name of the product
	CustomerItem* order;       // address of the customer requests 
	unsigned int nOrders;      // number of requests
	static size_t field_width; // current maximum field width
public:
	/*!
	Constructor that initalises the value of numberOfCustomerItems to 0,
	the pointer to the CustomerItem array to safe empty state and rest to the
	values that has beem extracted from the given string
	*/
	CustomerOrder(const std::string&);

	/*!
	The copy constructors which is not meant to be called and if by any chance 
	get called, reports an exception
	*/
	CustomerOrder(const CustomerOrder&);



	/*!
		The copy assignment operator for the CustomerOrder class
	*/
	CustomerOrder& operator=(const CustomerOrder&) = delete;


	/*!
	Move constructor for the customerOrder class
	*/
	CustomerOrder(CustomerOrder&&) NOEXCEPT;



	/*!
	The move copy assignment operator for the CustomerOrder class
	*/
	CustomerOrder&& operator=(CustomerOrder&&) NOEXCEPT;


	/*!
	Destructor for the CustomerOrder class, which deallocate all the dynamic memory from the class
	*/
	~CustomerOrder();



	/*!
	This function returns the number of items in the current object
	*/
	unsigned int noOrders() const;


	/*!
	Its returns the reference to name of the customer's item "i" and gives 
	an exception if the index is out of bond
	*/
	const std::string& operator[](unsigned int) const;


	/*!
	Itterate through the customer's item and fills the orders for the customer's
	item that has been identified by the item, if any have not been filled.
	It also increment the value of code, every time it fills the order.
	*/
	void fill(Item&);


	/*!
	Itterate through the customer's item and remove the items that get identified 
	by "item", if the corresponding part of the order has been filled.
	*/
	void remove(Item&);


	/*!
	This function return true if the object is in safe empty state, otherwise false
	*/
	bool empty() const;

	/*!
	The Display function which puts the description and name of the customer's
	order into the iostream object and also the name and item list of the customer
	*/
	void display(std::ostream&) const;
};