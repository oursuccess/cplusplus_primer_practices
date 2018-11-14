#include<iostream>

namespace out{
namespace test{
	void j(){ std::cout << "default ver in test" << std::endl;}
	void j(const void *) { std::cout << "j in test and need a argument which could turns to const void *" << std::endl; }
}

//using namespace test;
//this called int version
void j(int) { std::cout << " this is a int " << std::endl; }
void j(double, double = 3.4) { std::cout << "this is another function need at least one double "; }
void j(char * , char * = 0) { std::cout << "a version called by char * " ; }

void f()
{
	j(0);
}
}

int main()
{
	using namespace out::test;
	//this calls the int version too...
	//only this calls the void ver
	j(0);
	out::f();

	system("pause");
	return 0;
}
