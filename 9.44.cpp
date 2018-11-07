#include<iostream>
#include<string>
#include<fstream>

std::string findNReplace(std::string,std::string,std::string);

int main(int argc, char* argv[])
{
	std::string s;
	std::ofstream ou(argv[1],std::ofstream::app);
	std::string oldVal,newVal;
	while(getline(std::cin,s)){
		std::cout << "please type in the words you want to replace: " << std::endl;
		std::cin >> oldVal >> newVal;
		ou << findNReplace(s,oldVal,newVal);
		std::cin.clear();
	}

	system("pause");
	return 0;
}

std::string findNReplace(std::string s, std::string oldVal,std::string newVal)
{
	std::string::iterator istr = s.begin();
	if(s.size() < oldVal.size()){
		return s;
	}else{
		//::difference_type
		std::string::difference_type i = 0;
		while(istr + oldVal.size() != s.end()){
			if(s.substr(istr-s.begin(),oldVal.size()) == oldVal){
				//i shouldn't declare more than once
				i = istr - s.begin();
				s.replace(istr - s.begin(),oldVal.size(),newVal);
				istr = s.begin() + i + newVal.size() - oldVal.size();
			}else{
				++istr;
			}
		}
		return s;
	}
}
