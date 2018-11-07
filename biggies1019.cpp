#ifndef BIGGIES
#define BIGGIES

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

void biggies(std::vector<std::string> &words,std::vector<std::string>::size_type sz,char *argv[])
{

	std::ofstream ou(argv[1],std::ofstream::app);

	if(ou){
		for(auto i : words){
			std::cout << i << "\t";
			ou << i << "\t";
		}

		std::cout << std::endl;
		ou << std::endl;

		ou.close();
	}

	sort(words.begin(),words.end());
	auto end_unique = unique(words.begin(),words.end());
	words.erase(end_unique,words.end());

	ou.open(argv[1],std::ofstream::app);
	if(ou){
		for(auto i : words){
			std::cout << i << "\t";
			ou << i << "\t";
		}

		std::cout << std::endl;
		ou << std::endl;

		ou.close();
	}
	//stable_partition并不返回迭代器
	//上面是错的 应该接受的是一元谓词
	auto end = stable_partition(words.begin(),words.end(),[sz](const std::string &a) -> bool {return a.size() > sz;});
	//这样删除了满足条件的单词。。。
	words.erase(words.begin(),end);


	auto count = words.end() - words.begin();
	std::cout << count << " " << "words of length " << sz << " or longer " << std::endl;
	for_each(words.begin(),words.end(),
			[&ou,argv](const std::string &s){std::cout << s << " ";ou.open(argv[1],std::ofstream::app);ou << s << " ";});
}

#endif
