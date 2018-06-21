#pragma once
// Manager Milestone - TaskManager Interface
// TaskManager.h
// Chris Szalwinski
// v1.0 - 14/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <vector>

class Task;
class ItemManager;

class TaskManager : public std::vector<Task> {
public:
	/*!
	This function validates all the objects with all the other objects in the class and 
	puts a message into the ostream object if all the tasks have been not validated
	*/
	void validate(std::ostream&);

	/*!
	This function validates whether the task assigned to carry out each item by ItemManager
	are tasks in the base class. If not then it puts a message into the os object.
	*/
	void validate(const ItemManager&, std::ostream&);
	
	/*!
	This fuction puts the description of the task into the iostream object from The "tasks"
	*/
	void display(std::ostream&) const;
};