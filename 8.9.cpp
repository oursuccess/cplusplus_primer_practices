#include<iostream>
#include<string>
#include<sstream>

std::istream& GetSources(std::istream&);

int main()
{
	std::string line;
	/*
	*为什么^Z在cmd里是空白？
	*9iLhello
	*为什么多次输入^Z + 换行不结束getline 反而要等没有^Z的换行符？
	*/
	getline(std::cin,line);
	std::istringstream iss(line);
	
	GetSources(iss);
	GetSources(iss);
	
	system("pause");
	return 0;
}


std::istream& GetSources(std::istream& is)
{
	std::string s;
	while(!is.eof())
	{
		is >> s;
		std::cout << s;
	}
	
	is.clear();
	
	return is;
}