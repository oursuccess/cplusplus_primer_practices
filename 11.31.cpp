#include<iostream>
#include<string>
#include<map>

int main()
{
	std::multimap<std::string,std::string> bookForAuthor;
	std::string name,book;
	while(std::cin >> name){
		std::cin >> book;
		//not () use ({}) or make_pair
		auto ins = bookForAuthor.insert({name,book});
		//returns void?
	}

	for(auto p : bookForAuthor){
		std::cout << p.first << " " << p.second << std::endl;
	}

	std::string s;
	std::cin.clear();
	std::cin >> s;
	std::multimap<std::string,std::string>::iterator result = bookForAuthor.find(s);
	//should use lower_bound upper_bound and equal_range
	if(result != bookForAuthor.end()){
		bookForAuthor.erase(result);
	}
		
	for(auto p : bookForAuthor){
		std::cout << p.first << " " << p.second << std::endl;
	}

	system("pause");
	return 0;
}
