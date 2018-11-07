#include<iostream>
#include<string>
#include<map>

int main()
{
	std::string s;
	unsigned count;
	std::map<std::string,unsigned> word_count;

	while(std::cin >> s){
		auto ins = word_count.insert({s,1});
		//insert returns a pair(in utility): pair<iterator of word_count.find(s),bool>
		if(!ins.second){
			++ins.first -> second;
		}

	}

	for(auto p : word_count)
	{
		std::cout << p.first << " " << p.second << std::endl;
	}


	system("pause");
	return 0;
}
