#include<string>
#include<algorithm>
#include<map>

using namespace std;

const string& transform(const string &s, const map<string,string> &m)
{
	//original
	auto map_it = m.find(s);
	//1134
	//将find改为下标 会报错？
	//no viable overloaded operator [] for const map&
	//auto map_it = m[s];
	if(map_it != m.cend()){
		return map_it -> second;
	}else{
		return s;
	}
}
