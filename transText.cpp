//���������ļ�������һ��ת���������������һ���ļ��ж�ȡ���ַ������չ���������ڶ����ļ���

#include<sstream>
#include<string>
#include<memory>
#include<map>
#include<fstream>
#include<iostream>

bool transText(char* inText,std::shared_ptr<std::map<std::string,std::string>> transMap, char *outText)
{
	std::ifstream in(inText);
	if(in){
		std::string s;
		std::ofstream ou(outText,std::ofstream::app);
		
		//test transMap
		for(auto sp : *transMap){
			std::cout << sp.first << "sp->second: " << sp.second << std::endl;
		}

		while(in >> s){
			//��ζ��룿
			std::cout << s  << s.size() << std::endl;
			for(auto sp : *transMap){
				std::cout << "trans " << sp.first << sp.first.size() << std::endl;
				std::cout << "trans after " << sp.second << std::endl;
			}

			auto result = transMap -> find(s);
			std::cout << result -> second << std::endl;
			if(result != transMap -> end()){
				ou << result -> second;
			}else{
				ou << s;
			}

			ou << " ";
		}
		return true;
	}
	return false;
}
