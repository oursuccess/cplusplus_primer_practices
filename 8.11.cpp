/*
*如果将record定义于while循环之外，应该怎样修改？
*
*
*
*/

//在循环内的版本
/*
#include<vector>
#include<string>
#include<sstream>
#include<iostream>

struct PersonInfo{
	
	//var
	std::string name;
	std::vector<std::string> phones;
};


int main()
{
	std::string line,word;
	std::vector<PersonInfo> people;
	//逐行从输入读取数据，直到cin遇到文件尾
	while(getline(std::cin,line)){
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	
	for(auto info : people){
		std::cout << info.name << " ";
		for(auto word : info.phones){
			std::cout << word << std::endl;
		}
	}
	
	system("pause");
	return 0;
}
*/

//循环外
//先声明，在循环内再与line绑定可以吗？
//不可以使用record(line)
//record.str(line)后，将只能保存第一行
//*istringstream只绑定一次?
//record无法直接输出至ostream
/*
//第二次循环之后record不再更新line内容
//*record.str(line)本来就是使用line的值的副本为record绑定
//上面是错误的，record与line保持一致
*/
//如果在循环外将record与line绑定呢？

#include<vector>
#include<string>
#include<sstream>
#include<iostream>

struct PersonInfo{
	
	//var
	std::string name;
	std::vector<std::string> phones;
};

//解法1
/*
int main()
{
	std::string line,word;
	std::vector<PersonInfo> people;
	std::istringstream record;
	//逐行从输入读取数据，直到cin遇到文件尾
	while(getline(std::cin,line)){
		PersonInfo info;
		record.str(line);
		
		
		//调试
		//std::cout << line << std::endl;
		//std::string temps;
		// temps在第二次循环之后为空字符串
		//record >> temps;
		//std::cout << temps.length() << temps << std::endl;
		//rerord呢?
		//record与line保持一致
		//std::cout << record.str() << std::endl;
		
		
		
		//下面为错误语句
		//std::cout << record <<std::endl;
		
		
		
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		
		
		//大佬的解法
		//
		record.clear();
		record.seekg(0,std::ios_base::beg);
		
	}
	
	for(auto info : people){
		std::cout << info.name << " ";
		for(auto word : info.phones){
			std::cout << word << std::endl;
		}
	}
	
	system("pause");
	return 0;
}
*/

//思路2
//似乎record在绑定之后就不会更新了？
//嗯，record无内容
int main()
{
	std::string line,word;
	std::vector<PersonInfo> people;
	std::istringstream record(line);
	//逐行从输入读取数据，直到cin遇到文件尾
	
	while(getline(std::cin,line)){
		PersonInfo info;
		
		std::cout << record.str() << std::endl;
		
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		
	}
	
	for(auto info : people){
		std::cout << info.name << " ";
		for(auto word : info.phones){
			std::cout << word << std::endl;
		}
	}
	
	system("pause");
	return 0;
}