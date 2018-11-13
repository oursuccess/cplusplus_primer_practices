#include<tuple>
#include<numeric>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include"Sales_data.h"

typedef std::tuple<std::vector<Sales_data>::size_type, std::vector<Sales_data>::const_iterator, std::vector<Sales_data>::const_iterator> matches;

std::vector<matches>
findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
	std::vector<matches> ret;
	for(auto it = files.cbegin(); it != files.cend(); ++it){
		//no move and move assign
		//sort(it->begin(), it->end(), compareIsbn);
		//this algorithm does not works well in a unsorted vector
		auto found = equal_range(it -> cbegin(), it -> cend(), book, compareIsbn);
		std::cout << *found.second;
		if(found.first != found.second){
			ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
		}
	}
	return ret;
}


void reportResults(std::istream &in, std::ostream &os, const std::vector<std::vector<Sales_data>> &files)
{
	std::string s; //book needed to find
	while(in >> s){
		auto trans = findBook(files, s);
		if(trans.empty()){
			std::cout << s << " not found in any stores " << std::endl;
			continue;
		}

		for(const auto &store : trans){
			os << " store " << std::get<0>(store) << " sales: " << accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s)) << std::endl;
		}
	}
}
