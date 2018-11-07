#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<functional>

bool check_size(std::string, int);
void print(std::vector<std::string>,char *argv[]);

int main(int argc, char *argv[])
{
	int length;
	std::string s;
	std::vector<std::string> vs;
	std::ofstream ou(argv[1],std::ofstream::app);
	while(std::cin >> s){
		vs.push_back(s);
	}
	print(vs,argv);
	std::cin.clear();
	if(std::cin){
		std::cout << "insert length";
		std::cin >> length;
	}

	auto count = count_if(vs.begin(),vs.end(),bind(check_size,std::placeholders::_1,length));
	std::cout << count;
	ou << count;
	ou.close();

	system("pause");
	return 0;
}

bool check_size(std::string s, int length)
{
	return s.size() >= length;
}

void print(std::vector<std::string> vs,char *argv[])
{
	std::ofstream ou(argv[1],std::ofstream::app);
	for(auto i : vs){
		std::cout << i << "\t";
		ou << i << "\t";
	}
	ou.close();
}
