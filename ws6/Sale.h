/*!
Header guard to maintain the one defination rule
*/
#ifndef SALE_H
#define SALE_H

#include <iostream>
#include <vector>
#include "iProduct.h"

using namespace std;

namespace w7 {
	class Sale {
		vector<iProduct*> products;
	public:

		/*!
		The two-parameter constructor which is used to initalises the member variables
		*/
		Sale(const char* str);

		/*!
		This function is used to display the products information on the output
		in a desirable format
		*/
		void display(std::ostream& os) const;

	};
}

#endif // !SALE_H