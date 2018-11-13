#include<iostream>
#include<vector>
#include<string>
#include"Sales_data.h"
#include"findBook.h"

int main()
{
	Sales_data a1("b",10,2);
	Sales_data a2("a",12,3);
	Sales_data a3("c",4,10);
	Sales_data b1("b",1,3);
	Sales_data b2("a",8,1);
	Sales_data b3("c",8,28);

	std::vector<std::vector<Sales_data>> vvs;
	std::vector<Sales_data> va, vb;
	va.push_back(a1);
	va.push_back(a2);
	va.push_back(a3);
	vb.push_back(b1);
	vb.push_back(b2);
	vb.push_back(b3);


	vvs.push_back(va);
	vvs.push_back(vb);

	reportResults(std::cin,std::cout,vvs);

	system("pause");
	return 0;
}

