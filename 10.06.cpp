
#include<iostream>
#include<algorithm>
#include<vector>

int main(int argc, char* argv[])
{
	int i;
	std::vector<int> ivec;
	while(std::cin >> i){
		ivec.push_back(i);
	}

	for(auto i : ivec){
		std::cout << i << std::endl;
	}

	fill_n(ivec.begin(),ivec.size(),0);
	for(auto i : ivec){
		std::cout << i << std::endl;
	}

	system("pause");
	return 0;
}
