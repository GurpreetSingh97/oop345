#include <iomanip>
#include "Item.h"
#include "Utilities.h"

size_t Item::field_width = 0;

/*! Default Constructor*/
Item::Item(const std::string& record) {
	code = 1;

	size_t next_pos = 0;
	bool more = true;
	Utilities u;
	code = 1;
	description = "no detailed description";

	// Stores each token
	for (int i = 0; more && i <= 4; i++)
	{
		switch (i)
		{
		case 0:
			name = u.nextToken(record, next_pos, more);
			if (field_width < name.size()) field_width = name.size();
			break;
		case 1:
			filler = u.nextToken(record, next_pos, more);
			break;
		case 2:
			remover = u.nextToken(record, next_pos, more);
			break;
		case 3:
			code = std::stoi(u.nextToken(record, next_pos, more));
			break;
		case 4:
			description = u.nextToken(record, next_pos, more);
			break;
		default:
			throw std::string("Something went wrong");
		}
	}
}

/*! Returns true if the Item object in safe empty state*/
bool Item::empty() const {
	return name.empty();
}

/*! Returns current code and increments the code*/
int Item::operator++(int) {
	return code++;
}

/*! Returns name of the Item*/
const std::string& Item::getName() const {
	return name;
}

/*! Returns the name of the task that inserts the item into a product*/
const std::string& Item::getFiller() const {
	return filler;
}

/*! Returns the name of the task that extracts the item from a product*/
const std::string& Item::getRemover() const {
	return remover;
}

/*! Returns the code*/
unsigned int Item::getCode() const {
	return code;
}

/*! Inserts item data into the os*/
void Item::display(std::ostream& os, bool full /*= false*/) const
{
	os	<<	std::left	<< std::setfill(' ') << std::setw(field_width + 1)	<< name << "["
		<<	std::right	<< std::setfill('0') << std::setw(CODE_WIDTH)	<< code << "]";
	if (full)
	{
		os	<< " From "	<< std::left << std::setfill(' ') << std::setw(field_width) << filler
			<< " To "	<< std::left << std::setw(field_width) << remover << std::endl
			<<	std::setw(field_width + CODE_WIDTH + 4) << std::right << " : " << description;
	}
	os << std::endl;
}