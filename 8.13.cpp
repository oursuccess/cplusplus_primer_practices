#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include"8.13.h"

int main(int argc,char* argv[])
{
	std::ifstream op(argv[1],std::ifstream::in);
	if(op){
		std::string line,word;
		std::vector<PersonInfo> people;
		
		while(getline(op,line))
		{
			PersonInfo info;
			std::istringstream record(line);
			record >> info.name;
			while(record >> word)
				info.phones.push_back(word);
			people.push_back(info);
		}
		
		
		for(const auto &entry : people){
			std::ofstream ou;
			//这里不能直接写8.13 要输入argv[2]
			ou.open(argv[2],std::ostream::app);
			if(ou){
				std::ostringstream formatted,badNums;
				for(const auto& nums : entry.phones){
					if(!valid(nums)){
						badNums << " " << nums;
					}else{
						//上面的entry就是const的了
						formatted << " " << format(nums);
					}
				}
				if(badNums.str().empty()){
					std::cout << entry.name << " " << formatted.str() << std::endl;
					ou << entry.name << " " << formatted.str() << std::endl;
				}else{
					std::cerr << "input error: " <<entry.name << " invalid number(s) " << badNums.str() << std::endl;
					ou << "input error: " <<entry.name << " invalid number(s) " << badNums.str() << std::endl;
				}
			}
		}
	}
	
	system("pause");
	return 0;
}