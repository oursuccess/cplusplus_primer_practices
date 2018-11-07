//a class that bind employees and their id no
#include<iostream>
#include<string>

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class Employee{
	//constructor
	public:
		Employee(string s):name(s),ID(IDBase++){}

		Employee(const Employee& e):name(e.name),ID(e.ID){}
	
	//friend
	
	//operator
	friend ostream& operator<<(ostream&, const Employee &);
	Employee& operator=(const Employee& e){ name = e.name; ID = e.ID; return *this;}
	
	//func
	
	//var
	private:
		string name;
		unsigned ID;
	
	//static
	private:
		static unsigned IDBase;
	//deconstructor
	public:
		~Employee(){}
};

unsigned Employee::IDBase = 0;

ostream& operator<<(ostream& os, const Employee &e)
{
	os << "name: " << e.name <<  " ID" << e.ID << " ";
	return os;
}
