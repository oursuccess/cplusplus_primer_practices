#include<iostream>
#include"Quote.h"

int main()
{
	Quote q1("text1",5.0);
	Bulk_quote q2("text2",5.0,20,0.8);

	print_total(std::cout,q1,30);
	print_total(std::cout,q2,30);

	system("pause");
	return 0;
}
