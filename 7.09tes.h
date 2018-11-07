#ifndef PERSON
#define PERSON

#include<string>

struct person{
	//func
	//可以作为…… 但是在需要在main函数之前定义，否则将没有对象
	//上面错了 没加person声明域的话，是重新生命定义了一个非成员函数版本
	//为什么printPerson和getPerson都不是person的成员？
	//写错了，之前include的是7.09 而不是 7.09.cpp
	std::istream& getPerson(std::istream&, person &);
	std::ostream& printPerson(std::ostream&, const person &);
	
	//var
	std::string name;
	std::string address;
};

#endif