#ifndef SALES_DATA
#define SALES_DATA

#include<string>

struct Sales_data{
	//constructor
	Sales_data() = default;
	Sales_data(const std::string &s):bookNo(s){}
	Sales_data(std::istream &is){
		double price;
		is >> bookNo >> units_sold >> price;
		revenue = price * units_sold;
		}
	Sales_data(const std::string &s, unsigned u, double p):bookNo(s){}
	//function
	std::string isbn() const{return bookNo;}
	Sales_data& combine(const Sales_data&);
	
	//varible
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//非成员接口函数
std::ostream &printData(std::ostream&, const Sales_data&);
std::istream &readData(std::istream&, Sales_data&);

#endif