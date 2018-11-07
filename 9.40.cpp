//in mingw the size is 1024 1024 2000 2000
#include<iostream>
#include<string>
#include<vector>

int main()
{
	std::vector<std::string> svec;
	svec.reserve(1024);
	std::cout << "svec.size: " << svec.size() << " svec.capacity: " << svec.capacity() << std::endl;

	//use assign(n,t) not static_cast
	svec.assign(256,"test");
	svec.resize(svec.size() + svec.size()/2);
	std::cout << "svec.size: " << svec.size() << " svec.capacity: " << svec.capacity()<< std::endl;

	
	svec.assign(512,"test");
	svec.resize(svec.size() + svec.size()/2);
	std::cout << "svec.size: " << svec.size() << " svec.capacity: " << svec.capacity() << std::endl;


	svec.assign(1000,"test");
	svec.resize(svec.size() + svec.size()/2);
	std::cout << "svec.size: " << svec.size() << " svec.capacity: " << svec.capacity() << std::endl;


	//error: invalid conversion from const char* to vector<string>
	svec.assign(1000,"test");
	svec.resize(svec.size() + svec.size()/2);
	std::cout << "svec.size: " << svec.size() << " svec.capacity: " << svec.capacity() << std::endl;

	system("pause");
	return 0;
}
