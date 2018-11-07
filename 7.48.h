#ifndef SALES_DATA
#define SALES_DATA

#include<string>
#include<iostream>

class Sales_data{
	//friend
	
	
	//constructor
	public:
	//Sales_data(std::string s):bookNo(s){}
	//explicit
	explicit Sales_data(std::string s):bookNo(s){}
	
	//func
	std::ostream& printData(std::ostream &os = std::cout){os << bookNo; return os;}
	
	//var
	private:
	std::string bookNo;
	
};


#endif