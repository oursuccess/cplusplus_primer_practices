#include<iostream>
#include<vector>

int main()
{
	std::vector<int> vi(10);

	for(auto i : vi){
		std::cout << i << std::endl;
	}

	//without begin = vi.insert(begin,42); is an ub
	auto begin = vi.begin();
	while(begin != vi.end()){
		++begin;
		begin = vi.insert(begin,42);
		++begin;
	}


	for(auto i : vi){
		std::cout << i << std::endl;
	}

	system("pause");
	return 0;
}
