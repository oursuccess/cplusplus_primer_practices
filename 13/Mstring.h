#pragma once
#define _CRT_SECURE_NO_WARNINGS
//string
//include a char* which points to the word
//and has the following operations:
//construct by: char*, const char*, string, default
//operation : +: plus with another string/ char* / const char*; =:assign with another string
//iterator: begin(), end(); and first()/back(); iterators also support ++ and -- operator
#include<memory>
#include<iostream>

using std::allocator;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

class Mstring{
public:
	Mstring(const char* pc = nullptr);
	Mstring(const  Mstring&);
	Mstring(Mstring &&);
	~Mstring();

	//operator
	friend ostream& operator<<(ostream&, const Mstring&);
	friend Mstring operator+(const Mstring& ms1, const Mstring& ms2);
	friend istream& operator>>(istream&, Mstring&);
	Mstring& operator=(const Mstring&);
	Mstring& operator=(Mstring&&);

	//func
	char* getPointer();
	const char* getPointer() const;
	
private:
	static std::allocator<char> alloc;
	void alloc_and_copy(const char *);
	char* ivec;
};

//private member of class need to declare out of class
std::allocator<char> Mstring::alloc;

 void Mstring::alloc_and_copy(const char* pc)
{
	ivec = alloc.allocate(sizeof(pc)/sizeof(char));
	strcpy(ivec,pc);
}

Mstring::Mstring(const char* pc)
{
	//version of houjie
	/*
	//use new and strlen
	ivec = new char[strlen(pc) + 1];
	//copy from the second array to the first
	strcpy(ivec,pc);
	*/
	
	//use allocator
	if(pc)
		alloc_and_copy(pc);
	//need to consider nullptr ;
	//size of a nullptr could not count 
	else ivec = nullptr;
}

Mstring::Mstring(const Mstring& ms)
{
	cout << "this is a copy assign func " << endl;
	alloc_and_copy(ms.getPointer());
}

Mstring::Mstring(Mstring&& ms) noexcept
{
	cout << "this is a move assign func " << endl;
	ivec = ms.ivec;
	ms.ivec = 0;
}

Mstring::~Mstring()
{
	delete ivec;
}

char* Mstring::getPointer()
{
	return ivec;
}

const char* Mstring::getPointer() const
{
	return ivec;
}


ostream& operator<<(ostream& os, const Mstring& ms)
{
	//how to deal if ivec is nullptr?
	//if(ms.getPointer() == nullptr) return os;
	os << (ms.getPointer()?ms.getPointer():"");
	/*
	auto t = ms.getPointer();
	if(t){
		os << "it's not null "<< t;
	}else{
		os << "it's null" << "";
	}
	*/
	//if the Mstring is null, then need to refresh os
	//it is not correct
	//instead, need to change getPointer
	//os.clear();
	return os;
}

Mstring operator+(const Mstring& ms1, const Mstring& ms2)
{
	char* tmp = Mstring::alloc.allocate((sizeof(ms1)+sizeof(ms2))/sizeof(char)-1);
	strcpy(tmp,ms1.getPointer());
	tmp = strcat(tmp,ms2.getPointer());
	return tmp;
}

istream& operator>>(istream& is, Mstring& ms)
{
	char * tmp = Mstring::alloc.allocate(100);
	char * mtotal = Mstring::alloc.allocate(sizeof(mtotal)?sizeof(mtotal)/sizeof(char)*2:200);
	char * total = Mstring::alloc.allocate(sizeof(total)?sizeof(total)/sizeof(char)*2:400);
	while(is >> tmp)
	{
		
	}
	return is;
}

Mstring& Mstring::operator=(const Mstring& ms)
{
	cout << "this is a equal operator func" << endl;
	if(ivec == ms.ivec)
		return *this;
	delete ivec;
	alloc_and_copy(ms.getPointer());
	return *this;
}

Mstring& Mstring::operator=(Mstring&& ms)
{
	cout << "this is a equal operator func" << endl;
	if(ivec == ms.ivec)
		return *this;
	delete ivec;
	ivec = ms.ivec;
	ms.ivec = 0;
	return *this;
}
