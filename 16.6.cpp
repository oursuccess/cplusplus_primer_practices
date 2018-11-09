#include<iostream>

using std::cout;
using std::endl;

template<typename arr, size_t N>
const arr* begin(const arr (&a)[N])
{
	return &a[0];
}

template<typename arr, size_t N>
const arr* end(arr (&a)[N])
{
	return &a[sizeof(a)/sizeof(*arr) - 1];
}

int main()
{
	int ia[] = {1,2,3,45,6,7,8};
	double da[]{12,2.2};
	char ca[]("hello world");

	cout << *begin(ia) << " " << *begin(da) << " " << *begin(ca) << endl;

	system("pause");
	return 0;
}
