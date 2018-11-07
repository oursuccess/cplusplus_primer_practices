#include<iostream>
#include<string>
#include"HasPtr.hpp"

using std::cout;
using std::endl;

int main()
{
	HasPtr h1,h2("hello");
	h1 = h2;
	cout << "h1 " << h1 << "\th2" << h2 << endl;

	HasPtr h3("world");
	cout << "h3 " << h3 << endl;
	swap(h1,h3);
	cout << "h1 " << h1 << "\th3 " << h3 << endl;

	system("pause");
	return 0;
}
