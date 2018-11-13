#include<iostream>

template<typename T>
void g(T&& val)
{
	std::cout << "val: " << val << "\t&val: " << &val << std::endl;
}

int main()
{
	int i = 0;
	const int ci = i;
	std::cout << "&i: " << &i << std::endl;
	std::cout << "&ci: " << &ci << std::endl;
	g(i);
	g(ci);
	g(i * ci);

	system("pause");
	return 0;
}
