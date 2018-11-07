#include<vector>
#include<iostream>
#include<string>

using namespace std;

struct test{
	test(){cout << "test()" << endl;}
	test(const test&){cout << "const test&" << endl;}
	test& operator=(const test& rhs){cout << "=" << endl; return *this;}
	
	~test(){cout << "~" << endl;}

};

void f1(test t){}
void f2(test &t){}

int main()
{
	cout << "jububianliang" << endl;
	test t1;
	cout << endl;

	cout << "费引用参数传递 " << endl;
	f1(t1);
	cout << endl;

	cout << "reference arguement " << endl;
	f2(t1);
	cout << endl;

	cout << "dynamical allocate" << endl;
	test* pt = new test;
	cout << endl;

	cout << "add to container" <<endl;
	vector<test> vt;
	vt.push_back(t1);
	vt.push_back(*pt);
	cout << endl;

	cout << "delete" << endl;
	delete pt;
	cout << endl;

	cout << "jianjie chushihua he fuzhi" << endl;
	test t2 = t1;
	t2 = t1;
	cout << endl;

	system("pause");
	return 0;
}
