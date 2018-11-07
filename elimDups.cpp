#include<vector>
#include<string>
#include<algorithm>

void elimDups(std::vector<std::string> &vs)
{
	sort(vs.begin(),vs.end());
	auto end = unique(vs.begin(),vs.end());
	vs.erase(end,vs.end());
}
