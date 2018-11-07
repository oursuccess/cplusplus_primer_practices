#include<iostream>
#include<string>

//需要预先声明函数
std::istream& GetSources(std::istream&);

int main()
{
	GetSources(std::cin);
	GetSources(std::cin);
	
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