#include<iostream>
#include<string>
#include"7.22.h"

int main()
{
	person A("Daco","Tibet");
	putPerson(std::cout, A);
	person B(std::cin);
	putPerson(std::cout, B);
	person C;
	while(getPerson(std::cin,C))
	{
		putPerson(std::cout,C);
	}
	
	return 0;
}


//第二个形参声明为类，而非类的引用，将直接导致函数重载，而且报错提示是one的成员为私有成员
//为什么还是报错提示name与address为私有成员？
std::istream& getPerson(std::istream& is, person& one)
{
	is >> one.name >> one.address;
	return is;
}

//又重载了 这次是忘了const
std::ostream& putPerson(std::ostream& os,const person& one)
{
	os << one.name << " " << one.address;
	return os;
}