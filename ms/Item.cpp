#include <iostream>
#include <iomanip>
#include "Item.h"

#include "Utilities.h"

size_t Item::field_width = 0;

using namespace std;

Item::Item(const std::string& str) {
	description = "no detailed description";
	code = 1;

	//using the utilities class object to extract the info
	size_t next_pos = 0;
	bool more = true;
	Utilities obj;

	name = obj.nextToken(str, next_pos, more);
	if (name.empty()) {
		throw std::string(" No Name could be extracted!!! ");
	}
			

	if (more == true) {
		filler = obj.nextToken(str, next_pos, more);
	}
	if (filler.empty()) {
		throw std::string(" No Filler could be extracted!!! ");
	}

	
	if (more == true) {
		remover = obj.nextToken(str, next_pos, more);
	}
	if (remover.empty()) {
		throw std::string(" No Remover could be extracted!!! ");
	}


	if (more == true) {
		code = std::stoi(obj.nextToken(str, next_pos, more));
	}

	if (more == true) {
		description = obj.nextToken(str, next_pos, more);
	}
	
			
	if (field_width < name.size()) {
		field_width = name.size();
	}

}


bool Item::empty() const {
	bool answer = false;
	if (name.empty()) {
		answer = true;
	}
	return answer;
}


int Item::operator++(int) {
	return code++;
}


const std::string& Item::getName() const {
	return name;
}


const std::string& Item::getFiller() const {
	return filler;
}


const std::string& Item::getRemover() const {
	return remover;
}



unsigned int Item::getCode() const {
	return code;
}


void Item::display(std::ostream& os, bool full) const{
	os << std::left << std::setfill(' ') << std::setw(field_width + 1)	<< name << "[" << std::right << std::setfill('0') << std::setw(CODE_WIDTH) << code << "]";
	if (full == true){
		os	<< " From " << std::left << std::setfill(' ') << std::setw(field_width) << filler << " To "	<< std::left << std::setw(field_width) << remover<< endl
		<< std::setw(field_width + CODE_WIDTH + 4) << std::right << " : " << description;
	}

	os << endl;

}