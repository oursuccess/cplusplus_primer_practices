//get word and search it in the map
//then returns the appeared lines of the word
//and the content of the line

#include<iostream>
#include<string>
#include<set>
#include<memory>
#include<vector>
#include<map>
#include"TextQuery.h"

using std::string;
using std::set;
using std::shared_ptr;
using std::vector;
using std::ostream;
using std::endl;

QueryResult::QueryResult(string s, shared_ptr<set<unsigned>> li, shared_ptr<vector<string>> vs):word(s),lines(li),vsptr(vs){}

ostream& operator<<(ostream& ou, const QueryResult& q)
{
	ou << "the word " << q.word << " occurs " << q.lines -> size() << " times." << endl;
	for(auto appearTime = q.lines -> begin();appearTime != q.lines -> end();++appearTime){
		//in  vector, [i] starts from 0
		ou << "line" << *appearTime << " " << q.vsptr -> at(*appearTime - 1) << endl;
	}
	return ou;
}
