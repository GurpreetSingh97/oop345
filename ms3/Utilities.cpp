#include <iostream>
#include <string>
#include <fstream>
#include "Utilities.h"

using namespace std;

ofstream Utilities::logFile;
char Utilities::delimiter;


Utilities::Utilities() {
	field_width = 1;
}


size_t Utilities::getFieldWidth() const {
	return field_width;
}

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {
	
	string token = str.substr(next_pos);

	size_t temp_delimiter = token.find(delimiter);

	if (temp_delimiter == string::npos) {
		token = token.substr(0, token.find_first_of("\r\n"));
	}
	else {
		token = token.substr(0, temp_delimiter);
	}

	if (field_width < token.size()) {
		field_width = token.size();
	}

	next_pos = next_pos + token.size() + 1;

	if ((next_pos < str.size() - 1)) {
		more = true;
	}
	else {
		more = false;
	}

	size_t position;
	
	while ((position = token.size() - 1) != string::npos) {
		if (isspace(token.at(position))) {
			token.erase(position);
		}
		else {
			break;
		}
	}
	
	while (token.size() > 0) {
		if (isspace(token.at(0))) {
			token.erase(0, 1);
		}
		else { 
			break; 
		}
	}
	return token;
}

 void Utilities::setDelimiter(const char c) {
	 delimiter = c;
}
 void Utilities::setLogFile(const char* logfile) {
	 logFile.close();
	 logFile.open(logfile);
}
 std::ofstream& Utilities::getLogFile() {
	 return logFile;
}

