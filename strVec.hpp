#ifndef STRVEC
#define STRVEC

//必须把声明与定义分离 否则即使加了只包含一次的抬头 也会多次编译
//inline函数倒是没事
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
	StrVec &operator=(const StrVec&);
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


#endif
