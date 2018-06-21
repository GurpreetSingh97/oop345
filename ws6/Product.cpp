#include <iostream>
#include "Product.h"
#include <iomanip>

using namespace std;

Product::Product(long number,double cost) {
	proCost = cost;
	proNumber = number;
}
double Product::getCharge() const {
	return proCost;
}
void Product::display(std::ostream& os) const {
	os << setw(10) << proNumber<< setw(10) << fixed 
	<<setprecision(2) << proCost << ' ' << endl;
}