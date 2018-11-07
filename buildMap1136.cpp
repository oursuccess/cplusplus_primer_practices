#include<map>
#include<string>
#include<stdexcept>
#include<sstream>
#include<fstream>
#include<iostream>

using namespace std;

map<string,string> buildMap(ifstream &mapFile)
{
	map<string,string> transMap;
	string key;
	string value;

	while(mapFile >> key && getline(mapFile,value)){
		try {
			if (value.size() > 1) {
				//original
				//transMap[key] = value.substr(1);
				//1135
				transMap.insert({ key,value.substr(1) });
			}
			else {
				throw runtime_error("no rules for " + key);
			}
		}
			//try {
			//	//throw runtime_error("no rules for " + key);
			//}
			
		//	cerr << "no rules for" << key;
			catch (runtime_error &s)
			{
				cerr << s.what() << endl;
			}

	}


	return transMap;
}
