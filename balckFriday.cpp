#include<iostream>
#include<array>

#define DEFAULTYEAR 1900

int main()
{
	std::array<short> month{31,28,31,30,31,30,31,31,30,31,30,31};
	unsigned short  yearCount,yearNow,leapCount;
	unsigned int weekday = 1,week = 7, day =1;

	//count feb
	std::cin >> yearCount;
	for(int i = 0;i != yearCount ;++i){
		if(DEFAULTYEAR%100){
			if(DEFAULTYEAR%4){
				leapCount = 4;
			}else
