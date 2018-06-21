/*!
Header guard to maintain the one defination rule
*/
#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

#include <iostream>
#include <fstream>

namespace w7 {

	class iProduct {
	public:

		/*!
		GetCharge, a pure virtual function that returns the Cost of the product
		*/
		virtual double getCharge() const = 0;

		/*!
		Display, a pure virtual function, which puts the product information
		into the ostream object
		*/
		virtual void display(std::ostream&) const = 0;
	};

	/*
	! This Function is used as a helping operator function
	*/
	std::ostream& operator<<(std::ostream&, const iProduct&);

	/*!
	This Function reads the product information from the file and returns it in
	the form of iProduct object
	*/
	iProduct* readProduct(std::ifstream&);
}
#endif