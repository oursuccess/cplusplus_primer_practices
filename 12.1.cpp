#include<iostream>
#include"StrBlob.h"

int main()
{
	StrBlob b1;

	StrBlob b2 = {"a","an","the"};
	std::cout << b2 << std::endl;

	b1 = b2;
	std::cout << b1 << " b2: " << b2 << std::endl;

	b2.push_back("about");
	std::cout << b1 << " b2: " << b2 << std::endl;

	system("pause");
	return 0;
}
