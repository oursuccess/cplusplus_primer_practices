#include<map>
#include<list>
#include<iostream>
#include<fstream>
#include<sstream>

int main(int argc, char* argv[])
{
	//multimap<unsigned,string>
	std::map<unsigned,std::list<std::string>> mOccuredLines;
	std::string s,word;
	unsigned line = 0;
	std::ifstream in(argv[1]);
	//istringstream, not oss
	while(getline(in,s)){
		++line;
		//ss donot have open and close
		std::istringstream iss(s);
		while(iss >> word){
			mOccuredLines[line].push_back(word);
		}
	}

	std::ofstream ou(argv[2],std::ofstream::app);
	for(auto p : mOccuredLines){
		std::cout << p.first << ": ";
		ou<< p.first << ": ";
		for(auto s : p.second){
			std::cout << s << " ";
			ou << s << " ";
		}
		std::cout << std::endl;
		ou << std::endl;
	}

	system("pause");
	return 0;
}
