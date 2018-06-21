#pragma once
// Task Milestone - Task Interface
// Task.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>



/*!
Task class that conatins the name, the number of the slots of the task.
It also contains the name and the pointer to the next task.
*/
class Task {
	std::string name;          // name of the task
	std::string slots;         // number of slots
	std::string nextTask[2];   // names of the next tasks
	const Task* pNextTask[2];  // addresses of the next tasks
	static size_t field_width; // current maximum field width 
public:
	enum Quality {
		passed,
		redirect
	};


	/*!
	The Constructor of the task class the initalises the member variables
	It also extract the token from the string using the utilities class object and 
	if the field width needed by the extracted token is greater than field_width
	then it resets it value to the retreived value.
	*/
	Task(const std::string&);
	

	/*!
	This function validates the next task by matching their name to the
	given "task"
	If the name matches, it stores the address of the "task" in the pointer
	to the next task.
	*/
	bool validate(const Task&);


	/*!
	This function returns the name of the task
	*/
	const std::string& getName() const;


	/*!
	This function returns the "slots" string sfter converting it into an integer 
	*/
	unsigned int getSlots() const;


	/*!
	This function returns the address of the Next Task associated with the given parameter
	and reports an exception if the pointer to it is nullptr
	*/
	const Task* getNextTask(Quality) const;


	/*!
	Put all the inforamtion about the task into the "os" object, which varies on whether the
	task has been validated or not.
	*/
	void display(std::ostream&) const;


	/*!
	Return the field width associated with the current task
	*/
	static size_t getFieldWidth();
};


/*!
This function returns true if both the given task have the same name otherwise false 
*/
bool operator==(const Task&, const Task&);