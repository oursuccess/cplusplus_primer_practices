#include<iostream>
#include<vector>
#include"7.44.h"

int main()
{
	NoDefault a(10);
	
	
	/*
	// note: candidate: 'NoDefault::NoDefault(int)'
  NoDefault(int i):var(i),dir(i){}
  ^~~~~~~~~
7.44.h:7:2: note:   candidate expects 1 argument, 0 provided
7.44.h:4:7: note: candidate: 'constexpr NoDefault::NoDefault(const NoDefault&)'
 class NoDefault{
       ^~~~~~~~~
7.44.h:4:7: note:   candidate expects 1 argument, 0 provided
7.44.h:4:7: note: candidate: 'constexpr NoDefault::NoDefault(NoDefault&&)'
7.44.h:4:7: note:   candidate expects 1 argument, 0 provided
*/
//改成vec呢？
//不报错，但这是什么意思？
//只是声明，而未真正定义？
//嗯， 括号内只有一个参数时为定义一个有n个成员的vector，而每个成员的值要在括号中的第二个参数注明（此处必须标注，否则无默认构造函数）
	std::vector<NoDefault> vec(10,10);
	//或者用大括号直接用值初始化列表初始化
	std::vector<NoDefault> vec2{10};
	
	system("pause");
	return 0;
}