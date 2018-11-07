#ifndef SALES_DATA
#define SALES_DATA

#include<string>

class Sales_data{
	
	//friend
	friend std::ostream &printData(std::ostream&, const Sales_data&);
	friend std::istream &readData(std::istream&, Sales_data&);
	
	public:
	//constructor
	//为什么这儿的默认构造函数不能初始化units_sold和revenue了？
	//这就是默认构造函数，但如果有构造函数初始值列表，则不能后接 = default;
	Sales_data():units_sold(0),revenue(0.0){};
	//显示初始化
	Sales_data(const std::string &s):bookNo(s),units_sold(0),revenue(0.0){}
	Sales_data(std::istream &is){
		double price;
		is >> bookNo >> units_sold >> price;
		revenue = price * units_sold;
		}
	Sales_data(const std::string &s, unsigned u, double p):bookNo(s){}
	//function
	std::string isbn() const{return bookNo;}
	Sales_data& combine(const Sales_data&);
	
	private:
	//varible
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

//非成员接口函数
std::ostream &printData(std::ostream&, const Sales_data&);
std::istream &readData(std::istream&, Sales_data&);

#endif