/*
*将文件中的行
*保存至vector<string>中
*然后使用istringstream从vector中读取元素
*每次读取一个单词
*/

//中文被识别为乱码


#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>

int main(int argc,char* argv[])
{
	//ifstream对象无法在if中创建
	std::ifstream file(argv[1]);
	if(file){
		std::string is;
		std::vector<std::string> vs;
		while(getline(file,is))
		{
			vs.push_back(is);
		}
		
		for(auto i:vs){
			std::istringstream iss(i);
			std::string word;
			while(iss >> word){
				std::cout << word << std::endl;
			}
		}
	}else{
		std::cerr << static_cast<std::string>("could not open") + argv[1];
		
	}
	
	system("pause");
	return 0;
}