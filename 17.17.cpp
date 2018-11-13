#include<regex>
#include<string>
#include<vector>
#include<iostream>

int main()
{
	using std::string;
	using std::regex;
	using std::cout;
	using std::cin;
	using std::smatch;
	using std::vector;
	using std::endl;

	string pattern("[^c]ei");

	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	smatch results;

	//vector<string> vs;
	//need to be string

	string test;
	while(1){
		cout << "enter a word, or q to quit:";
		getline(std::cin,test);
		if(test == "q")
			break;

		//vs.push_back(test);
		for(std::sregex_iterator it(test.begin(), test.end(), r), end_it; it != end_it; ++it)
			cout << it -> str() << endl;
	}


	return 0;
}
	
