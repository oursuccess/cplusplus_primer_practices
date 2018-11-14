#include<iostream>

struct Base{
	void bar(int) { std::cout << "base bar" << std::endl;}
	protected:
	int ival = 0;
};

struct Derived1 : virtual public Base{
	void bar(char) {std::cout << "d1 bar" << std::endl;}
	void foo(char) { std::cout << "d1 foo" << std::endl;}
	protected:
	char cval = '1';
};

struct Derived2 : virtual public Base{
	void foo(int){std::cout << "d2 foo" << std::endl;}
	protected:
	int ival = 10;
	char cval = '1';
};
class VMI : public Derived1, public Derived2{};

int main()
{
	VMI v;
	//d1 bar
	v.bar(1);
	//d1 bar
	v.bar('a');
	//error : found multi functions with different arguments
	//v.foo('a');
	//v.foo(2);
	//error : ival is a protected member of derived2(which means VMI can visit)
	//error : found multi cval has different values
	//std::cout << v.ival ; //v.cval;

	system("pause");
	return 0;
}
