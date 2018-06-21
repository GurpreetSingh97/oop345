#include <iomanip>
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"

CustomerItem::CustomerItem(const std::string& s /*= std::string()*/) {
	filled = false;
	code = 0;
	name = s;
}

bool CustomerItem::asksFor(const Item& item) const {
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
	os << " " << (filled ? '+' : '-') << " " <<
		"[" << std::right << std::setfill('0') << std::setw(CODE_WIDTH) << code << "] " <<
		name << std::endl;
}