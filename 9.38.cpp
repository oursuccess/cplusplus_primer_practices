//in mingw, the capacity of vector doubles it when need more space
//but can use reserve to ask for more space and shrink_to_fit to less
#include<iostream>
#include<vector>

int main()
{
	std::vector<int> vi;
	std::cout << "size of vi: " << vi.size() << " capacity of vi: " << vi.capacity() << std::endl;

	for(int i = 0;i != 100;++i){
		vi.push_back(i);
		std::cout << "size of vi: " << vi.size() << " capacity of vi: " << vi.capacity() << std::endl;
	}

	vi.shrink_to_fit();
	std::cout << "size of vi: " << vi.size() << " capacity of vi: " << vi.capacity() << std::endl;

	vi.resize(50);
	std::cout << "size of vi: " << vi.size() << " capacity of vi: " << vi.capacity() << std::endl;

	vi.resize(200);
	std::cout << "size of vi: " << vi.size() << " capacity of vi: " << vi.capacity() << std::endl;

	vi.reserve(100);

	std::cout << "size of vi: " << vi.size() << " capacity of vi: " << vi.capacity() << std::endl;

	vi.reserve(10);
	std::cout << "size of vi: " << vi.size() << " capacity of vi: " << vi.capacity()<< std::endl;


	system("pause");
	return 0;
}
