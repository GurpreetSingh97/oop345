/*!
header guard to prevent repetition in Text file and to maintain one defination rule
*/
#ifndef W3_TEXT_H
#define W3_TEXT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*!
NAMESPACE w3, to prevent the problem of double inclusion while dealing with #include
*/
namespace w3 {
	
	/*!
	Text class for storing the count of records and the data from the given file
	*/
	class Text {
		
		int m_count;
		string* m_arr;
	public:
	
		/*!
		initalise the instances of the class to safe empty space
		*/
		Text();

		/*!
		copy the data from the given file into the string instance of the class
		*/
		Text(const string filename); 

		/*!
		Copy operator for copying from a given object to a newely created object
		*/
		Text(const Text& obj);

		/*!
		copy operator for copying from a given object to an already existing object
		*/
		Text& operator=(const Text& obj); 

		/*!
		move constructor to create a new object form existing one and deleting the data of the existing object
		*/
		Text(Text&& obj);

		/*!
		move operator to create a new Text class object form source object and deleting the data of the source object
		*/
		Text&& operator=(Text&& obj);
		
		/*!
		destructor to deallocate any dynamic memory
		*/
		~Text();

		/*!
		This function returns the number of records
		*/
		size_t size() const;
	};


}
#endif
