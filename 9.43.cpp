#include<iostream>
#include<fstream>
#include<string>

std::string findNReplace(std::string,std::string,std::string);

int main(int argc, char* argv[])
{
	std::string s;
	std::ifstream in(argv[1]);
	if(in){
		std::string stemp;
		std::ofstream ou(argv[2],std::ofstream::app);
		//getline(std::istream,std::string)
		std::string oldVal,newVal;
			std::cout << "please type in the vals you want to replace and their replacement: " << std::endl;
			std::cin >> oldVal >> newVal;
		while(getline(in,s)){
			ou << findNReplace(s,oldVal,newVal);
		}
	}

	system("pause");
	return 0;
}

std::string findNReplace(std::string s, std::string oldVal, std::string newVal)
{
	if(s.size() < oldVal.size()){
		return s;
	}else{
		std::string::iterator istr = s.begin();
		while(istr + oldVal.size() != s.end()){
			if(s.substr(istr-s.begin(),oldVal.size()) == oldVal){
				//s.insert(istr,newVal.begin(),newVal.end()) or s.insert(pos,str)
				istr = s.insert(istr,newVal.begin(),newVal.end());
				istr += newVal.size();
				//s.erase(istr,istr) or s.erase(pos,len) the last one return a ref of s
				istr = s.erase(istr, istr + oldVal.size());
			}
			else{
				++istr;
			}
		}
		return s;
	}
}
