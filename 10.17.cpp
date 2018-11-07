#include<iostream>
#include<vector>
#include<string>
#include"10.17.h"
#include<algorithm>

int main()
{
	Sales_data s1;
	std::vector<Sales_data> itemVec;
	while(std::cin >> s1){
		itemVec.push_back(s1);
	}

	for(auto i : itemVec){
		std::cout << i;
	}

	stable_sort(itemVec.begin(),itemVec.end(),[](const Sales_data &s1,const Sales_data &s2)-> bool {return s1.isbn() < s2.isbn();});

	for(auto i : itemVec){
		std::cout << i;
	}

	system("pause");
	return 0;
}
