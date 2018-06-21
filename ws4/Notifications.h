/*!
Header guard to prevent the problem of double inclusion when dealing with the include directive
*/
#ifndef W5_NOTIFICATION_H
#define W5_NOTIFICATIONS_H

#include <iostream>
#include <string>
#include "Message.h"
#include <vector>


using namespace std;

/*!
Namespace w5, to avoid collision of names from different files
*/
namespace w5 {
	class Notifications {

		/*
		A vector to store Message objects, it is same as an array but it's size can be change dynamically 
		*/
		vector <Message> m_notifaications;

	public:
		/*!
		Default constructor to set all the member variable to safe empty state
		*/
		Notifications();
		
		/*!
		Copy Constructor to initalise a new object using another object of the same class
		*/
		Notifications(const Notifications&);

		/*!
		Copy assignment Operator to copy all the data from the source object to the given object
		*/
		Notifications& operator=(const Notifications&);

		/*!
		Move constructor to create a new object from a source object and erasing all the data from the source object
		*/
		Notifications(Notifications&&);

		/*!
		Move copy assignment operator to copy all the data from the source object to the given object and erasing all the data from the source object.
		*/
		Notifications&& operator==(Notifications&&);

		/*!
		Destructor to dellocate the dynamically allocated memory
		*/
		~Notifications();

		/*!
		"+= overload operator" to add a message to the set
		*/
		void operator+=(const Message& msg);

		/*!
		Display function which insert all the Message objects, one by one, in the std::ostream object for the purpose of display
		*/
		void display(std::ostream& os) const;
	};
}

#endif