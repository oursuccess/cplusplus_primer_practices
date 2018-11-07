using namespace std;

#include<fstream>
#include<map>
#include<string>
#include<iostream>
#include<sstream>
#include"11.36.h"

void wordTransform(ifstream &mapFile,ifstream &input)
{
	auto transMap = buildMap(mapFile);
	string text;
	while(getline(input,text)){
		istringstream stream(text);
		string word;
		bool firstword = true;
		while(stream >> word){
			if(firstword){
				firstword = false;
			}
			else{
				cout << " ";
			}
			cout << transform(word,transMap);
		}

		cout << endl;
	}
}
