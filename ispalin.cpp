#include<string>

//use a,b,c to display hex or other bases more than 


bool ispalin(const unsigned u)
{
	std::string s;
	s = std::to_string(u);
	std::string front(s.cbegin(), s.cbegin() + s.size() / 2);
	std::string back(s.crbegin(), s.crbegin() + s.size() / 2);
	return front == back ? true : false;
}


bool ispalin(const std::string &s)
{
	std::string front(s.cbegin(),s.cbegin() + s.size()/2);
	std::string back(s.crbegin(),s.crbegin() + s.size()/2);
	return front == back ? true : false;
}
