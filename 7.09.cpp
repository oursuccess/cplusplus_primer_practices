#include<iostream>
#include<string>
#include"7.09.h"

//读取和打印person对象的操作函数定义
std::istream& getPerson(std::istream& is, person &one)
{
	is >> one.name >> one.address;
	return is;
}

std::ostream& printPerson(std::ostream& os, const person &one)
{
	os << one.name << "\n" << one.address;
	return os;
}

int main()
{
	person one;
	
	while(getPerson(std::cin,one)){
		printPerson(std::cout,one);
	}
	
	return 0;
}

