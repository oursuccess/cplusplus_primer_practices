#include<iostream>
#include<bitset>
#include<string>

int main()
{
	std::cout << std::bitset<64>(32) << std::endl;
	std::cout << std::bitset<32>(1010101) << std::endl;
	std::string s;
	std::cin >> s;
	std::cout << std::bitset<8>(s) << std::endl;

	system("pause");
	return 0;
}
