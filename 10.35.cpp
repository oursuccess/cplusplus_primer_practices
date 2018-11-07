#include<iostream>
#include<vector>

int main()
{
	std::vector<int> vi;
	for(auto i = 0; i!= 9;){
		vi.push_back(i++);
	}

	//not cend to cbegin but cend-1 to cbegin(include)
	for(auto iter = vi.cend();iter != vi.cbegin();){
		//*--i is valid
		std::cout << *--iter << " ";
	}

	system("pause");
	return 0;
}
