#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::string s;
	std::vector<std::string> vs;
	while(std::cin >> s){
		vs.insert(vs.begin(),s);
	}

	for(auto s : vs){
		std::cout << s << std::endl;
	}

	system("pause");
	return 0;
}
