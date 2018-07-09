#ifndef SICT_NONPERISHABLE_H
#define SICT_NONPERISHABLE_H

#include "Product.h"
#include "ErrorMessage.h"
namespace sict {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class NonPerishable : public Product {
	private:
		char type;
		char sku[max_sku_length];
		char* item_name;
		char unit[max_unit_length];
		int current_quantity;
		int required_quantity;
		double price;
		bool taxable;
		ErrorMessage err;
	protected:
		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isCLear() const;
	public:
		NonPerishable(char p_type = '\0');
		NonPerishable(const char* p_sku,const char* p_name,const char* p_unit, int p_current_qunatity=0,bool p_taxable = true,double p_price = 0,int p_required_quantity=0);
		NonPerishable(const NonPerishable& obj);
		NonPerishable& operator=(const NonPerishable& obj);
		~NonPerishable();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;


	};
	//helper function
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
}
#endif // SICT_PERISHABLE_H