#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include<string>

struct Sales_item{
	//func
	std::string isbn() const {return bookNo;}
	Sales_item& combine(const Sales_item&);
	Sales_item& update(const Sales_item&);
	
	//var
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_item add(const Sales_item&, const Sales_item&);
std::istream& rea(std::istream&,Sales_item&); 
std::ostream& prin(std::ostream&,const Sales_item&);

#endif