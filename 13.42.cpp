
#include<iostream>
#include<fstream>
#include<string>
#include"TextQuerySV.h"


using std::ifstream;
using std::cin;
using std::cout;

void runQueries(ifstream& );

int main(int argc, char* argv[])
{
	ifstream in(argv[1]);
	runQueries(in);

	system("pause");
	return 0;
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while(true){
		cout << "enter word to look for, or q to quit:";
		string s;
		if(!(cin >> s) || s == "q") break;
		cout << tq.query(s);
	}
}