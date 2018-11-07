#include<iostream>
#include<string>
#include"7.24.h"

int main()
{
	Screen scr1, scr2(80,90),scr3(100,90,'c');
	
	std::cout << scr2.getcursor(6,6) << scr3.getcursor(8,8) << std::endl;
	
	system("pause");
	return 0;
}