#include<iostream>
#include<fstream>

//一个递减变量值至0的lambda

int main()
{
	int i;
	while(std::cin >> i){
		if([&i]() -> bool{ return --i;}())
			std::cout << i << " ";
	}

	system("pause");
	return 0;
}
