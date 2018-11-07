#include<iostream>
#include<string>
#include<deque>

int main(){
	std::string s;
	std::deque<std::string> ds;
	while(std::cin >> s){
		ds.push_back(s);
	}

	for(std::deque<std::string>::iterator iods = ds.begin();iods != ds.end();++iods){
		std::cout << *iods << std::endl;
	}

	system("pause");
	return 0;
}
