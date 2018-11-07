#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<algorithm>

int main(int argc, char* argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		std::string s;
		std::list<std::string> vs;
		while(in >> s){
			vs.push_back(s);
		}

		std::ofstream ou(argv[2],std::ofstream::app);
		if(ou){
			ou << s << "\t";
			std::cout << "请输入要检索的数字: ";
			int i;
			std::cin >> i;
			std::cout << count(vs.begin(),vs.end(),i);
			ou << count(vs.begin(),vs.end(),i);
		}
	}

	system("pause");
	return 0;
}
