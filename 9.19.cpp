
#include<iostream>
#include<string>
#include<list>

int main()
{
	std::string s;
	std::list<std::string> ls;
	while(std::cin >> s){
		ls.push_back(s);
	}

	for(std::list<std::string>::iterator iols = ls.begin(); iols!=ls.end();++iols){
		std::cout << *iols << std::endl;
	}

	system("pause");
	return 0;
}
