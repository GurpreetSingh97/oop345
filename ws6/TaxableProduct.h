/*!
Header guard to maintain the one defination rule
*/
#ifndef TAXABLEPRODUCT_H
#define TAXABLEPRODUCT_H

#include "Product.h"

	class TaxableProduct : public Product {
		double taxArray[2];
		char taxStatus;
	public:

		/*!
		The three-parameter constructor which is used to initalises the member variables of the class 
		*/
		TaxableProduct(long number, double cost, char tax);
		
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
#endif
