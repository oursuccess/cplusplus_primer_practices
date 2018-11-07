#include<iostream>
#include<string>
#include"test6.h"

int main()
{
	unsigned base;
	std::string b;
	std::cout << "type in bases";
	std::cin >> base;
	for(unsigned i = 1; i != 200; ++i){
		//c++中有itoa函数
		b =toDifBase(i*i,base);
		if(ispalin(b)){
			std::cout << i << " " << b << std::endl;
		}
	}

	system("pause");
	return 0;
}
