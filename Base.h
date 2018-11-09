#pragma once

class Base{
	public:
		friend class Pal;
		size_t size() const { return n;}

	public:
		void pub_mem();
	protected:
		int prot_mem;
		size_t n;
	private:
		char prov_mem;
};

void Base::pub_mem()
{
}

class Derived : private Base{
	public:
		using Base::size;
	protected:
		using Base::n;
};


struct Pub_Derv : public Base{
	int f() { return prot_mem;}
	char g() { return prot_mem;}
};

struct Priv_Derv : private Base{
	int f1() const { return prot_mem;}
};

struct Proc_Derv : protected Base{
	int f1() const {return prot_mem;}
};

struct Derived_from_Public : public Pub_Derv{
	int use_base() { return prot_mem;}
};

struct Derived_from_Private : public Priv_Derv{
	//error : cannot cast 'derived from private ' to it's private base class 'base' (see line 30)
	//int use_base() { return prot_mem;}
};

struct Derived_from_Protected : public Proc_Derv{
	int use_base() { return prot_mem;}
};

class Sneaky : public Base{
	friend void clobber(Sneaky&);
	friend void clobber(Base&);
	int j;
};

void clobber(Sneaky &s) { s.j = s.prot_mem = 0;}
//error : clobber is not friend of class Base
//void clobber(Base &b){ b.prot_mem = 0;}

class Pal{
	public:
		int f(Base b){return b.prot_mem;}
		//error : j is a private member of 'sneaky'
		//int f2(Sneaky s){return s.j;}
		int f3(Sneaky s){return s.prot_mem;}
};

class D2 : public Pal{
	public:
		//error prot_mem is not public
		//and the derived class is not the friend of Base
		//int mem(Base b){return b.prot_mem;}
};
