#ifndef SALES_DATA
#define SALES_DATA

#include<iostream>
#include<string>

class Sales_item{
	// friend
	
	
	//constructor
	public:
	//默认实参不能重复声明,默认实参在声明时声明
	Sales_item(std::istream& is = std::cin);
	
	//func
	//为什么说类内成员变量未声明？
	//忘了声明函数作用域
	std::ostream &display(std::ostream& );
	
	//var
	private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
	
};

Sales_item::Sales_item(std::istream& is)
{
	double price;
	is >> bookNo >> units_sold >> price;
	revenue = price * static_cast<double>(units_sold);
}

std::ostream& Sales_item::display(std::ostream& os = std::cout)
{
	os << bookNo << units_sold << revenue;
	return os;
}


#endif