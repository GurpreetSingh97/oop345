#include <iostream>
#include <iomanip>
#include "Product.h"
#include "TaxableProduct.h"


using namespace std;


TaxableProduct::TaxableProduct(long number, double cost, char tax) :Product(number,cost) {
      taxArray[0] = 1.13;
      taxArray[1] = 1.08;
	taxStatus = tax;

}

double TaxableProduct::getCharge() const {
	double totalCost;
	if (taxStatus == 'H') {
		totalCost = proCost *taxArray[0];
	}
	if(taxStatus == 'P'){
		totalCost = proCost*taxArray[1];
	}
	return totalCost;
}

void TaxableProduct::display(std::ostream& os) const {
	os << std::setw(10) << proNumber
		<< std::setw(10) << std::fixed << std::setprecision(2) << proCost
		<< ' ' << (taxStatus == 'H' ? "HST" : "PST") << std::endl;
}
