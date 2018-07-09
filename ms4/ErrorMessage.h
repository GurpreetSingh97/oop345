// Final Project Milestone 2
// Version 1.0
// Date	
// Author	
//
//
// Revision History
// -----------------------------------------------------------
// Name :Gurpreet Singh     Date:3 december 2017   Reason- null

#include <iostream>
#ifndef SICT_ERRORMESSAGE_H
#define SICT_ERRORMESSAGE_H

namespace sict {
	class ErrorMessage {
		char* e_message;
	public:
		explicit ErrorMessage(const char* errorMessage = nullptr);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		virtual ~ErrorMessage();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
		                     

	};
	// helper operator 
	std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& obj);
}

#endif //SICT_ERRORMESSAGE_H