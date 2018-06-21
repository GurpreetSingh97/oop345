#pragma once
// CustomerOrder Milestone - Item Interface
// Item.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

const unsigned int CODE_WIDTH = 5;

class Item {
	std::string name;          // name of the component
	std::string filler;        // name of the filler task
	std::string remover;       // name of the remover task 
	std::string description;   // detailed description
	unsigned int code;         // next shipping label
	static size_t field_width; // current maximum field width
public:
	/*!
	Constructor for the Item file, which initialises it "code" and "description" member variable to safe empty state 
	and initialise others member variables from the information extracted from the given string.
	*/
	Item(const std::string& = std::string());


	/*!
	return true if the object is in safe empty state
	*/
	bool empty() const;


	/*!
	increment the code member variable and returns it value
	*/
	int operator++(int);


	/*!
	return the code to be printed on the next insertion
	*/
	unsigned int getCode() const;


	/*!
	returns the names of the item
	*/
	const std::string& getName() const;


	/*!
	returns the name of the task that insert the item into a product
	*/
	const std::string& getFiller() const;


	/*!
	returns the name of the task that extract the item from a product
	*/
	const std::string& getRemover() const;


	/*!
	The display function which puts the name, code, remover, filler and the detailed description
	into the ostream object for the purpose of display
	*/
	void display(std::ostream&, bool = false) const;
};
