#include<iostream>
#include<string>
//sstream, not stringstream
#include<sstream>
#include<vector>

struct PersonInfo{
	std::string name;
	//这里的string还需要声明命名空间吗？
	//需要
	std::vector<std::string> phones;
};

int main()
{
	std::string line,word;
	std::vector<PersonInfo> people;
	
	/*
	while(getline(std::cin,line)){
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	*/
	
	//不使用sstream
	//string似乎没有>>运算?
	while(getline(std::cin,line)){
		PersonInfo info;
		//error: no match for 'operator>>' (operand types are 'std::__cxx11::string' {aka 'std::__cxx11::basic_string<char>'} and 'std::__cxx11::string' {aka 'std::__cxx11::basic_string<char>'})
		line >> info.name;
		while(line >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	
	
	system("pause");
	return 0;
}