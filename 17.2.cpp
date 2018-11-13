#include<iostream>
#include<vector>
#include<string>
#include<tuple>
#include<utility>

int main()
{
	auto tu = std::make_tuple(std::string("hello"), std::vector<std::string>{"this","is","a","test"}, std::pair<std::string, int>{" and num is ",42});
	//std::tuple_size<> need a type signify in <>
	std::cout << std::tuple_size<std::tuple<std::string,std::vector<std::string>,std::pair<std::string,int>>>::value << std::endl;
	std::cout << std::get<0>(tu);
	for(auto i : std::get<1>(tu))
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	if(2 <= std::tuple_size<decltype(tu)>::value)
		std::cout << std::get<2>(tu).first << " " << std::get<2>(tu).second;

	system("pause");
	return 0;
}
	
