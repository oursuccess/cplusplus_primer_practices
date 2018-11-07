#include<iostream>
#include<string>
#include"7.40.h"

int main()
{
	Book b1("Cookbook","978-1","pku","L",2,2016,9,39.4),b2,b3("pride and prejudice",88.2),b4("Little Prince","K",1,18.8);
	//,b5("Lolita","E",99.6);
	b1.printBook();
	b2.printBook();
	b3.printBook();
	b4.printBook();
	//b5.printBook(std::cout);
	
	system("pause");
	return 0;
}