#ifndef SALES_DATA
#define SALES_DATA

#include<iostream>
#include<string>

/*
//前向声明是非必要的
class Sales_data;
std::istream& readData(std::istream&, Sales_data&);
*/

class Sales_data{
	//friend
	//错在哪儿？
	//忘了friend前缀...
	//这样可能前向声明就是必要的了？
	//非必要
	friend std::istream& readData(std::istream&, Sales_data&);
	
	//constructor
	public:
	Sales_data(std::string s, unsigned cnt, double price):bookNo(s),units_sold(cnt),revenue(cnt * price){printData(std::cout);}
	
	//delegating constructor
	Sales_data():Sales_data("", 0 , 0.0){}
	Sales_data(std::string s):Sales_data(s,0,0.0){}
	
	//这里不首先声明readData能直接调用吗？
	//不需要预先声明
	Sales_data(std::istream& is):Sales_data(){readData(is,*this);}
	
	//func
	std::ostream& printData(std::ostream& os = std::cout)
	{
		os << bookNo << units_sold << revenue;
		return os;
	}
	
	//var
	private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

std::istream& readData(std::istream& is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

#endif