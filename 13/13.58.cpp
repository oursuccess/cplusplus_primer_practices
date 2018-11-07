#include<iostream>
#include"Foo.h"

using std::endl;
using std::cout;
using std::cin;

int main()
{
	Foo a;
	int i;
	while(cin >> i)
		a.push_back(i);
	
	cout << a << endl;
	Foo b(a);
	cout << b << endl;
	Foo c(a.sorted());
	cout << c << endl;

	system("pause");
	return 0;
}
