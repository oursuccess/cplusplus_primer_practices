#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

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

	unsigned u;
	std::cin.clear();
	if(std::cin){
		std::cout << " typein the u: ";
		std::cin >> u;
	}
	auto count = count_if(vs.begin(),vs.end(),[u](const std::string &s){return s.size() > u;});
	std::cout << "count is: " << count << std::endl;

	system("pause");
	return 0;
}
