#include<iostream>
#include<vector>
#include<sstream>

struct PersonInfo{
	
	//var
	std::string name = "zhang";
	std::vector<std::string> phones{"","1"};
};

int main()
{
	std::string line,word;
	std::vector<PersonInfo> people;
	
	while(getline(std::cin,line)){
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	
	for(auto i : people){
		std::cout << i.name << std::endl;
		for(auto j : i.phones){
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	
	system("pause");
	return 0;
}
