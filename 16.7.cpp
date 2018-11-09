#include<iostream>
#include<string>

using namespace std;

template<typename T, size_t N>
constexpr int arr_size(const T (&a)[N])
{
	return N;
}

int main()
{
	int a[6] = {0,2,4,5,6,8};
	string vs[3] = {"hello"};

	cout << arr_size(a);

	system("pause");
	return 0;
}
