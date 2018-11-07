#include<iostream>
#include<fstream>
#include<string>
#include<vector>


//输入参数：
/*
*cmd:
*%.exe argv[1] argv[2] ...
*argc自动生成
*/

int main(int argc,char *argv[])
{
	std::ifstream ifile;
	ifile.open(argv[1],std::ifstream::in);
	if(ifile){
		std::string s;
		std::vector<std::string> vs;
		while(getline(ifile,s)){
			vs.push_back(s);
		}
		
		for(auto i : vs){
			std::cout << i << std::endl;
		}
	}
	else{
		std::cerr << static_cast<std::string>("couldn't open") + argv[1];
	}
	
	system("pause");
	return 0;
}