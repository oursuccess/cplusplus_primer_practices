//this test the deconstructor of TextQuery

#include<iostream>
#include<fstream>
#include"TextQuery.h"
#include"DebugDelete.h"

void runQueries(std::ifstream &);

using std::cin;
using std::cout;

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	runQueries(in);

	system("pause");
	return 0;
}
