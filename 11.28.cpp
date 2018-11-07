#include<iostream>
#include<string>
#include<vector>
#include<map>

int main()
{
	std::map<std::string,std::vector<int>> mp_svi;
	std::string s;
	int i;
	while(std::cin >> s){
		while(std::cin >> i){
			mp_svi[s].push_back(i);
		}
		std::cin.clear();
	}

	for(auto p : mp_svi){
		std::cout << p.first << " ";
		for(auto i : p.second){
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cin.clear();
	std::cin >> s;

	std::map<std::string,std::vector<int>>::iterator iter = mp_svi.find(s);
	std::cout << iter -> first << " ";
	for(int i : iter -> second){
		std::cout << i << " ";
	}

	system("pause");
	return 0;
}
