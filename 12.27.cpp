#include<iostream>
#include<fstream>
#include<string>
#include"TextQuery.h"

void runQueries(ifstream& );

using std::ifstream;
using std::cin;
using std::cout;

int main(int argc, char* argv[])
{
	ifstream in(argv[1]);
	runQueries(in);

	system("pause");
	return 0;
}
