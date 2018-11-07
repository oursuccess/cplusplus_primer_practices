#include<iostream>
#include<list>
#include<algorithm>

int main()
{
	std::list<int> li;
	int i;
	while(std::cin >> i){
		li.push_back(i);
	}

	auto fiter = find(li.crbegin(),li.crend(),0);
	for_each(fiter,li.crend(),[](int i){std::cout << i << " ";});

	system("pause");
	return 0;
}
