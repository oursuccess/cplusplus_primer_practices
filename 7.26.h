#ifndef SALES_DATA
#define SALES_DATA

#include<string>

class Sales_data{
	//friend
	//io类不能被拷贝，只能通过引用来传递它们，而且因为读取和写入都会改写流的内容，因此引用不能为常量引用
	friend std::ostream& printBook(std::ostream&, const Sales_data&);
	
	
	//constructor
	public:
	Sales_data() = default;
	
	/*
	//如果把形参都命名为类内成员会怎么样？而且构造函数中某一成员变量的初始化会使用形参还是成员名呢？
	//没报错
	//无法在此电脑上运行？
	//为什么13.2MB？
	//emmm，把.h转成了exe文件……
	//revenue使用的units_sold为传入的形参而非类内成员
	Sales_data(std::string bookNo,unsigned units_sold,double price):bookNo(bookNo),units_sold(0),revenue(price*units_sold){};
	*/
	
	Sales_data(const std::string& b,unsigned u,double p):bookNo(b),units_sold(u),revenue(p*u){};
	
	//func
	
	//var
	private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


std::ostream& printBook(std::ostream& os, const Sales_data& item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

#endif