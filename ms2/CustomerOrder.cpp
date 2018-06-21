#include <vector>
#include <iomanip>

#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"

// char CustomerOrder::delimiter = '|';
size_t CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder(const std::string& record) {
	nOrders = 0;
	order = nullptr;

	size_t next_pos = 0;
	bool more = true;
	std::vector<std::string> tokens;
	Utilities u;

	name = u.nextToken(record, next_pos, more);
	if (more) product = u.nextToken(record, next_pos, more);

	/* extract remaining tokens */
	while (more) tokens.push_back(u.nextToken(record, next_pos, more));

	/* create CustomerItems for each remaining token */
	nOrders = tokens.size();
	order = new CustomerItem[nOrders];
	for (std::vector<int>::size_type i = 0; i<nOrders; i++) {
		order[i] = CustomerItem(tokens[i]);
	}

	field_width = field_width < u.getFieldWidth() ? u.getFieldWidth() : field_width;
}

// Since customer orders are not to be duplicated, 
// the copy constructor should never be called.
CustomerOrder::CustomerOrder(const CustomerOrder& customerOrder) {
	throw std::string("Duplication is not not allowed for customerOrder!");
}

CustomerOrder::CustomerOrder(CustomerOrder&& customerOrder) NOEXCEPT { // OSX noexcept
	order = nullptr;
	*this = std::move(customerOrder);
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& customerOrder) NOEXCEPT {
	if (this != &customerOrder) {
		if (order) {
			delete[] order;
			order = nullptr;
			nOrders = 0;
		}

		name = customerOrder.name;
		product = customerOrder.product;
		nOrders = customerOrder.nOrders;
		order = customerOrder.order;

		customerOrder.nOrders = 0;
		customerOrder.order = nullptr;
	}

	return std::move(*this);
}

CustomerOrder::~CustomerOrder() {
	if (order) {
		delete[] order;
		order = nullptr;
		nOrders = 0;
	}
}

unsigned int CustomerOrder::noOrders() const {
	return nOrders;
}

const std::string& CustomerOrder::operator[](unsigned int i) const {
	if (nOrders <= i) throw std::string("index is out of bounds");
	return order[i].getName();
}

void CustomerOrder::fill(Item& item) {
	for (unsigned int i = 0; i<nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			order[i].fill(item.getCode());
			item++;
		}
	}
}

void CustomerOrder::remove(Item& item) {
	for (unsigned int i = 0; i<nOrders; i++) {
		if (order[i].getName() == item.getName()) order[i].clear();
	}
}

bool CustomerOrder::empty() const {
	return name.empty();
}

void CustomerOrder::display(std::ostream& os) const {
	os << std::left << std::setfill(' ') << std::setw(field_width) << name <<
		" : " <<
		std::left << std::setfill(' ') << std::setw(field_width) << product <<
		std::endl;
	for (unsigned int i = 0; i<nOrders; i++) {
		order[i].display(os);
	}
}
