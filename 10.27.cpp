#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>

int main()
{
	std::vector<std::string> vs{"hi","there","is","a","red","apple","do","you","want","to","taste","it","and","i","bet","it","is","delicious","in","case","it","is","red","over","there"};
	for(auto s : vs){
		std::cout << s << "\t";
	}

	std::list<std::string> ls;

	//inserter(std::vector<std::>,std::vector<std::>::iterator>)
	//u can only use unique when the same elements occurs aside
	sort(vs.begin(),vs.end());
	unique_copy(vs.begin(),vs.end(),inserter(ls,ls.begin()));
	
	//test
	/*
	 * auto end_unique = unique(vs.begin(),vs.end());
	for(std::vector<std::string>::iterator siter = vs.begin(); siter != end_unique; ++siter){
		std::cout << *siter << "\t";
	}
	*/

	for(auto s : ls){
		std::cout << s << std::endl;
	}

	system("pause");
	return 0;
}
