#ifndef SALES
#define SALES

#include<iostream>
#include<string>

class Sales_data{
	public:
		//friend
		friend bool compareIsbn(const Sales_data&, const Sales_data&);
		friend std::istream& operator>>(std::istream &is, Sales_data& item);

	public:
		//constructor
		Sales_data(std::string s,unsigned u,double r):bookNo(s),units_sold(u),revenue(r){}
		Sales_data():Sales_data("",0,0.0){}
		Sales_data(std::istream&);
		
	public:
		//func
		std::string isbn() const {return bookNo;}
		std::ostream& printData(std::ostream& os = std::cout );

	private:
		//private func

	private:
		//var
		std::string bookNo;
		unsigned units_sold;
		double revenue;
};

// = std::cin makes it a default constructor and cause an error
Sales_data::Sales_data(std::istream &in )
{
	double price;
	in >> bookNo >> units_sold >> price;
	revenue = price * units_sold;
}

//operater
std::istream& operator>>(std::istream &is,Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if(is){
		item.revenue = price * item.units_sold;
	}
	else{
		item = Sales_data();
	}
	return is;
}

//Sales_data::printData
std::ostream& Sales_data::printData(std::ostream& os)
{
	os << bookNo << " " << units_sold << " " << revenue;
	return os;
}

//为什么将compareIsbn置于新文件不可行？
bool compareIsbn(const Sales_data&, const Sales_data&);


#endif
