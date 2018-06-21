/*!
W1_CSTRING_H, a header guard to prevent repetition use in cString file
*/
#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>
/*!
Namespace w1
*/
namespace w1 {
	
	/*!
	max_char, a constant integer which states the maximun number of characters that can be stored in the character array
	*/
	
	const int max_char = 3;           
	/*!
	cString class that has array of max_char length named m_char and has one display function and overload operator <<
	*/

	class cString {
		
		/*!
		attribute of the class which stores the character array of max length max_char
		*/      
		char m_char[max_char +1]; 
	
	public:

		/*!
		constructor that initializes the m_char array by processing the parameter and storing the first max_char character.
		*/
		cString(char arr[]);  

		/*!
		display function, it sends the string to the ostream object
		*/
		void display(std::ostream& os) const; 

	};

	/*!
	overload operation<<, a helper non-friend operator that uses the public display function for output purpose
	*/
	std::ostream& operator<<(std::ostream& os,const cString& obj); 
}


#endif 
