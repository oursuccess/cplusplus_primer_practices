//额 怎么在输入s的时候只保存整数？
//i.find_fisrt_of returns a very large int and cause a ub(越界)
//为什么会打不出来sum？
#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<fstream>

int main(int argc, char * argv[])
{
	std::vector<std::string> vs;
	std::string s;
	std::ifstream in(argv[1]);
	while(in >> s){
		vs.push_back(s);
	}

	long long sum = 0;
	std::ofstream out(argv[2],std::ofstream::app);
	for(auto i : vs){
		out << i << std::endl;
		sum += stoi(i.substr(i.find_first_of("+-.0123456789")));
	}

	out << sum << std::endl;


	system("pause");
	return 0;
}
