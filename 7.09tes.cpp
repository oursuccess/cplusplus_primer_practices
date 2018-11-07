#include<iostream>
#include<string>
#include"7.09tes.h"

//读取和打印person对象的操作函数定义
/*
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
*/

std::istream& person::getPerson(std::istream& is, person &one)
{
	is >> one.name >> one.address;
	return is;
}

std::ostream& person::printPerson(std::ostream& os, const person &one)
{
	os << one.name << "\n" << one.address;
	return os;
}

int main()
{
	person one;
	
	while(person::getPerson(std::cin,one)){
		person::printPerson(std::cout,one);
	}
	
	return 0;
}

