#include<vector>
#include<iostream>

template<typename T>
int elemCount(const std::vector<T> &vi, T t)
{
	int count = 0;
	for(auto i : vi)
		if(t == i)
			++count;
	return count;

}

int main()
{
	std::vector<int> vi;
	for(auto i = 0; i != 10; ++i)
	{
		vi.push_back(i);
		vi.push_back(i);
	}

	std::cout << elemCount(vi,2) << std::endl;


	system("pause");
	return 0;
}
