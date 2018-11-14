#include<iostream>

namespace Exercise{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
//first:
//using namespace Exercise;
//error : reference to ivar is ambigious

int ivar = 0;

int main()
{
	//second:
	using namespace Exercise;
	//error : reference to ivar(the local one is ambigious);

	//original ver : could not find limit
	double dvar = 3.14;
	int iobj = limit + 1;
	++ivar;
	++::ivar;

	system("pause");
	return 0;
}

