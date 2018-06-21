#include <iostream>
#include "Utilities.h"

char Utilities::delimiter;
std::ofstream Utilities::logFile;

Utilities::Utilities()
{
	Utilities::field_width = 1;
}

void Utilities::setFieldWidth(size_t width)
{
	Utilities::field_width = width;
}

size_t Utilities::getFieldWidth() const
{
	return Utilities::field_width;
}

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more)
{
	//Substracts string to the given position
	std::string token = str.substr(next_pos);

	// Finds the position of the delimiter
	int pos = token.find(delimiter);
	token = (pos == -1) ? token : token.substr(0, pos);

	next_pos += token.size() + 1;
	more = (next_pos < str.size() - 1);

	// REMOVING SPACES
	bool exit = false;

		// Removing spaces from the end
		for (size_t i = token.size() - 1; !exit && i > 0; i--)
		{
			// if last character is space it removes it
			if (token[i] == ' ') token = token.substr(0, i);
			else exit = true;
		}

		exit = false;

		// Removing spaces from beginning
		while (token.size() > 0)
		{
			if (token[0] == ' ' || token[0] == '\t') token = token.substr(1);
			else break;
		}
	
	if (field_width < token.size()) setFieldWidth(token.size());
	
	return token;
}

void Utilities::setDelimiter(const char deli) {
	Utilities::delimiter = deli;
}

void Utilities::setLogFile(const char* logfile)
{
	// Close the logfile if the logfile is already open
	if (Utilities::logFile.is_open()) Utilities::logFile.close();
	Utilities::logFile.open(logfile);
}

std::ofstream& Utilities::getLogFile()
{
	return Utilities::logFile;
}
