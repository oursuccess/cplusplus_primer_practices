#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<iterator>

using namespace std;

int main()
{
	string s;
	map<string,int> word_count;
	//const p*  指向const的p  // 后面的是错的p const* 指针const
	//p *const
	//map的迭代器解引用后为ref of pair 而非iterator
	//pair没有iterator成员 习题集答案错误
	//::map<::string,size_t>::iterator iowoc = word_count.cbegin();
	//const pair<const string, size_t>::iterator i = word_count.cbegin();
	map<string, int>::const_iterator iowoc = word_count.cbegin();
	auto j = word_count.cbegin();

	return 0;
}
