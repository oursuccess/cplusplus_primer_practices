#include<iostream>
#include<fstream>
#include<string>
#include"8.7.h"

int main(int argc, char* argv[])
{
	std::ifstream ifile(argv[1]);
	if(ifile){
		std::ofstream ofile(argv[2]);
		if(ofile){
			Sales_data total(ifile);
			Sales_data temp;
			while(readData(ifile,temp)){
				if(total.isbn() == temp.isbn()){
					total.combine(temp);
				}else{
					printData(std::cout,total);
					printData(ofile,total);
					total = temp;
				}
			}
			printData(std::cout,total);
			printData(ofile,total);
		}else{
			std::cerr << static_cast<std::string>("could not open") + argv[2];
		}
	}else{
		std::cerr << static_cast<std::string>("could not open") + argv[1];	
	}
	
	system("pause");
	return 0;
}