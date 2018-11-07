#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>

bool isLongerThan5(const std::string& s);

int main(int argc, char* argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		std::string s;
		std::vector<std::string> vs;
		while(in >> s){
			vs.push_back(s);
		}

		std::ofstream ou(argv[2],std::ofstream::app);
		for(auto s : vs){
			std::cout << s << std::endl;
			ou << s << "\t";
		}
		ou << std::endl;
		std::cout << std::endl;

		auto end = partition(vs.begin(),vs.end(),isLongerThan5);
		for(auto vec = vs.begin(); vec != end;++vec){
			std::cout << *vec << std::endl;
			ou << *vec << "\t";
		}
	}

	system("pause");
	return 0;
}

bool isLongerThan5(const std::string& s)
{
	return s.size() > 5;
}

