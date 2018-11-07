#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<iterator>

int main()
{
	std::vector<int> vi;
	int i;
	while(std::cin >> i){
		vi.push_back(i);
	}

	for(auto i : vi){
		std::cout << i << " ";
	}

	std::list<int> li;
	std::cout << std::endl;
	//
	//copy(vi.begin(),vi.end(),inserter(li,li.begin()));
	//not rbegin() - 1 , use rbegin() +1
	copy(vi.rbegin() + 3,vi.rbegin() + 8,inserter(li,li.begin()));

	for(auto i : li){
		std::cout << i << " ";
	}

	system("pause");
	return 0;
}
