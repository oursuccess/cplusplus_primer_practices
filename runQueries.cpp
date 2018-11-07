//start Queries
//
//receive an ifstream arguement
//use this to build a map
//then ask user to type in words to search

#include<iostream>
#include<fstream>
#include<string>
#include"TextQuery.h"

using std::string;
using std::cout;
using std::ifstream;
using std::cin;
using std::endl;

void runQueries(ifstream& infile)
{
	//infile : the file we need to search in
	//use TextQuety to build map;
	TextQuery searchMap(infile);
	//ask user to search
	while(true){
		cout << " enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q") break;
		//print result
		cout << searchMap.query(s) << endl;
		}
}
	
