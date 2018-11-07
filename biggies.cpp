#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b){return a.size() < b.size();});
	auto wc = find_if(words.begin(), words.end(), [sz](const std::string &a){return a.size() >= sz;});

	auto count = words.end() - wc;
	std::cout << count << " " << make_plural(count,"words","s") << "of length " << sz << " or longer" << std::endl;

	for_each(wc,words.end(),[](const std::string &s){std::cout << s << " " ;});
	std::cout << std::endl;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz,char *argv[])
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b){return a.size() < b.size();});
	auto wc = find_if(words.begin(), words.end(), [sz](const std::string &a){return a.size() >= sz;});

	auto count = words.end() - wc;
	std::ofstream ou(argv[2],std::ofstream::app);
	if(ou){
		ou << count << " " << make_plural(count,"words","s") << "of length " << sz << " or longer" << std::endl;

		for_each(wc,words.end(),[](const std::string &s){ou << s << " " ;});
		ou << std::endl;
}
