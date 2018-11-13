#include<tuple>
#include<iostream>

int main()
{
	std::tuple<int,int,int> t = std::make_tuple(10,20,30);
	auto a = std::get<0>(t); 
	auto b = std::get<1>(t); 
	auto c = std::get<2>(t);

	std::cout << a << " b " << b << " c " << c;

	system("pause");
	return 0;
}
