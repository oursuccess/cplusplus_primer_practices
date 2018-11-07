#ifndef SALES_DATA
#define SALES_DATA

#include<iostream>
#include<string>

class Sales_data{

	public:
		Sales_data():bookNo(),units_sold(0),revenue(0.0){};
		Sales_data(std::istream &);
		friend std::ostream& operator<<(std::ostream& os, const Sales_data &item);
		friend std::istream& operator>>(std::istream& is, Sales_data &item);

	public:
		std::string isbn() const {return bookNo;}

	private:
		std::string bookNo;
		int units_sold;
		double revenue;
};

Sales_data::Sales_data(std::istream &is)
{
	double price;
	is >> bookNo >> units_sold >> price;
	revenue = price * units_sold;
}

std::ostream& operator<<(std::ostream& os, const Sales_data &item)
{
	os << " " << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

std::istream& operator>>(std::istream& is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

#endif
