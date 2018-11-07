#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<deque>

int main()
{
	std::vector<int> vi;
	for(auto i = 1; i!=9; ++i){
		vi.push_back(i);
	}

	std::vector<int> vi1,vi2;
	std::deque<int> di;
	copy(vi.begin(),vi.end(),inserter(vi1,vi1.begin()));
	std::cout << "inserter:" ;
	for(auto i : vi1){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	copy(vi.begin(),vi.end(),front_inserter(di));
	std::cout << "front_inserter";
	for(auto i : di){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	copy(vi.begin(),vi.end(),back_inserter(vi2));
	std::cout << "back_inserter";
	for(auto i : vi2){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}
