
#include<iostream>

using std::cout;
using std::endl;

class numbered{
	public:
		//constructor
		numbered(){i = seq++;}
		friend void f(const numbered&);
		numbered(const numbered& nu){i = seq++;}

	private:
		int i;
		static int seq;
};

//is this necessary?
//yes read chap7
//you can define a static member of class out the class , only could not repeat static
int numbered::seq = 0;

void f( const numbered &s){cout << s.i << endl;}


int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	system("pause");
	return 0;
}

