#include<iostream>
#include<string>
#include"Mstring.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	//Mstring ms1;
	Mstring ms2("hello");
	Mstring ms3("world");
	Mstring ms1;
	//ms1 = ms2 + ms3;
	//could not cout a nullptr, but you can cout a default string
	/*
	string s;
	string *ps = nullptr;
	cout << "defalut construct" << s << "\tnullptr of string" << *ps;
	*/
	cout << "ms1: " << ms1 << "\tms2: " << ms2 << "\tms3: " << ms3 << endl;
	ms1 = ms2 + ms3;
	cout << "ms1: " << ms1 << "\tms2: " << ms2 << "\tms3: " << ms3 << endl;
	Mstring ms4(ms1);
	ms1 = ms2;
	cout << "ms1: " << ms1 << "\tms2: " << ms2 << "\tms3: " << ms3 << "\tms4:" << ms4 << endl;

	system("pause");
	return 0;
}