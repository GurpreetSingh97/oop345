#include "NonPerishable.h"
#include "ErrorMessage.h"
#include <iomanip>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
namespace sict {

	void NonPerishable::name(const char* p_name) {
		if (p_name != nullptr && p_name[0]!='\0') {
			int length = strlen(p_name);
			item_name = new char[length + 1];
			strcpy(item_name, p_name);
		}
	}

	const char* NonPerishable::name() const {
			return item_name;		
	}

	double NonPerishable::cost() const {
		double ans;
		if (taxable) {
			ans= price + price*tax_rate;

		}
		else {
			
			ans = price;
		}
		return ans;
	}
	void NonPerishable::message(const char* obj) {
		err.message(obj);
	}

	bool NonPerishable::isCLear() const {
		bool answer;
		if (err.isClear() == true) {
			answer = true;
		}
		else {
			answer = false;
		}
		return answer;
	}
	
	NonPerishable::NonPerishable(char p_type) {
		type = p_type;
		sku[0] = '\0';
		item_name = nullptr;
		unit[0] = '\0';
		current_quantity = 0;
		required_quantity = 0;
		price = 0;
		taxable = false;;
		err.clear();

	}
	//done
	NonPerishable::NonPerishable(const char* p_sku, const char* p_name, const char* p_unit, int p_current_qunatity, bool p_taxable, double p_price, int p_required_quantity) {
		if (p_sku[0]!='\0' && p_name != nullptr && p_unit!='\0') {

			type = '\0';
			strcpy(sku, p_sku);
			item_name = nullptr;
			name(p_name);
			strcpy(unit, p_unit);
			current_quantity = p_current_qunatity;
			taxable = p_taxable;
			price = p_price;
			required_quantity = p_required_quantity;
			err.clear();



		}
		else {
			type = '\0';
			sku[0] = '\0';
			item_name = nullptr;
			unit[0] = '\0';
			current_quantity = 0;
			required_quantity = 0;
			price = 0;
			taxable = true;
			err.clear();
		}
	}
	//done
	NonPerishable::NonPerishable(const NonPerishable& obj) {
		type = obj.type;
		current_quantity = obj.current_quantity;
		required_quantity = obj.required_quantity;
		price = obj.price;
		taxable = obj.taxable;

		if (obj.sku[0] != '\0' &&  obj.item_name != nullptr && obj.unit != '\0' && obj.err.isClear() == true) {

			strcpy(sku, obj.sku);
			name(obj.item_name);
			strcpy(unit, obj.unit);
			err.clear();
		}
		else {
			sku[0] = '\0';
			item_name = nullptr;
			unit[0] = '\0';
			err.clear();
		}

	}

		NonPerishable& NonPerishable::operator=(const NonPerishable& obj) {
		if (this != &obj) {

			type = obj.type;
			current_quantity = obj.current_quantity;
			required_quantity = obj.required_quantity;
			price = obj.price;
			taxable = obj.taxable;

			delete[] item_name;
			if (obj.sku[0] != '\0' && obj.item_name != nullptr && obj.unit != '\0' && obj.err.isClear() == true) {

				strcpy(sku, obj.sku);
				name(obj.item_name);
				strcpy(unit, obj.unit);
				err.clear();
			}
			else {
				sku[0] = '\0';
				item_name = nullptr;
				unit[0] = '\0';
				err.clear();
			}

		}
		return *this;
	}




	NonPerishable::~NonPerishable() {
		delete[] item_name;
	}

	
	std::fstream& NonPerishable::store(std::fstream& file, bool newLine) const {
		if (file.is_open()==true) {
			file << type;
			file<< ",";
			file << sku;
			file << ",";
			file << item_name;
			file << ",";
			file << current_quantity;
			file << ",";
			file << required_quantity;
			file << ",";
			file << price;
			file << ",";
			file << taxable;

			

			if (newLine == true) { // adds a new line at the end
				file << endl;
			}
		}

		return file;

	}
	//load function pending
	std::fstream& NonPerishable::load(std::fstream& file) {

		char c_type;
		char c_sku[max_sku_length+1];
		char* c_item_name; //DYNAMIC MEMORY
		char c_unit[max_unit_length+1];
		int c_current_quantity;
		int c_required_quantity;
		double c_price;
		bool c_taxable;

		if (file.is_open()==true) {

			file >> c_type;
			file.ignore();
			file.getline(c_sku, max_sku_length+1, ','); //DELIMETER IS ,
			file.ignore();

			c_item_name = new char[max_name_length + 1];
			file.getline(c_item_name, max_name_length+1, ',');
			file.ignore();
		
			file.getline(c_unit, max_unit_length + 1, ',');
			file.ignore();

			file >> c_current_quantity;
			file.ignore();

			file >> c_required_quantity;
			file.ignore();

			file >> c_price;
			file.ignore();

			file >> c_taxable;
			file.ignore();
		
			NonPerishable copy_file(c_sku, c_item_name, c_unit, c_current_quantity, c_taxable, c_price, c_required_quantity); //using constructor7
			*this = copy_file; //asssigning
		
		}
		return file;
	}

	std::ostream& NonPerishable::write(std::ostream& os, bool linear) const {
		if (isEmpty()==true) {
			if (linear==true) {
				os << cout.fill(' ') << left << cout.width(max_sku_length) << sku << '|'<< cout.width(20) << name() << '|'
				<< right << cout.width(7) << fixed << showpoint << setprecision(2) << cost() << '|'<< cout.width(4) << quantity() << '|'
				<< cout.width(10) << unit << '|'<< cout.width(4) << qtyNeeded() << '|';
			}
			// implement straight line display here
			else {
				os << "Sku: " << sku<<endl;
				os << "Name: " << item_name<<endl;
				os << "Price" << price<<endl;
				if (taxable) os << "Price after tax: " << cost()<<endl;
				os << "Quantity On Hand:" << current_quantity<<endl;
				os << "Quantity Needed" << required_quantity <<endl;
			}
		}
		return os;
	}

	std::istream& NonPerishable::read(std::istream& is) {
		char temp_sku[max_sku_length + 1];   
		char temp_item_name[max_name_length + 1];  
		double temp_price;    
		bool temp_taxable;   
		int temp_current_quantity;    
		char temp_unit[max_unit_length + 1];
		int temp_required_quantity;
		char temp_taxed;
		if (!is.fail())
		{
			cout << "Sku: ";
			is >> temp_sku;
			cout << "Name: ";
			is >> temp_item_name;
			cout << "Unit";
			is >> temp_unit;
			if (err.isClear()==true)
			{	cout << "Taxed?: ";
				is >> temp_taxed;
				if (!is.fail()) {
					if (temp_taxed == 'y' || temp_taxed == 'Y') {
						temp_taxable = true;
					}
					else if (temp_taxed == 'n' || temp_taxed == 'N') {
						temp_taxable = false;
					}
					else {
						temp_taxed = '\0';
						message("Only (Y)es or (N)o are acceptable");
					}
				}
				else {
					message("Only (Y)es or (N)o are acceptable");
				}

				cout << "Price";
				is >> temp_price;
				if (temp_price < 0)
				{
					temp_price = 0;
					message("Invalid Price Entry");
				}
				cout << "Quantity On Hand: ";
				is >> temp_current_quantity;
				if (temp_current_quantity < 0)
				{
					temp_current_quantity = 0;
					message("Invalid Quantity Entry");
				}
				cout << "Quantity Needed:";
				is >> temp_required_quantity;
				if (temp_required_quantity < 0)
				{
					temp_required_quantity = 0;
					message("Invalid Quantity Needed Entry");
				}
			} 
		} 

		NonPerishable copy_file(temp_sku, temp_item_name, temp_unit, temp_current_quantity, temp_taxable, temp_price, temp_required_quantity); //using constructor7
		
		*this = copy_file; //assigning same as above

		return is;
	}




	bool NonPerishable::operator==(const char*p_sku) const {
		bool answer;
		if (strcmp(sku, p_sku) == 0) {
			answer = true;
		}
		else {
			answer = false;
		}
		return answer;
	}


	double NonPerishable::total_cost() const {
		double ans;
		if (taxable == true) {
			 ans =  current_quantity * price*(1+tax_rate);
		}
		else {
			ans = current_quantity*price;
		}
		return ans;
	}


	void NonPerishable::quantity(int on_hand) {
		current_quantity = on_hand;

	}


	bool NonPerishable::isEmpty() const {
		bool answer;
		if (item_name == nullptr) {
			answer = true;

		}
		else {
			answer = false;
		}
		return answer;
	}


	int NonPerishable::qtyNeeded() const {
		return required_quantity;
	}
	int NonPerishable::quantity() const {
		return current_quantity;

	}


	bool NonPerishable::operator>(const char* p_sku) const {
		bool answer;
		if (strcmp(p_sku, sku)>0) {
			answer = true;
		}
		else {
			answer = false;
		}
		return answer;
	}


	int NonPerishable::operator+=(int number) {
		int ans;
		if (number > 0) {
			ans= current_quantity += number;
		}
		else {
			ans= current_quantity;
		}
		return ans;
	}



	bool  NonPerishable::operator>(const Product& obj ) const {
		bool answer;
		if(strcmp(item_name,obj.name())>0){
			answer = true;
		}
		else{
			answer = false;
		}
		return answer;
	}


	

	
	
	ostream& operator<<(ostream& ostr, const Product& p)
	{
		p.write(ostr, true);
		return ostr;
	}
	istream& operator >> (istream& is, Product& p)
	{
		p.read(is);
		return is;
	}

	double operator+= (double& given, const Product& p)
	{
		given += p.total_cost();
		return given;
	}
	//need prof help
	Product* CreateProduct() {
		Product* obj = new NonPerishable;
		return obj;
	}
	


}