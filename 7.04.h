#ifndef PERSON
#define PERSON

#include<string>

struct Person{
	//7.5 可以使用const修饰this指针
	std::string name() const{return name;};
	std::string address() const{return address;};
	
	std::string name;
	std::string address;
};


#endif
