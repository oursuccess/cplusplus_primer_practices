


//define a copy constructor and copy all members
//ps. dynamically allocate a new string , and copy new string to the location p points to, not just copy p
#include<iostream>
#include<string>

using std::cout;
using std::endl;

class HasPtr{
	public:
		HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0){}
		HasPtr(const HasPtr& h):ps(new std::string(*h.ps)), i(h.i){}

		//copy-assignment
		HasPtr operator=(const HasPtr& h){ps = new std::string(*h.ps); i = h.i; return *this;}
		//friend
		//don't forget to return os!!!
		friend std::ostream& operator<<(std::ostream& os, const HasPtr& hp);

		//func
		void changeWord(const std::string &s){*ps = s;}

		//deconstructor
		//it should be public or is un-readable
		//when is deleted, should free the space ps used
		~HasPtr(){delete ps; cout << "it is deleted~" << endl;}

	private:
		std::string *ps;
		int i;


};

std::ostream& operator<<(std::ostream& os, const HasPtr& hp) { 
	os << *hp.ps << " location of ps: " << hp.ps << " i: " << hp.i; 
	return os;
}


int main()
{
	{
	HasPtr h1("hello");
	HasPtr h2(h1);
	HasPtr h3;
	h3 = h1;
	cout << "h1: " << h1 << endl;
	cout << "h2: " << h2 << endl;
	cout << "h3: " << h3 << endl;


	
	h1.changeWord("world");

	cout << "h1: " << h1 << endl;
	cout << "h2: " << h2 << endl;
	cout << "h3: " << h3 << endl;
	}

	system("pause");
	return 0;
}
