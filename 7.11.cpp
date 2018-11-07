#include<iostream>
#include<string>
#include"7.11.h"

int main()
{
	//默认构造函数
	/*
	Sales_data total,temp;
	*/
	
	//调用输入流,此时一次只能初始化一个变量
	//上面错误，先有类名，然后是括号
	//有问题，等下再次尝试
	//必须使用system.pause，否则将直接走完整个程序
	//此时将无法正常调用readdata函数初始化temp
	//直接跳过了while函数
	//因为此处的初始化构造函数调用了readdata，所以仍然期望的是三个变量，而非仅仅是一个bookNo
	Sales_data total(std::cin),temp;
	printData(std::cout,total);
	
	//分别使用三个变量和使用string初始化变量
	/*
	Sales_data total("B",2,8), temp("B");
	printData(std::cout,total);
	printData(std::cout,temp);
	*/
	
	while(readData(std::cin, temp)){
		//printData(std::cout,temp);
		if(total.isbn() == temp.isbn()){
			total.combine(temp);
		}
		else{
			printData(std::cout, total);
			total = temp;
		}
	}
	printData(std::cout,total);
	
	system("pause");
	return 0;
}


//接口函数
Sales_data& Sales_data::combine(const Sales_data &temp)
{
	if(isbn() == temp.isbn()){
		units_sold += temp.units_sold;
		revenue += temp.revenue;
	}
	else{
		std::cout << "please check isbn!" << std::endl;
	}
	return *this;
}

double Sales_data::avg_price() const
{
	return revenue/units_sold;
}

Sales_data add(const Sales_data&temp1, const Sales_data&temp2)
{
	Sales_data total = temp1;
	if(total.isbn() == temp2.isbn()){
		total.units_sold += temp2.units_sold;
		total.revenue += temp2.revenue;
	}
	else{
		std::cout << "isbn not equal!" << std::endl;
	}
	return total;
}

std::ostream &printData(std::ostream& os, const Sales_data& temp)
{
	os << temp.bookNo << " " << temp.units_sold << " " << temp.revenue;
	return os;
}

std::istream &readData(std::istream& is, Sales_data& temp)
{
	double price;
	is >> temp.bookNo >> temp.units_sold >> price;
	temp.revenue = price * temp.units_sold;
	return is;
}

//constructor
/*
//7.12题中，需要将此构造函数定义移入类内部
Sales_data::Sales_data(std::istream &s)
{
	readData(s, *this);
}
*/