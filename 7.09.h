#ifndef PERSON
#define PERSON

#include<string>

struct person{
	//func
	//为什么对person进行读写的函数不能作为成员函数？
	//因为此时person对象尚未创建，也就没有函数可言？
	//那成员函数呢？
	friend std::istream& getPerson(std::istream&, person &);
	friend std::ostream& printPerson(std::ostream&, const person &);
	
	//var
	std::string name;
	std::string address;
};

#endif