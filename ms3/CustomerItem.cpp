#include <iomanip>
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"
#include <string>


using namespace std;
CustomerItem::CustomerItem(const std::string& str) {
	filled = false;
	code = 0;
	if (str.empty()) {
		name = "";
	}
	else {
		name = str;
	}
}

bool CustomerItem::asksFor(const Item& item) const {
	bool answer = false;
	if (name == item.getName()) {
		answer = true;
	}
		return true;
}

bool CustomerItem::isFilled() const {
	return filled;
}

void CustomerItem::fill(const unsigned int c) {
	code = c;
	filled = true;
}

void CustomerItem::clear() {
	code = 0;
	filled = false;
}

const std::string& CustomerItem::getName() const {
	return name;
}

void CustomerItem::display(std::ostream& os) const {
	
	os << " ";
	if (filled) {
		os << '+';
	}
	else {
		os << '-';
	}
	os << " " << "[" << std::right << std::setfill('0') << std::setw(CODE_WIDTH) << code << "] " << name << endl;
}