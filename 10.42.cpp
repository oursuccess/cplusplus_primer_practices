#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<fstream>
#include<stdexcept>

void elimDups(std::list<std::string> &words);

int main(int argc,char* argv[])
{
	std::list<std::string> ls;
	std::ifstream in(argv[1]);
	if(in){
		std::ofstream ou(argv[2],std::ofstream::app);
		if(ou){
			std::string s;
			while(in >> s){
				ls.push_back(s);
			}

			for(auto s : ls){
				std::cout << s << " ";
				ou << s << " ";
			}

			ls.sort();
			ls.unique();

			std::cout << std::endl;
			ou << std::endl;

			for(auto s : ls){
				std::cout << s << " ";
				ou << s << " ";
			}

			ou.close();
		}
		else{
			std::cerr << "could not open " << argv[2];
		}
	}
	else{
		throw std::runtime_error(std::string("could not open") + argv[1]);
	}

	system("pause");
	return 0;
}
