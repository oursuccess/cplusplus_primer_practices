#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include"10.11.h"

int main(int argc,char* argv[])
{
	std::vector<std::string> vs;
	std::string s;
	std::ofstream ou(argv[1],std::ofstream::app);

	while(std::cin >> s){
		vs.push_back(s);
	}

	for(auto s : vs){
		std::cout << s << std::endl;
		ou << s << '\t';
	}

	elimDups(vs);
	stable_sort(vs.begin(),vs.end(),isShorter);

	for(auto s : vs)
	{
		std::cout << s <<std::endl;
		ou << s << '\t';
	}

	system("pause");
	return 0;
}
