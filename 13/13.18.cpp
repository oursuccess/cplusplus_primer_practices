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
	
	//friend
	
	//operator
	friend ostream& operator<<(ostream&, const Employee &);
	
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

int main()
{
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	Employee e1(s1), e2(s2),e3(s3);

	cout << e1 << e2 << e3 <<endl;

	system("pause");
	return 0;
}
