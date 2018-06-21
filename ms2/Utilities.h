#pragma once
// Milestone 1 - Utilities Interface
// Utilities.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#include <string>
#include <fstream>

class Utilities {
	size_t field_width;           // maximum field width needed
	static char delimiter;        // field delimiter character
	static std::ofstream logFile; // log file
public:
	/*!Default Constructor*/
	Utilities();
	/*! Sets Field Width*/
	void setFieldWidth(size_t fw);
	/*! Returns Field Width*/
	size_t getFieldWidth() const;
	/*! Returns a token to the given delimiter and position*/
	const std::string nextToken(const std::string&, size_t&, bool&);
	/*! Sets the delimiter*/
	static void setDelimiter(const char);
	/*! Opens the given logfile*/
	static void setLogFile(const char*);
	/*! Returns the logFile*/
	static std::ofstream& getLogFile();
};
