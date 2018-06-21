#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "TaxableProduct.h"
#include "Product.h"
#include "Sale.h"



using namespace std;
using namespace w7;



Sale::Sale(const char* str) {
	ifstream is(str);
	iProduct* obj;
	
	while (is.good() && (obj = readProduct(is))!= nullptr) {
		products.push_back(obj);
	}

}


void Sale::display(std::ostream& os) const {
	os << setw(10) << "Product No" << setw(10) << "Cost" << " Taxable" << endl;

	double totalCost = 0;

	for (auto i : products){
		i->display(os);
		totalCost += i->getCharge();
	}

	os << setw(10) << "Total"<< fixed << setprecision(2) << setw(10) << totalCost << endl;
}


std::ostream& operator<<(std::ostream& os, const iProduct& obj) {
	obj.display(os);
	return os;  
}

iProduct* w7::readProduct(std::ifstream& is){
	
	string line;
	getline(is, line);

	stringstream ss;

	if (line.empty()==false)
	{
	ss.str(line);

	vector<string> vectr;

	string obj;
	//extract data by whole line
	while (ss >> obj) {
	vectr.push_back(obj);
	}

	iProduct* TempProd;
	if (vectr.size() == 3) {
	//string into long
	TempProd = new TaxableProduct(stol(vectr[0]),stod(vectr[1]), vectr[2].c_str()[0]);
	}
	else {
	TempProd = new Product(stol(vectr[0]),stod(vectr[1]));
	}
	return TempProd;
	}
	return nullptr;

	

	
}
