/*!
Header guard to maintain the one defination rule
*/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "iProduct.h"

	/*!
	This class is used to store the Product Number's and Product's Cost.
	*/
	class Product: public w7::iProduct{
	protected:
		long proNumber;
		double proCost;
	public:

		/*!
		The Two-parameter Constructor for initalising the member variables
		*/
		Product(long number, double cost);

		/*!
		This function returns the Cost chargable to the customer of the product
		*/
		double getCharge() const;

		/*!
		This function is used for the display function, it pushes the product information
		in the form of a single line into the oustream object
		*/
		void display(std::ostream&) const;

	};

#endif // !PRODUCT_H
