#include<iostream>
#include<string>
#include"Employee.h"

using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::endl;

int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	Employee e1(s1), e2(s2), e3(s3);
	cout << e1 << e2 << e3 << endl;
	Employee e4(e1), e5(e1);
	e3 = e2 = e1;
	cout << e1 << e2 << e3  << e4 << e5 << endl;


	system("pause");
	return 0;
}
