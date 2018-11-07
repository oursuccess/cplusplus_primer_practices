#ifndef SALES_DATA
#define SALES_DATA

#include<string>

class Sales_data{
	//friend
	friend std::istream& readData(std::istream&, Sales_data&);
	friend std::ostream& printData(std::ostream&, const Sales_data&);
	
	//constructor
	public:
	Sales_data():Sales_data("",0,0){}
	Sales_data(std::string s,unsigned i,double price):bookNo(s),units_sold(i),revenue(price * i){}
	Sales_data(std::istream& is){readData(is,*this);}
	
	//func
	public:
	std::string isbn(){return bookNo;}
	Sales_data& combine(Sales_data&);
	
	//var
	private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

std::istream& readData(std::istream& is, Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

std::ostream& printData(std::ostream& os, const Sales_data& item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data& Sales_data::combine(Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

#endif