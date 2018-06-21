#pragma once
// Milestone 1 - Utilities Interface
// Utilities.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016

#include <string>
#include <fstream>


/*!
Utilities class which holds field_width, delimiter and an ostream object to handle the file.
*/
class Utilities {
	size_t field_width;           // maximum field width needed 
	static char delimiter;        // field delimiter character
	static std::ofstream logFile; // log file
public:

	/*!
	Constructor for the Utilities class, which initalises the "field_width" variable to 1 
	*/
	Utilities();


	/*!
	GetFieldWidth function, which returns the "field_width" of the current object
	*/
	size_t getFieldWidth() const;


	/*!
	This function extracts the token from the given string and set the value of "More" to true
	if there are more tokens in the strings that can be extracted otherwise to false. 
	Moreover, it updates the value of field_width if it's value is smaller than the 
	size of the extracted token
	*/
	const std::string nextToken(const std::string&, size_t&, bool&);
	

	/*!
	This function sets the value of the member-variable "Delimeter" to the given parameter's values
	*/
	static void setDelimiter(const char);


	/*!
	SetLogFile function which opens the file with the given name in the "logFile" for the purpose of writing into it.
	*/
	static void setLogFile(const char*);


	/*!
	This function returns the reference to the log file that can be modified
	*/
	static std::ofstream& getLogFile();

};