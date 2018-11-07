#include<iostream>
#include<iterator>
#include<vector>

int main()
{
	std::vector<int> vi;
	for(auto i = 1; i!= 9; ++i){
		vi.push_back(i);
	}

	for(auto riter = vi.crbegin(); riter != vi.crend(); ++riter){
		std::cout << *riter << " ";
	}

	system("pause");
	return 0;
}
