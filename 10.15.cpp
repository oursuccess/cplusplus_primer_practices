#include<iostream>

int main()
{
	int i,j;
	while(std::cin >> i >> j){
		std::cout << [i](int j) -> int {return i + j;}(j) << std::endl;
	}

	system("pause");
	return 0;
}
