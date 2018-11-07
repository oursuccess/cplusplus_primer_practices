//接受一个文件名参数，读取转换文件，保存转换规则
#include<memory>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<iostream>

std::shared_ptr<std::map<std::string,std::string>> BuildMap(char * argv)
{
	std::ifstream in(argv);
	if(in){
		std::string pre,after,word,line,transDigit = ":",endDigit = ";";
		std::shared_ptr<std::map<std::string,std::string>> map = std::make_shared<std::map<std::string,std::string>>();
		while(getline(in,line)){
			std::istringstream iss(line);
			while(iss >> word && word != transDigit){
				//在真正读入需要转化的关键字前，多加了一个空格，而且这样也无法将具有空格不同的单词转换掉
				//逐个单词转换应该更好?
					pre += word + " ";
			}
			//不支持-= 只能用erase(pos,len) len可省略
			pre.erase(pre.size()-1);
			while(iss >> word && word != endDigit){
				after += word + " ";
			}

			auto ins = map -> insert({pre,after});
			
			std::cout << "ins.first: " << ins.first -> first << " ins.second: " << ins.first -> second << std::endl;

			if(!ins.second){

			}
		}
		return map;
	}else{

	}
}
