#include<iostream>
#include<string>
#include"7.14.h"

int main()
{
	Sales_data total("ABOOK");
	printData(std::cout,total);
	Sales_data temp;
	printData(std::cout,temp);
	
	
	//while中创建对象似乎是只走一次循环？
	//不好意思，只是用7.11 生成了7.13而已
	//条件判断中不能声明定义对象吗？
	//Sales_data的构造函数无法作为条件判断
	while(readData(std::cin,temp)){
	//while(Sales_data temp(std::cin)){
		if(total.isbn() == temp.isbn())
		{
			total.combine(temp);
		}else{
			printData(std::cout, total);
			total = temp;
		}
	}	

	printData(std::cout,total);
	
	system("pause");
	return 0;
}

//成员函数定义
//永远都不能忘了函数定义域
Sales_data& Sales_data::combine(const Sales_data& temp)
{
	units_sold += temp.units_sold;
	revenue += temp.revenue;
	return *this;
}

//接口函数定义
std::ostream &printData(std::ostream& os, const Sales_data &temp)
{
	os << temp.bookNo << temp.units_sold << temp.revenue;
	return os;
}

std::istream &readData(std::istream& is, Sales_data &temp)
{
	double price;
	is >> temp.bookNo >> temp.units_sold >> price;
	temp.revenue = price * temp.units_sold;
	return is;
}