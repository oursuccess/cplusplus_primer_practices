#include<iostream>
#include<string>
#include"7.15.h"

int main()
{
	person p1;
	printPerson(std::cout,p1);
	
	person p2("Davi");
	printPerson(std::cout,p2);
	
	person p3("Davi","Beijing");
	printPerson(std::cout,p3);
	
	person p4(std::cin);
	printPerson(std::cout,p4);
	
	system("pause");
	
	return 0;
}

