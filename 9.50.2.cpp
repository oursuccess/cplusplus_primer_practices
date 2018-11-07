#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main(int argc,char* argv[])
{
	std::vector<std::string> _string;
	std::ifstream in(argv[1]);
	std::string s;
	while(in >> s){
		_string.push_back(s);
	}

	int sum = 0;
	std::ofstream out(argv[2],std::ofstream::app);
	for(int i = 0; i < _string.size(); ++i){
	       sum += stod(_string[i]);
       	       out << stod(_string[i]) << std::endl;
	}
	out << sum << std::endl;

	system("pause");
	return 0;
}
