#include<iostream>
#include<map>
#include<string>
#include<utility>

int main()
{
	std::string s;
	std::map<std::string,unsigned> mWordCount;
	while(std::cin >> s){
		++mWordCount[s];
	}

	for(auto s : mWordCount){
		//not mWordCount use s
		std::cout <<s.first << " " << s.second << "\t";
	}

	system("pause");
	return 0;
}
