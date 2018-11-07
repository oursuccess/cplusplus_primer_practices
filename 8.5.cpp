//以读模式打开一个文件，将其每个单词作为独立的元素读入到一个string的vector中

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main(int argc,char* argv[])
{
	std::ifstream ifile;
	ifile.open(argv[1],std::fstream::in);
	
	if(ifile){
		std::string s;
		std::vector<std::string> vs;
		while(ifile >> s){
			vs.push_back(s);
		}
		for(auto i : vs){
			std::cout << i << std::endl;
		}
	}else{
		std::cerr << static_cast<std::string>("couldn't open") + argv[1];
	}
	
	system("pause");
	return 0;
}