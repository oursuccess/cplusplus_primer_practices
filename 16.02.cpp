#include<iostream>
#include<string>

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

	if(compare(a,b)) cout << " 1 < 2 " << endl;
	if(compare(s1,s2)) cout << " hello < world " << endl;
	if(compare(d1,d2)) cout << "1.1 < 2.2 " << endl;

	system("pause");
	return 0;
}
