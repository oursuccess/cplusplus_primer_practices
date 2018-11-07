#include<iostream>
#include<fstream>
#include<string>
#include"8.6.h"


int main(int argc,char *argv[])
{
	Sales_data book1("Harry Potter",8,2.1),total(std::cin);
	printData(std::cout, book1);
	printData(std::cout,total);
	//为什么下面会是乱码？
	printf("下面开始输出\n");
	Sales_data temp;
	std::ifstream ifile;
	ifile.open(argv[1],std::fstream::in);
	
	if(ifile){
		while(readData(ifile,temp)){
			if(total.isbn() == temp.isbn()){
				total.combine(temp);
			}else{
				printData(std::cout,total);
				total = temp;
			}
		}
		printData(std::cout,temp);
	}else{
		std::cerr << static_cast<std::string>("couldn't open") + argv[1];
	}
	
	
	system("pause");
	return 0;
}