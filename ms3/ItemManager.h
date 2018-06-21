#pragma once
// Manager Milestone - ItemManager Interface
// ItemManager.h
// Chris Szalwinski
// v1.0 - 14/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <vector>
#include "Item.h"

class ItemManager : public std::vector<Item> {
public:

	/*!
	Insert the detail about all the items in the iostream object
	*/
	void display(std::ostream&, bool = false) const;
};