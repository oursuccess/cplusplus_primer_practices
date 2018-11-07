#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<utility>

int main()
{
	std::string s;
	std::vector<int> vi;
	std::map<std::string,std::vector<int>> mp_svi;
	
	std::pair<std::map<std::string,std::vector<int>>::iterator,bool> testp = mp_svi.insert({"hello",vi});

	return 0;
}
