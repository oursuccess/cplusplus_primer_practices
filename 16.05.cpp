#include<iostream>

using std::endl;
using std::cout;
using std::begin;
using std::end;

template<typename T>
void print(T &array)
{
	for(auto i = begin(array); i != end(array); ++i)
		cout << *i << "\t";
	cout << endl;
}

int main()
{
	int ia[6]{1,2};
	double da[10]{1.2,3.4,4.5};
	char ca[18] = "hello";


	print(ia);
	print(da);
	print(ca);

	system("pause");
	return 0;
}
