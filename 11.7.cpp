#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<fstream>

int main(int argc, char * argv[])
{
	std::string s,afterName;
	std::ifstream in(argv[1]);
	if(in){
		std::map<std::string,std::vector<std::string>> mFamilyName;
		std::ofstream ou(argv[2],std::ofstream::app);

		while(in >> s >> afterName){
			//std::map[] returns a mapped_value
			mFamilyName[afterName].push_back(s);
		}

		for(auto p : mFamilyName){
			std::cout << p.first << ": ";
			ou << p.first << ": ";
			for(auto s : p.second){
				std::cout << s << " ";
				ou << s << " ";
			}
			std::cout << std::endl;
			ou << std::endl;
		}

	}

	system("pause");
	return 0;
}
