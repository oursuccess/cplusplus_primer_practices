#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class B1{
	public:
	~B1() { cout << "B1d" << endl;}
	virtual void p() { cout << "B1p" << endl; }
};
class B2{
	public:
		~B2(){ cout << "B2d" << endl;}
		virtual void p() { cout << "B2p" << endl;}
};
class D1 : public B1{
	public:
		~D1(){ cout << "D1d" << endl; }
		virtual void p() { cout << "D1p" << endl; }
};
class D2 : public B2{
	public:
		~D2(){cout << "D2d" << endl;}
		virtual void p() { cout << "D2p" << endl; }
};
class MI : public D1, public D2{
	public:
		~MI() { cout << "MId" << endl;}
		virtual void p() { cout << "MIp" << endl; }
};

int main()
{
	B1 *pb1 = new MI;
	B2 *pb2 = new MI;
	D1 *pd1 = new MI;
	D2 *pd2 = new MI;
	pb1 -> p();
	pd2 -> p();
	pd1 -> p();
	delete pb2;
	delete pd1;
	delete pd2;

	system("pause");
	return 0;
}
