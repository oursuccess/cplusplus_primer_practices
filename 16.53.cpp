#include<iostream>

using std::ostream;

template <typename T, typename...Args>
ostream &print(ostream &os, const T &t, const Args ...rest)
{
	os << t << ",";
	return print (os, rest...);
}

template <typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

int main()
{
	print(std::cout, "this","is","a","test","word","to","show");

	system("pause");
	return 0;
}
