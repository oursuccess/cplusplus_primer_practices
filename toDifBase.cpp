#include<string>

std::string toDifBase(unsigned u, const unsigned base)
{
	std::string s;
	unsigned i;
	do{
		i = u % base;
		if(i<=9)
			s += i + '0';
		else
			s += i - 10 + 'a';
		u /= base;
	}while(u);

	reverse(s.begin(),s.end());
	return s;
}
