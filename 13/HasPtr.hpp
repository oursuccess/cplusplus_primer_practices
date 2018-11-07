#include<memory>
#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::ostream;

using std::shared_ptr;
using std::make_shared;
using std::string;

class HasPtr{
	public:
		HasPtr(const string &s = string()):ps(new string(s)),i(0),useCount(new unsigned(0)){}
		
		//++*ptr  not *++ptr
		HasPtr(const HasPtr& p):ps(p.ps),i(0),useCount(p.useCount){++*useCount;}
		HasPtr& operator=(const HasPtr&);
		HasPtr& operator=(HasPtr &&) noexcept;

		friend void swap(HasPtr&,HasPtr&);
		friend ostream& operator<<(ostream&, const HasPtr&);
		friend bool operator<(const HasPtr&,const HasPtr&);

		~HasPtr();

	private:
		string *ps;
		int i;
		//count of ref of same obj
		unsigned *useCount;
};

//consider self assignment
//value like version
/*
HasPtr& operator=(const HasPtr& p)
{
	//need to free former cache
	//ps = new string(*p.ps);
	//consider if ps is a smart pointer
	//it seems notwrong...
	//auto ds = ps;
	//ps = new string(*p.ps);
	//delete ds;
	
	//standard version
	auto newp = new string(*p.ps);
	delete ps;
	ps = newp;
	i = p.i;
	return *this;
}
*/

//consider assignment failure
//wrong, ignore situation if this is the last one
/*
HasPtr& operator=(const HasPtr& p)
{
	++*p.useCount;
	i = p.i;
	ps = p.ps;
	--*useCount;
	useCount = p.useCount;
	return *this;
}
*/

HasPtr& HasPtr::operator=(const HasPtr& p)
{
	++*p.useCount;
	if(--*useCount == 0){
		delete ps;
		delete useCount;
	}
	ps = p.ps;
	i = p.i;
	useCount = p.useCount;
	return *this;
}

HasPtr& HasPtr::operator=(HasPtr&& p) noexcept
{
	if(this != &p){
		delete ps;
		delete useCount;
		ps = p.ps;
		useCount = p.useCount;
		i = p.i;
		p.ps = nullptr;
		p.i = 0;
	}
	return *this;
}
	

HasPtr::~HasPtr()
{
	--*useCount;
	if(!*useCount){
		delete ps;
		delete useCount;
	}
}

void swap(HasPtr& h1, HasPtr& h2)
{
	using std::swap;
	swap(h1.useCount,h2.useCount);
	cout << "function swap is calling!" << endl;
	swap(h1.ps,h2.ps);
	swap(h1.i,h2.i);
}

ostream& operator<<(ostream& os, const HasPtr& hp)
{
	os << *hp.ps << " " << hp.i << " " << *hp.useCount;
	return os;
}

bool operator<(const HasPtr& h1, const HasPtr& h2)
{
	return *h1.ps < *h2.ps;
}
