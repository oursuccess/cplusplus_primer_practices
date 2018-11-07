#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include"11.33.h"

int main(int argc, char* argv[])
{

	//接受文件，并建立一个两个string的map
	auto TransRules = BuildMap(argv[1]);
	//接受两个文件，从第一个文件读取，按照转换规则将其保存至第二个文件中
	transText(argv[2],TransRules,argv[3]);

	std::ifstream in(argv[3]);
	if(in){
		std::string s;
		while(getline(in,s)){
			std::cout << s << std::endl;
		}
	}

	system("pause");
	return 0;
}
