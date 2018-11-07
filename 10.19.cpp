#include<iostream>
#include<string>
#include<vector>
#include"10.19.h"

int main(int argc, char* argv[])
{
	std::cout << " please typein your words. " << std::endl;
	std::string s;
	std::vector<std::string> vs;
	while(std::cin >> s){
		vs.push_back(s);
	}

	std::cin.clear();
	if(std::cin){
		std::cout << "type in length";
		int i;
		std::cin >> i;
		biggies(vs,i,argv);
	}

	system("pause");
	return 0;
}
