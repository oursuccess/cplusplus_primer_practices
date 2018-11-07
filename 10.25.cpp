#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<fstream>
#include"10.25.h"

int main()
{
	std::string s;
	std::vector<std::string> vs;
	while(std::cin >> s){
		vs.push_back(s);
	}


	for(auto i : vs){
		std::cout << i << " ";
	}

	int length;
	std::cin.clear();
	std::cout << " type in length: ";
	std::cin >> length;
	biggies(vs,length);
	
	system("pause");
	return 0;
}

