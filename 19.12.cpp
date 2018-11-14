#include<iostream>

class test{
	public:
		int i = 1;
		int num() { return i; }
};

int main()
{
	test t;
	int test::* pi = &test::i;
	int (test::*pnum)() = &test::num;
	
	std::cout << t.*pi;
	std::cout << (t.*pnum)();

	system("pause");
	return 0;
}
