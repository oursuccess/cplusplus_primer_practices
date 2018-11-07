
//get a text
//and then returns a set of lines(unsigned) of the words apperaed and print every line the word appears
// build a vector<string> to store every line
// and a map of {word, set<line>} to store lines of each word

//use two function
//1st: build map
//2nd: search and print it

//thus

#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<fstream>
#include<sstream>
#include<memory>

using std::istream;
using std::istringstream;
using std::string;
using std::ifstream;
using std::ofstream;
using std::map;
using std::set;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::endl;
using std::cout;
using std::cin;

// to build a vector of string, redefine BuildMap 
shared_ptr<map<string,set<unsigned>>> BuildMap(ifstream&,shared_ptr<vector<string>>);
void TextQuery(string,shared_ptr<map<string,set<unsigned>>>, shared_ptr<vector<string>>);

int main(int argc, char* argv[])
{
	ifstream in(argv[1]);
	if(in){
		shared_ptr<vector<string>> vsptr = make_shared<vector<string>>();
		auto lineEachWord = BuildMap(in,vsptr);
		string s;

		do{
			cout << "type in word you want to search " << "or q to quit" << endl;
			if(cin >> s && s!= "q"){
				TextQuery(s,lineEachWord,vsptr);
			}else break;
		}while(true);
	}

	system("pause");
	return 0;
}

shared_ptr<map<string,set<unsigned>>> BuildMap(ifstream& infile, shared_ptr<vector<string>> vsptr)
{
	std::string line, word;
	unsigned u = 0;
	shared_ptr<map<string,set<unsigned>>> lineEachWord = make_shared<map<string,set<unsigned>>>();
	while(getline(infile,line)){
		vsptr -> push_back(line);
		++u;
	
		istringstream iss(line);
		while(iss >> word){
			(*lineEachWord)[word].insert(u);
		}
	}

	return lineEachWord;
}

void TextQuery(string s, shared_ptr<map<string,set<unsigned>>> lineEachWord, shared_ptr<vector<string>> vsptr)
{
	//lineEachWord is a ptr, and result is a iterator of map<string,set<unsigned>>
	auto result = lineEachWord -> find(s);
	//result : a iterator of map<string,set<unsigned>>, point to the word, and the first elem of the pair is a string, second is a set of unsigned
	if (result != lineEachWord->end()) {
		cout << s << " appears " << result->second.size() << " time(s)" << endl;
		for (auto beg = result->second.begin(); beg != result->second.end(); ++beg) {
			cout << "line " << *beg << ":" << vsptr->at(*beg - 1) << endl;
		}
	}
	else {
		cout << s << "does not occurs in this text";
	}
}

