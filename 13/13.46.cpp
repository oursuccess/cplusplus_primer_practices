#include<vector>
#include<iostream>

using std::cout;
using std::endl;

int f()
{
	cout << "this is a func" << endl;
}

int main()
{
	std::vector<int> vi(100,0);
	int&& r1 = f();
	int& r2 = vi[0];
	int& r3 = r1;
	int&& r4 = vi[0] * f();

	system("pause");
	return 0;
}
