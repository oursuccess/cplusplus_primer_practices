#include<iostream>
#include<vector>

int main()
{
	std::vector<int> vi{1};
	std::cout << vi.size() << vi.capacity() << std::endl;
	for(auto i : vi){
		std::cout << i << std::endl;
	}

	auto val = *vi.begin(), val2 = vi.front();
	auto last = vi.end();
	auto val3 = *(--last);
	auto val4 = vi.back();

	std::cout << val << " " << val2 << " " << val3 << " " << val4 << std::endl;

	system("pause");
	return 0;
}
