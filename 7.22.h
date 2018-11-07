#ifndef PERSON
#define PERSON

#include<string>

class person{
	
	friend std::istream& getPerson(std::istream&, person&);
	friend std::ostream& putPerson(std::ostream&,const person&);
	
	//func
	public:
	//构造函数作为接口，需要声明为public
	person() = default;
	person(std::istream& is){
		is >> name >> address;
	}
	//不加std，后果很严重，将直接将s1s2默认为int
	person(const std::string &s1, const std::string &s2):name(s1),address(s2){}
	//var
	private:
	std::string name;
	std::string address;
	
};

std::istream& getPerson(std::istream&,person&);
std::ostream& putPerson(std::ostream&,const person&);

#endif