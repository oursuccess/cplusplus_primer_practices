//in clang 7.00, it seems that sort doesnot call sort when elems are no more than a base nums 
//which is larger than 32?

#include<iostream>
#include<string>
#include<vector>
#include"HasPtr.hpp"
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	HasPtr h1,h2("hello");
	h1 = h2;
	cout << "h1 " << h1 << "\th2" << h2 << endl;

	HasPtr h3("world");
	cout << "h3 " << h3 << endl;
	swap(h1,h3);
	cout << "h1 " << h1 << "\th3 " << h3 << endl;

	HasPtr h4("lalala");
	HasPtr h5("linux");
	HasPtr h6("king");
	HasPtr h7("lion");

	vector<HasPtr> vh;
	vh.push_back(h1);
	vh.push_back(h2);
	vh.push_back(h3);
	vh.push_back(h1);
	for(auto i : {1,2,3,4}){
		vh.push_back(h1);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h3);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h4);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h5);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h6);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}
	for(auto i : {1,2,3,4}){
		vh.push_back(h7);
	}

	//the following func is wrong
	//vh.push_back(HasPtr("lalala"));

	for(auto i : vh){
		cout << i << endl;
	}

	sort(vh.begin(),vh.end());


	for(auto i : vh){
		cout << i << endl;
	}

	system("pause");
	return 0;
}
