#include<iostream>
#include<fstream>
#include<map>
#include<utility>
#include<string>
#include"11.4.h"

int main(int argc, char* argv[])
{
	std::string s;
	std::ifstream in(argv[1]);
	if(in){
		std::map<std::string,unsigned int> mWordCount;

		std::ofstream ou(argv[2],std::ofstream::app);
		if(ou){
			while(in >> s){
				//discard digits and toupper
				operates(s);
				++mWordCount[s];
			}

			for(auto p : mWordCount){
				std::cout << p.first << " " << p.second << "\t";
				ou << p.first << " " << p.second << "\t";
			}

		}
	}
	else{
		std::cerr << "could not open " << argv[1];
	}

	system("pause");
	return 0;
}
