#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<char> vc;
	std::string s;
	while(std::cin >> s){
		for(auto c : s){
			vc.push_back(c);
		}
	}

	std::string str(vc.begin(),vc.end());

	std::cout << str << std::endl;

	system("pause");
	return 0;
}
