#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<iterator>

int main()
{
	std::multiset<std::string> c;
	std::vector<std::string> v;
	copy(v.begin(),v.end(),inserter(c,c.end()));
	copy(v.begin(),v.end(),back_inserter(c));
	copy(c.begin(),c.end(),inserter(v,v.end()));
	copy(c.begin(),c.end(),back_inserter(v));

	return 0;
}
