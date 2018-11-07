#ifndef BIGGIES
#define BIGGIES

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz,char *argv[])
{
	auto end_unique = partition(words.begin(), words.end(),[sz](const std::string &s) -> bool { return s.size() >= sz;});
	auto count = end_unique - words.begin();
	std::ofstream ou(argv[2],std::ofstream::app);
	for(auto s : words){
		std::cout << s << "\t";
		ou << s << "\t";
	}
	ou << std::endl;
	ou.close();

	words.erase(end_unique,words.end());

	ou.open(argv[2],std::ofstream::app);
	for(auto s : words){
		std::cout << s << "\t";
		ou << s << "\t";
	}
	ou << std::endl;
	ou.close();

	std::cout << count << " " << "words" << " of length " << sz << " or longer " << std::endl;
	for_each(words.begin(), words.end(),[](const std::string &s){std::cout << s << "\t";});
}


#endif
