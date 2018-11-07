#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

void biggies(std::vector<std::string> &, std::vector<std::string>::size_type );
void biggies(std::vector<std::string> &, std::vector<std::string>::size_type, char **);

int main(int argc, char* argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		std::string s;
		std::vector<std::string> vs;

		while(in >> s){
			vs.push_back(s);
		}

		biggies(vs,vs.size());
		biggies(vs,vs.size(),argv);

	}

	system("pause");
	return 0;
}

