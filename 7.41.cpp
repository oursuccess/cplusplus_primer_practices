#include<iostream>
#include<string>
#include"7.41.h"

int main()
{
	//使用委托构造函数：默认构造函数委托至三参数版
	Sales_data d1,d2;
	//使用委托构造函数：三参数版
	Sales_data d3("A",10,9.8),d4("B",9,2.1);
	//使用委托构造函数：单参数委托至三参数版
	Sales_data d5("C");
	//使用委托构造函数：单参数委托至三参数版，随后从istream中读取信息流，并写入d6
	Sales_data d6(std::cin);
	d6.printData();
	
	system("pause");
	return 0;
}