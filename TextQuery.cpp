//build a vector for text

#include<string>
#include<vector>
#include<fstream>
#include<memory>
#include<sstream>
#include<set>
#include"TextQuery.h"

#include<iostream>

using std::cout;
using std::endl;

using std::string;
using std::make_shared;
using std::shared_ptr;
using std::set;
using std::istringstream;
using std::ifstream;
using std::string;

TextQuery::TextQuery(ifstream& infile)
{
	string line,word;
	vsptr = make_shared<vector<string>> ();
	//wordLines = make_shared<set<unsigned>> ();
	lineForWordMap = make_shared<map<string,set<unsigned>>> ();
	unsigned u = 0;
	while(getline(infile,line)){
		++u;
		vsptr -> push_back(line);
		//test
		istringstream iss(line);
		while(iss >> word){
			(*lineForWordMap)[word].insert(u);
		}
	}

	for (auto line : *vsptr) {
		cout << line << endl;
	}
}

QueryResult TextQuery::query(string word)
{
	//if returns a reference of QueryResult, will cause a ref of deleted obj
	//return {word, make_shared<set<unsigned>>(*lineForWordMap -> find(word)), vsptr}
	//居然不报错 lineForWordMap查找word返回的迭代器解引用后结果为map<string,set<unsigned>>
	return {word,make_shared<set<unsigned>>((* lineForWordMap -> find(word)).second), vsptr};
}
