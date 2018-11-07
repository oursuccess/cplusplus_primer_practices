#include<string>

void operates(std::string &s)
{
	std::string stemp;
	for(auto c : s){
		if(!ispunct(c)){
			stemp += tolower(c);
		}
	}

	s = stemp;
}
