#pragma once

//define classes:
//TextQuery : read the text and build a vector of all the words , and tag their lines
//read file -- use vector to save -- save as an map:word and their appear lines
//QueryResult : which can save the appear lines and counts of word searching

#include<fstream>
#include<string>
#include<memory>
#include<vector>
#include<map>
#include<set>

using std::ifstream;
using std::string;
using std::vector;
using std::map;
using std::shared_ptr;
using std::ostream;
using std::set;

class QueryResult;

class TextQuery{
	public:
		//constructor
		TextQuery(ifstream&);

		//friend
		
		//func
		QueryResult query(string);

	private:
		//func

		//var
		shared_ptr<vector<string>> vsptr;
		//shared_ptr<set<unsigned>> wordLines;
		shared_ptr<map<string,set<unsigned>>> lineForWordMap;
		//to save the whole line;
};

class QueryResult{
	public:
		//constructor
		QueryResult(string, shared_ptr<set<unsigned>>, shared_ptr<vector<string>>);

		//operator
		friend ostream& operator<<(ostream&,const QueryResult&);

		//friend
		
		//func

	private:
		//func

		//var
		string word;
		shared_ptr<set<unsigned>> lines;
		shared_ptr<vector<string>> vsptr;
};

ostream& operator<<(ostream&,const QueryResult&);

