#include<iostream>
#include<bitset>

int main()
{
	unsigned b = 2 | (1 << 2) | (1 << 5) | (1 << 8) | (1 << 13) | (1 << 21);
	std::bitset<32> bv(b);

	std::cout << "b" << b << " bv: " << bv << std::endl;

	std::bitset<32> bv2;
	bv2.set(1,1);
	bv2.set(8);
	bv2.set(5,true);

	std::cout << "bv2: " << bv2 << std::endl;

	system("pause");
	return 0;
}
