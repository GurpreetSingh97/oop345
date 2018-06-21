/*!
Header guard to prevent the problem of double inclusion when dealing with the include directive
*/
#ifndef W5_MESSAGE_H
#define W5_MESSAGE_H

#include <string>

using namespace std;

/*!
Namespace w5, to avoid collision of names from different files
*/
namespace w5 {
	class Message {

		/*!
		Strings to store the name of the sender, receiver and the message sent by them
		*/
		string username;
		string reply;
		string tweet;

	public:

		/*!
		Message function to extract the username, receiver name and the Message from the file
		*/
		Message(std::ifstream& in, char c);

		/*!
		"Empty" function which returns true if the object is in safe empty state otherwise false
		*/
		bool empty() const;

		/*!
		Display function, it display the username, receiver's name and the message sent by them in a desirable and convinent format
		*/
		void display(std::ostream&) const;
	};
}

#endif