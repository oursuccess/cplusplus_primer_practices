//����һ���ļ�����������ȡת���ļ�������ת������
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
				//������������Ҫת���Ĺؼ���ǰ�������һ���ո񣬶�������Ҳ�޷������пո�ͬ�ĵ���ת����
				//�������ת��Ӧ�ø���?
					pre += word + " ";
			}
			//��֧��-= ֻ����erase(pos,len) len��ʡ��
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
