
#include<string>
#include<iostream>
#include"Quote.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Quote q1("test1", 10);
	Quote q2(q1);
	q2 = q1;

	Bulk_quote bq1("test2",10,20,0.5);
	Bulk_quote bq2(bq1);
	bq2 = bq1;

	Test_quote tq1("test3",10,20,0.5);
	print_total(cout,tq1,20);

	system("pause");
	return 0;
}
