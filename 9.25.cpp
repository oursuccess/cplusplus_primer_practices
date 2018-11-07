#include<iostream>
#include<vector>

int main()
{
	std::vector<int> vi;
	int i;
	while(std::cin >> i){
		vi.push_back(i);
	}

	for(auto i : vi){
		std::cout << i << std::endl;
	}

	//don't forget to clear the statement of std::cin
	std::cout << "please typein the elems u want to delete" << std::endl;
	//redecleration of i
	std::cin.clear();
	int j;
	while(std::cin >> i >> j){
		//not string, int
		//forgot the practice:erase elements ...
		std::vector<int>::iterator be = vi.begin() + i;
		auto en = vi.begin() + j;
		vi.erase(be,en);
		for(auto i : vi){
			std::cout << i << std::endl;
		}
		std::cout << vi.size() << " " << vi.capacity() << std::endl;
		std::cin.clear();
	}

	system("pause");
	return 0;
}
