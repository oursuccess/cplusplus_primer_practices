#include<iostream>
#include"Quote.h"

int main()
{
	Quote q1("text1",5.0);
	//disc quote is an abstract class
	//Disc_quote qd("text0",5.0,20,0.8);
	Bulk_quote q2("text2",5.0,20,0.8);
	Less_quote q3("text3",5.0,20,0.8);

	q1.debug();
	print_total(std::cout,q1,30);
	q2.debug();
	print_total(std::cout,q2,30);
	q3.debug();
	print_total(std::cout,q3,30);

	system("pause");
	return 0;
}
