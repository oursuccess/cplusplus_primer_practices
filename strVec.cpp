#include<string>
#include<memory>
#include<utility>
#include<algorithm>
#include"strVec.hpp"

StrVec::StrVec(std::initializer_list<string> ls)
{
	reallocate(ls.size() * 2);
	alloc_n_copy(ls.begin(), ls.end());
}

void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements) {
		//delete use for loop
		/*
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		}
		*/
		//catch this in lambda
		//s should be string
		//泛型算法：对元素迭代器进行操作 但谓词应该接受的是元素
		//[this](string &s) {alloc.destroy(&s);}
		for_each(elements, first_free, [this](string& ps)->void {alloc.destroy(&ps); });
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate(size_t sz)
{
	auto newcapacity = sz;

	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	reallocate(newcapacity);
}

void StrVec::reserve(size_t size)
{
	if (size > capacity()) {
		auto newcapacity = size;
		reallocate(size);
	}
}

void StrVec::resize(size_t sz, string s)
{
	if (sz > capacity()) {
		auto newcapacity = sz * 2;
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; i != size(); ++i)
		{
			alloc.construct(dest++, std::move(*elem++));
		}
		free();
		dest = uninitialized_fill_n(dest, sz - size(), s);
		elements = newdata;
		first_free = dest;
		cap = elements + sz;
	} else if (sz > size()) {
		first_free = uninitialized_fill_n(first_free, sz - size(), s);
	} else {
		//delete the late elems
		for (size_t i = size() - sz; i; --i) {
			alloc.destroy(--first_free);
		}
		alloc.deallocate(first_free, cap - first_free);
	}
}
