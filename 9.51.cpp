#include<iostream>
#include<string>
#include<fstream>
#include"9.51.h"

int main()
{
	Date_Me d1;
	Date_Me d2(2000,01,01); 

	std::string s;
	if(std::cin >> s){
		//Date_Me d3()
		Date_Me d3(s);
		d3.printDate();
	}

	d1.printDate();
	d2.printDate();

	system("pause");
	return 0;
}
