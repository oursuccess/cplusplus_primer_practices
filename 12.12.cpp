#include<iostream>
#include<memory>
#include"12.12.h"

using std::shared_ptr;
using std::make_shared;

int main()
{
	auto p = new int(42);
	auto sp = make_shared<int>(41);
	//ok
	process(sp);
	//no viable conversion from int* to shared_ptr
	//process(new int(*sp));
	process(shared_ptr<int>(new int(*sp)));
	//no viabe conversion from int* to shared_ptr
	//process(p);
	process(shared_ptr<int>(p));
	process(shared_ptr<int>(p));

	system("pause");
	return 0;
}
