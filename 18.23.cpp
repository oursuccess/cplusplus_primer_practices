
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class A{
	public:
	A(){ std::cout << "A" << endl; }
};
class B : public A{
	public:
	B(){cout << "B" << endl;}
};
class C : public B{
	public:
	C() { cout << "C" << endl;}
};
class X{
	public:
	X() { cout << "X" << endl;}
};
class Y{
	public:
	Y() { cout << "Y" << endl;}
};
class Z:public X,public Y{
	public:
	Z(){cout << "Z" << endl;}
};
class D : public X, public C{
	public:
		D() { cout << "D" << endl;}
};

class MI: public C, public Z{
	public:
	MI() { cout << "MI" << endl;}
};

int main()
{
	MI m;
	D *pd = new D;
	cout << sizeof(D) << sizeof(pd) << sizeof(*pd) << endl;
	X *px = pd;
	A *pa = pd;
	B *pb = pd;
	C *pc = pd;

	system("pause");
	return 0;
}
