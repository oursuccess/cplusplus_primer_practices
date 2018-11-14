#include<cstdlib>
#include<iostream>
#include<exception>

int main()
{
	try{
		throw std::range_error("range_error!");
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
		abort();
	}

	system("pause");
	return 0;
}
