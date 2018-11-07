#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include"Sales_data.h"


int main(int argc, char* argv[])
{
	Sales_data item;
	std::vector<Sales_data> SalesVec;
	
	std::ifstream in(argv[1]);
	if(in){
		while(in >> item){
			SalesVec.push_back(item);
		}

		std::ofstream ou(argv[2],std::ofstream::app);

		for(auto i : SalesVec){
			i.printData();
			i.printData(ou);
		}

		stable_sort(SalesVec.begin(),SalesVec.end(),compareIsbn);
		for(auto i : SalesVec){
			i.printData();
			i.printData(ou);
		}

	}

	system("pause");
	return 0;
}

