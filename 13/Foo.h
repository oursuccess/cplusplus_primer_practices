#pragma once

#include<vector>
#include<algorithm>
#include<iostream>

using std::ostream;
using std::vector;

class Foo{
	public:
		Foo():data(){};
		Foo(const vector<int> vi):data(vi){}
		Foo(const Foo& f):data(f.data){}
		Foo(std::initializer_list<int> li){for(auto beg = li.begin(); beg != li.end(); ++beg) data.push_back(*beg);} 

		friend ostream& operator<<(ostream&, const Foo&);
		void push_back(int);
		Foo sorted() &&;
		Foo sorted() const&;

	private:
		vector<int> data;
};

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}

//correct version
Foo Foo::sorted() const &
{
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret;
}

//15.56
//���벻������ִ��ʱ����
/*
Foo Foo::sorted() const&
{
	Foo ret(*this);
	return ret.sorted();
}
*/

//15.57
//ͬ���Ǳ���ʱ���ӣ���ִ��ʱ����
//�������������ȼ� �����Ƕ�this����sort����
/*
Foo Foo::sorted() const&
{
	return Foo (*this).sorted();
}
*/

void Foo::push_back(int i)
{
	data.push_back(i);
}

ostream& operator<<(ostream& os, const Foo& f)
{
	for(auto i : f.data)
	{
		os << i << "\t";
	}
	return os;
}
