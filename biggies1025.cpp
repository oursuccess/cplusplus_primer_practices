#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>

//bind与泛型算法无法分辨重载函：数
bool checksize(const std::string s,const int length);
bool check_size(const std::string s1, const std::string s2);

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
	sort(words.begin(),words.end());
	auto end_unique = unique(words.begin(),words.end());
	words.erase(end_unique,words.end());

	stable_sort(words.begin(),words.end(),check_size);
	
	for(auto s : words){
		std::cout << s << " ";
	}

	auto end = stable_partition(words.begin(), words.end(),bind(checksize,std::placeholders::_1,sz));
	for(auto s : words){
		std::cout << s << " ";
	}
	std::cout << std::endl;

	words.erase(end,words.end());
	auto count = words.size();
	std::cout << "words has " << count << "words of length more than " << sz << std::endl;
	for_each(words.begin(),words.end(),[](const std::string &s){std::cout << s << " " ;});

}

bool checksize(const std::string s, const int length)
{
	return s.size() > length;
}

bool check_size(const std::string s1, const std::string s2)
{
	return s1.size() > s2.size();
}
