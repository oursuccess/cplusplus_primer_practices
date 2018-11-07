#include<iostream>
#include<string>

int main()
{
	std::string numbers{"0123456789"}, name("r2d2");
	std::cout << numbers.find(name) <<std::endl;
	std::cout << static_cast<unsigned>(-1);

	system("pause");
	return 0;
	}
