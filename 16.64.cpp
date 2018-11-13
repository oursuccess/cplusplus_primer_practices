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

template<>
int elemCount(const std::vector<const char *> &vc, const char *c)
{
	int count = 0;
	for(auto i : vc){
		if(*c == *i)
			++count;
	}
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

	std::vector<const char *> vc;
	const char *c1 = static_cast<const char*>("hello");
	const char *c2 = static_cast<const char*>("hello");
	const char *c3 = static_cast<const char*>("world");

	for(auto i = 0; i != 6; ++i)
		vc.push_back(c1);

	for(auto i = 0; i != 6; ++i)
		vc.push_back(c2);

	for(auto i = 0; i != 6; ++i)
		vc.push_back(c3);

	std::cout << elemCount(vc,"hello");

	system("pause");
	return 0;
}
