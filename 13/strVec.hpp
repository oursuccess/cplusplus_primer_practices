#pragma once

#include<string>
#include<memory>
#include<utility>

using std::pair;
using std::string;

class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<string> s);
	StrVec(const  StrVec&);
	//move assign
	//StrVec(StrVec &&);
	StrVec &operator=(const StrVec&);
	//move assign
	StrVec &operator=(StrVec &&) noexcept;
	~StrVec();

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements;}
	std::string *begin() const {return elements;}
	std::string *end() const { return first_free; }

	void reserve(size_t);
	void resize(size_t, string = "");

private:
	//alloc 前面不能有static
	std::allocator<std::string> alloc;
	void chk_n_alloc(){ if(size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string *, const std::string*);
	void free();
	void reallocate();
	void reallocate(size_t);
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

StrVec::StrVec(std::initializer_list<string> ls)
{
	reallocate(ls.size() * 2);
	alloc_n_copy(ls.begin(),ls.end());
}

void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string* ,string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if(elements){
		for(auto p = first_free; p != elements;){
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}


StrVec::~StrVec(){ free(); }

StrVec &StrVec::operator=( const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::StrVec(StrVec&& rhs) noexcept
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	if(this != &rhs){
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::reallocate(size_t sz)
{
	auto newcapacity = sz;

	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
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
	if(size > capacity()){
		auto newcapacity = size;
		reallocate(size);
	}
}

void StrVec::resize(size_t sz, string s)
{
	if(sz > capacity()){
		auto newcapacity = sz * 2;
		auto newdata =  alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for(size_t i = 0; i != size(); ++i)
		{
			alloc.construct(dest++,std::move(*elem++));
		}
		free();
		dest = uninitialized_fill_n(dest,sz - size(),s);
		elements = newdata;
		first_free = dest;
		cap = elements + sz;
	}else if(sz > size()){
		first_free = uninitialized_fill_n(first_free,sz-size(),s);
	}else{
		//delete the late elems
		for(size_t i = size() - sz;i;--i){
			alloc.destroy(--first_free);
		}
		alloc.deallocate(first_free,cap-first_free);
	}
}
