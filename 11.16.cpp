#include<iostream>
#include<map>

int main()
{
	//map<,> {{,},{,}}
	std::map<int,char> mic{{1,'c'},{2,'d'},{3,'s'}};
	std::map<int,char>::iterator iom = mic.begin();
	std::cout << iom -> first << " " << iom -> second << std::endl;
	iom -> second = 'g';

	std::cout << iom -> first << " " << iom -> second << std::endl;

	system("pause");
	return 0;
}
