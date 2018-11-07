#include<iostream>
#include<memory>
#include"12.12.h"

using std::shared_ptr;
using std::cout;
using std::endl;

void process(shared_ptr<int> ptr)
{
	cout << *ptr << endl;
}
