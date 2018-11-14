#include<iostream>
#include<random>

int main()
{
	std::default_random_engine e;
	for(auto i = 0; i != 10; ++i){
		std::cout << e() << std::endl;
	}
	std::cout << e.min() << " and max: " << e.max() << std::endl;

	system("pause");
	return 0;
}
