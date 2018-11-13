#include<string>
#include<iostream>
#include<sstream>

template<typename T>
std::string debug_rep(const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T>
std::string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if(p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

int main()
{
	std::cout << debug_rep("hello");
	std::string s("world");
	std::cout << debug_rep(s); 

	system("pause");
	return 0;
}

