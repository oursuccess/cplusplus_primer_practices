#include<string>
#include<iostream>
#include<vector>
#include"Vec.h"

int main()
{
	Vec<int> vi;
	Vec<std::string> vs;

	vi.push_back(1);
	vi.push_back(2);

	std::cout << vi.size() << " vi.begin(): " << *vi.begin() << std::endl;

	system("pause");
	return 0;
}
