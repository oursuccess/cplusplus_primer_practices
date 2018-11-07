#include<iostream>
#include<string>
#include"7.48.h"


int main()
{
	//以下两种均可以正常使用？
	std::string null_isbn("9-999-99999-9");
	Sales_data item1(null_isbn);
	//下面是不报错的
	//Sales_data item2(static_cast<Sales_data>("9-999-99999-9"));
	//下面同样不报错
	//Sales_data item2(static_cast<std::string>("9-999-99999-9"));
	//不转换也没问题……
	//可能是构造时是这样？
	Sales_data item2("9-999-99999-9");
	item1.printData();
	item2.printData();
	
	
	system("pause");
	return 0;
}