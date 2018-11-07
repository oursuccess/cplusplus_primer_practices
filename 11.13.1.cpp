#include<iostream>
#include<string>
#include<utility>
#include<vector>

int main()
{
	int i = 1;
	std::string s = "s";
	
	auto p1 = make_pair(s,i);
	std::pair<std::string,int> p2 = std::pair<std::string,int>(s,i);
	std::pair<std::string,int> p3{s,i};

	std::cout << p1.first << " " << p1.second << std::endl;
	std::cout << p2.first << " " << p2.second << std::endl;
	std::cout << p3.first << " " << p3.second << std::endl;

	system("pause");
	return 0;
}
