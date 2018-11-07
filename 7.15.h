#ifndef PERSON
#define PERSON

#include<string>

struct person{
	//constructor
	person() = default;
	person(const std::string s):name(s){}
	person(const std::string &s1, const std::string s2):name(s1),address(s2){}
	person(std::istream &is){is >> name >> address;}
	
	//member function
	std::string name;
	std::string address;
};

std::ostream& printPerson(std::ostream &os,person temp){
	os << temp.name << " " << temp.address;
	
	return os;
}
#endif