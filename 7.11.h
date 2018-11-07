#ifndef SALES_DATA
#define SALES_DATA

#include<string>

struct Sales_data{
	//constructor
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s),units_sold(n),revenue(p*n){}
		
	/*
	//7.11
	//Sales_data(std::istream&);
	*/
	
	//无法直接初始化,但可以在构造函数函数体内部控制输入流
	Sales_data(std::istream &is){is >> bookNo;}
	
	//func
	std::string isbn() const{ return bookNo;}
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	
	//var
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &printData(std::ostream&, const Sales_data&);
std::istream &readData(std::istream&, Sales_data&);

#endif