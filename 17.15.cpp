#include<regex>
#include<string>
#include<iostream>

int main()
{
	using std::string;
	using std::regex;
	using std::cout;
	using std::cin;
	using std::smatch;
	using std::endl;

	string pattern("[^c]ei");

	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch results;

	string test;
	while(1){
		cout << "enter a word, or q to quit:";
		cin >> test;
		if(test == "q")
			break;

		if(regex_search(test, results, r))
			cout << results.str() << endl;
	}

	return 0;
}
	
