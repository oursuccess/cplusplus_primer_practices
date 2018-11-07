#include<iostream>
#include<map>
#include<string>
#include<vector>

int main()
{
	std::string name,FamilyName;
	std::multimap<std::string,std::string> note;

	while(std::cin >> name >> FamilyName){
		note.insert({name,FamilyName});
	}

	for(auto p : note){
		std::cout << p.first << " " << p.second << std::endl;
	}
	
	system("pause");
	return 0;
}
