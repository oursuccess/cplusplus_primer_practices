#include<iostream>
#include<string>
#include"7.23.h"

int main()
{
	Screen scr;
	Screen scr2(90,90,'*');
	
	std::cout << scr2.getcursor(8,7) << std::endl;
	
	system("pause");
	
	return 0;
}