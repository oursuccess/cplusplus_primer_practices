#include<iostream>

template<typename T>
void f(T)
{
	std::cout << "f1" << std::endl;
}

template<typename T>
void f(const T*)
{
	std::cout << "f2" << std::endl;
}

template<typename T>
void g(T)
{
	std::cout << "g1" << std::endl;
}

template<typename T>
void g(T*)
{
	std::cout << "g2" << std::endl;
}

int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &i;

	g(42);
	g(p);
	g(ci);
	g(p2);
	f(42);
	f(p);
	f(ci);
	f(p2);
	
	system("pause");
	return 0;
}
