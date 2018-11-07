// just for test
#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

template<typename T>
T add(T t1, T t2){
	return t1+t2;
}

int main()
{
	int i = 2,j = 4;
	double d1 = 4.0,d2 = 2.1;
	string s1 = " hello ",s2("world");
	auto r1 = add(i,j);
	auto r2 = add(d1,d2);
	auto r3 = add(s1,s2);
	cout << "r1" << r1 << endl;
	cout << "r2" << r2 << endl;
	cout << "r3" << r3 << endl;

	system("pause");
	return 0;
}
