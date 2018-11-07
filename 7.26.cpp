#include<iostream>
#include<string>
#include"7.26.h"


int main()
{
	
	Sales_data book("hello",2,8.0);
	
	/*
	//语句错误，以下均为私有成员变量
	std::cout << book.bookNo << book.units_sold << book.revenue << std::endl;
	*/
	
	printBook(std::cout,book);
	
	system("pause");
	
	return 0;
}