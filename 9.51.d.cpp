#include<iostream>
#include<fstream>
#include"9.51.h"
#include<string>
#include<sstream>

Date_Me::Date_Me(std::string s)
{
	//first, those vals with just nums
	//issstream
	//	std::istringstream is(s);
	//	unsigned u,y,d;
	//	while(is >> u){
	//		if(u > 30){
	//			y = u;
	//		}
	//		else{
	//			static unsigned m = u;
	//			d = u;
	//		}
	//	}

	//could not use constructor out of a class
	//Date_Me::Date_Me(y,m,d);
	

	if(!s.empty()){
		auto pos = s.find_last_of("0123456789");
		year = stoul(s.substr(pos - 3));
		s.erase(pos - 3);
		if(s.find_first_of("QWERTYUIOPASDFGHJKLZXCVBNM") != std::string::npos){
			date = stoul(s.substr(s.find_first_of("0123456789")));
			std::string str(s,0,3);
			switch(s[0]){
				case 'J':
					if(str == "Jan")
						month = 1;
					else if(str == "Jun")
						month = 6;
					else
						month = 7;
					break;
				case 'F':
					month = 2;
					break;
				case 'M':
					if(str == "Mar")
						month = 3;
					else
						month = 5;
					break;
				case 'A':
					if(str == "Apr")
						month = 4;
					else
						month = 8;
					break;
				case 'S':
					month = 9;
					break;
				case 'O':
					month = 10;
					break;
				case 'N':
					month = 11;
					break;
				case 'D':
					month = 12;
					break;
			}
		}else{
			month = stoul(s);
			if(month > 9)
				date = stoul(s.substr(3));
			else
				date = stoul(s.substr(2));
		}
	}
}
