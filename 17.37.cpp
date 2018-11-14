#include<iostream>
#include<string>
#include<fstream>

#define MAX 10000

int main(int argc, char * argv[])
{
	char file[MAX];
	std::ifstream ifile;
	ifile.open(argv[1]);
	if(ifile){
		ifile.getline(file,MAX, '\0');
		std::cout << file;
	}


	system("pause");
	return 0;
}
