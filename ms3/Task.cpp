#include <iostream>
#include <string>

#include <iomanip>
#include "Task.h"
#include "Utilities.h"

using namespace std;

size_t Task::field_width=0;

Task::Task(const std::string& rec) {
	slots = "1";

	pNextTask[passed] = nullptr;
	pNextTask[redirect] = nullptr;

	size_t next_pos = 0;
	bool more = true;
	Utilities obj;

	name = obj.nextToken(rec, next_pos, more);
	if (more) {
		slots = obj.nextToken(rec, next_pos, more);
	}
	if (more) {
		nextTask[passed] = obj.nextToken(rec, next_pos, more);
	}
	if (more) {
		nextTask[redirect] = obj.nextToken(rec, next_pos, more);
	}
	field_width = obj.getFieldWidth();
}


bool Task::validate(const Task& task) {
	if (task.name == nextTask[passed]) {
		pNextTask[passed] = &task;
	}
	else if (task.name == nextTask[redirect]) {
		pNextTask[redirect] = &task;
	}

	return (nextTask[passed].empty() || pNextTask[passed]) && (nextTask[redirect].empty() || pNextTask[redirect]);
}

const std::string& Task::getName() const {
	return name;
}

unsigned int Task::getSlots() const {
	return stoi(slots);
}

const Task* Task::getNextTask(Quality quality) const {
	if (pNextTask[quality] == nullptr) {
		throw "*** Validate [" + nextTask[quality] + "] @ [" + name + "] ***";
	}
	return pNextTask[quality];
}


size_t Task::getFieldWidth() {
	return field_width;
}

bool operator==(const Task& task_a, const Task& task_b) {
	bool answer = false;
	if (task_a == task_b) {
		answer = true;
	}
	return answer;
}


void Task::display(std::ostream& os) const {

	os << "Task Name    : " << setfill(' ') << setw(20) << std::left << "[" + name + "]" << "[" << slots << "]" << endl;

	if (!nextTask[passed].empty()) {
		os << " Continue to : " << setfill(' ') << setw(20) << std::left << "[" + nextTask[passed] + "]";
	
		if (pNextTask[passed] == nullptr) {
			os << " *** to be validated ***";
		}

		os << endl;
	}

	if (!nextTask[redirect].empty()) {

		os << " Redirect to : " << setfill(' ') << setw(20) << std::left << "[" + nextTask[redirect] + "]";
		
		if (pNextTask[redirect] == nullptr) {
			os << " *** to be validated ***";
		}
		os << endl;
	}
}