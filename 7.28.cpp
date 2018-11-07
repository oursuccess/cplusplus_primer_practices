#include<iostream>
#include<string>
#include"7.28.h"

int main()
{
	Screen myScreen(5,5,'X');
	myScreen.move(4,0).set('#').display(std::cout);
	std::cout << "\n";
	myScreen.display(std::cout);
	std::cout << "\n";
	
	
	system("pause");
	return 0;
}