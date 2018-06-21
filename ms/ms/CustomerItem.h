#pragma once
// CustomerOrder Milestone - CustomerItem Interface
// CustomerItem.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

class Item;

class CustomerItem {
	std::string name;  // name of the requested component 
	bool filled;       // status of the request
	unsigned int code; // unique shipping label
public:
	/*!
	Constructor that initialises the value of name filled and item_code
	*/
	CustomerItem(const std::string& = std::string());


	/*!
	This function returns true if the object asks for a item otherwise false
	*/
	bool asksFor(const Item&) const;
	
	
	/*!
	Return true if the object's request has been filled otherwise false
	*/
	bool isFilled() const;


	/*!
	Fill Function, it sets the code value to the given integer and change the status of object
	to filled
	*/
	void fill(const unsigned int);


	/*!
	This function clear the value of code and put it equal to 0
	and change the status of object to not filled, i.e False
	*/
	void clear();


	/*!
	This function returns the name of the object
	*/
	const std::string& getName() const;


	/*!
	Display function which puts the description and code of the customer's
	item into the ostream object and also the name of the customer
	*/
	void display(std::ostream&) const;
};