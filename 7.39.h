#ifndef SALES_ITEM
#define SALES_ITEM

#include<string>
#include<iostream>

class Sales_item{
	//friend
	
	//constructor
	public:
	//error call to constructor of "Sales_item" is ambiguous: 2 candidate constructor
	Sales_item(std::istream& is = std::cin){ is >> bookNo;}
	Sales_item(std::string isbn = " "):bookNo(isbn){}
	
	//func
	
	
	
	//var
	private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


#endif