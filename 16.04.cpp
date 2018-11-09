#include<vector>
#include<string>
#include<list>
#include<iostream>

using std::vector;
using std::string;
using std::list;
using std::cout;
using std::endl;

template<typename iter, typename T>
iter Mfind(iter beg, iter end, T target)
{
	for(;beg != end; ++beg){
		if(*beg == target) return beg;
	}
	return beg;
}

int main()
{
	vector<int> vi{1,2,3,4,5,6,7,7,8};
	list<string> ls{"hi","i","am","fine","thank","you","and","you","?"};

	cout << *Mfind(vi.begin(),vi.end(),5)<< endl;
	cout << *Mfind(ls.begin(),ls.end(),"and") << endl;

	system("pause");
	return 0;
}
