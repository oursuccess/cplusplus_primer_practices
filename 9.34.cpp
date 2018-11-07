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

	std::vector<int>::iterator iter = vi.begin();
	while(iter != vi.end())
	{
		if(*iter % 2)
			iter = vi.insert(iter, *iter);
		iter += 2;
	}

	for(auto i : vi){
		std::cout << i << std::endl;
	}
	system("pause");
	return 0;
}
