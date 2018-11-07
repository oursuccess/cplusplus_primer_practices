#ifndef PHONES
#define PHONES

#include<vector>
#include<string>

struct PersonInfo{
	
	//var
	std::string name;
	std::vector<std::string> phones;
};


bool valid(const std::string &is)
{
	//&&优先级比||高？
	std::string s{""};
	for(auto c : is)
	{
		//:后面不能没有函数体？
		//isdigit(c)?s+=c:;
		if(isdigit(c))
			s+=c;
	}
	
	//若&&优先级更高，则判断12位s的首数字为0;若更低，则11位的s也同样判断首位
	return s.size() == 11 || s.size() == 8 || s.size() == 12 && s[0] ? true : false;
}

std::string format(const std::string& is)
{	
	std::string s = "";
	unsigned cnt = 0;
	for(auto c : is)
	{
		if(isdigit(c))
		{
			++cnt;
			if(cnt == 3){
				cnt = 0;
				s+=' ';
			}
			s+=c;
		}
	}
	return s;
}

#endif