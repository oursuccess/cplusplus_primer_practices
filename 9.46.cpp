#include<iostream>
#include<string>
#include<fstream>


std::string autoIndent(std::string ,std::string,std::string );

int main(int argc, char* argv[])
{
	std::string s,pre = "and: ",app = "(s);";
	std::ofstream ou(argv[1],std::ofstream::app);

	while(std::cin >> s){
		ou << autoIndent(s,pre,app) << std::endl;
	}

	system("pause");
	return 0;
}


std::string autoIndent(std::string s,std::string pre,std::string app)
{
	return s.insert(0,pre).insert(s.size(),app);
}
