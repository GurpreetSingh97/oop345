#pragma once
// Task Milestone - Task Interface
// Task.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

class Task {
	std::string name;          // name of the task
	std::string slots;         // number of slots
	std::string nextTask[2];   // names of the next tasks
	const Task* pNextTask[2];  // addresses of the next tasks
	static size_t field_width; // current maximum field width
public:
	/*! Enum for types of tasks*/
	enum Quality {
		passed,
		redirect
	};
	/*! Constructor with one parameter*/
	Task(const std::string&);

	/*! Validates a task*/
	bool validate(const Task&);

	/*! Returns name of the task*/
	const std::string& getName() const;

	/*! Returns the number of the slots of the task*/
	unsigned int getSlots() const;

	/*! Returns the address of the next task*/
	const Task* getNextTask(Quality) const;
	
	/*! Displays data on the output stream*/
	void display(std::ostream&) const;

	/*! Returns the field width*/
	static size_t getFieldWidth();
};

bool operator==(const Task&, const Task&);
