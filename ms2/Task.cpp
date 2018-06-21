/*
OOP 345 MILESTONE 1
Task.cpp
Niral Parmar
146824164
*/

#include <iomanip>
#include "Task.h"
#include "Utilities.h"

size_t Task::field_width = 0;

Task::Task(const std::string& record)
{
	// Safe State
	slots = "1";
	pNextTask[passed] = nullptr;
	pNextTask[redirect] = nullptr;

	size_t next_pos = 0;
	bool more = true;
	Utilities utility;

	// Stores each token
	for (int i = 0; more && i <=3 ; i++)
	{
		switch (i)
		{
		case 0:
			name = utility.nextToken(record, next_pos, more);
			break;
		case 1:
			slots = utility.nextToken(record, next_pos, more);
			break;
		case 2:
			nextTask[passed] = utility.nextToken(record, next_pos, more);
			break;
		case 3:
			if (more) nextTask[redirect] = utility.nextToken(record, next_pos, more);
			break;
		}
	}

	// Set Field Width
	field_width = utility.getFieldWidth();
}

const std::string& Task::getName() const
{
	return name;
}

unsigned int Task::getSlots() const
{
	// Converts string to int
	return std::stoi(slots);
}

bool Task::validate(const Task& task)
{
	if (task.name == nextTask[passed]) pNextTask[passed] = &task;
	else if (task.name == nextTask[redirect]) pNextTask[redirect] = &task;

	return (nextTask[passed].empty() || pNextTask[passed]) && (nextTask[redirect].empty() || pNextTask[redirect]);
}

const Task* Task::getNextTask(Quality quality) const
{
	if (pNextTask[quality] == nullptr) throw "*** Validate  [" + nextTask[quality] + "] @ [" + name + "] ***";
	return pNextTask[quality];
}

void Task::display(std::ostream& os) const
{
	os      << "Task Name    : "
		<< std::setfill(' ') << std::setw(15) << std::left << "[" + name + "]"
		<< "[" << slots << "]" << std::endl;

	if (!nextTask[passed].empty())
	{
		os      << " Continue to : "
			<< std::setfill(' ') << std::setw(15) << std::left << "[" + nextTask[passed] + "]";

		if (pNextTask[passed] == nullptr) os << " *** to be validated ***";

		os      << std::endl;
	}

	if (!nextTask[redirect].empty())
	{
		os      << " Redirect to : "
			<< std::setfill(' ') << std::setw(15) << std::left << "[" + nextTask[redirect] + "]";

		if (pNextTask[redirect] == nullptr) os << " *** to be validated ***";

		os << std::endl;
	}
}

size_t Task::getFieldWidth()
{
	return field_width;
}

bool operator==(const Task& task_a, const Task& task_b)
{
	return task_a.getName() == task_b.getName();
}
