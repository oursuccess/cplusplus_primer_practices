#include<iostream>

int main()
{
	std::cout << (3 < 3.14?"y":"n") << std::endl;
	int i = 3;
	double d = 3.14;
	std::cout << (i<d?"y":"n") << std::endl;

	system("pause");
	return 0;
}
