#include<iostream>
#include<string>
#include<map>

int main()
{
	std::string word;
	std::map<std::string,size_t> word_count;
	while(std::cin >> word){
		++word_count.insert({word,0}).first->second;
	}

	for(auto p : word_count){
		std::cout << p.first << " " << p.second << std::endl;
	}

	system("pause");
	return 0;
}
