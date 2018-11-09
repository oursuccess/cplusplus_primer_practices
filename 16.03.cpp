
#include<iostream>
#include<string>
#include"Sales_data.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

template<typename T >
bool compare(T a, T b){
	return a < b;
}

int main()
{
	int a = 1, b = 2;
	string s1 = "hello", s2 = "world";
	double d1 = 1.1, d2 = 2.2;

	Sales_data item1("item1",10,5), item2("item2",5,5);

	if(compare(a,b)) cout << " 1 < 2 " << endl;
	if(compare(s1,s2)) cout << " hello < world " << endl;
	if(compare(d1,d2)) cout << "1.1 < 2.2 " << endl;
	//error : invalid operator <
	if(compare(item1,item2)) cout << "item1 < item2" <<endl;

	system("pause");
	return 0;
}
