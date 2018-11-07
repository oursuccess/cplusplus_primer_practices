
//get word and search it in the map
//then returns the appeared lines of the word
//and the content of the line

#include<iostream>
#include"strVec.hpp"
#include<set>
#include<memory>
#include<map>
#include<string>
#include"TextQuerySV.h"

using std::set;
using std::shared_ptr;
using std::ostream;
using std::endl;
using std::string;

QueryResult::QueryResult(string s, shared_ptr<set<unsigned>> li, shared_ptr<StrVec> vs):word(s),lines(li),vsptr(vs){}

ostream& operator<<(ostream& ou, const QueryResult& q)
{
	ou << "the word " << q.word << " occurs " << q.lines -> size() << " times." << endl;
	for(auto appearTime = q.lines -> begin();appearTime != q.lines -> end();++appearTime){
		//in  StrVec, [i] starts from 0
		ou << "line" << *appearTime; 
	}
	return ou;
}
