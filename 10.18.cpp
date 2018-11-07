#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include"10.18.h"

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		std::string s;
		std::vector<std::string> vs;
		while(in >> s){
			vs.push_back(s);
		}

		for(auto i : vs){
			std::cout << i << std::endl;
		}

		int i;
		std::cin >> i;
		biggies(vs,i,argv);
	}

	system("pause");
	return 0;
}

