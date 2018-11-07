#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main(int argc, char* argv[])
{
	std::ifstream ifile;
	ifile.open("text.txt",std::ifstream::in);
	if(ifile){
		std::vector<std::string> vs;
		std::string s;
		while(getline(ifile,s)){
			vs.push_back(s);
		}
		
		/*
		*for声明于if外时：
		*error 'vs' was not declared in this scope
		*for(auto i : vs){
		*error 'else' without a previous 'if'
		*else{
		*/
		for(auto i:vs){
			std::cout << i << std::endl;
		}
	}
		
	else{
		std::cerr << "couldn't open test.txt";
	}
	
	
	system("pause");
	return 0;
}