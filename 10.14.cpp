#include<iostream>

int main()
{
	int i,j;
	std::cin >> i >> j;
	int sum;
	//[capture list](parament list) -> return type {function body} : a lambda
	//[]() -> retype {}() a call of lambda
	sum = [i,j]() -> int {return i + j;}();
	std::cout << sum << std::endl;

	system("pause");
	return 0;
}
