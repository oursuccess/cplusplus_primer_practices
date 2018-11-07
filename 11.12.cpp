#include<iostream>
#include<string>
#include<utility>
#include<vector>

int main()
{
	std::string s;
	int i;
	std::vector<std::pair<std::string,int>> vp;
	std::pair<std::string,int> p; 
	while(std::cin >> s >> i){
		p = make_pair(s,i);
		vp.push_back(p);
	}

	for(auto p : vp){
		std::cout << p.first << " " << p.second;
	}

	system("pause");
	return 0;
}
