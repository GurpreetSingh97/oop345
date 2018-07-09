// Final Project Milestone 2
// Version 1.0
// Date	
// Author	
//
// Revision History
// -----------------------------------------------------------
// Name:Gurpreet Singh    Date:3 December 2017    Reason:null

#include <cstring>
#include "ErrorMessage.h"
#define _CRT_SECURE_NO_WARNINGS



namespace sict {

	 ErrorMessage::ErrorMessage(const char* errorMessage ){
		if (errorMessage == nullptr) {
			e_message = nullptr;
		}
		else {
			int length = strlen(errorMessage);
			e_message = new char[length+1];
			strcpy(e_message, errorMessage);
		}
	}
	

	  ErrorMessage::~ErrorMessage() {
		  delete[] e_message;
	 }
	 

	  void ErrorMessage::clear() {
		  delete[] e_message;
		  e_message = nullptr;
	  }
	  
	  bool ErrorMessage::isClear() const {
		  bool answer;
		  if (e_message == nullptr) {
			  answer = true;
		  }
		  else {
			  answer = false;
		  }
		  return answer;
	  }
	 
	  void ErrorMessage::message(const char* str) {

		  clear();
		  if (str != nullptr) {
			  int length = strlen(str);
			  e_message = new char[length + 1];
			  strcpy(e_message, str);
		  }
		  else {
			  e_message = nullptr;
		  }
	  }

	  
	  const char* ErrorMessage::message() const {
		  return e_message;
	  }
	
	  std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& obj) {
		  if (!obj.isClear()) {
			
			  ostr << obj.message();
		  }
		  
		  return ostr;
	  }

	  
	 

}