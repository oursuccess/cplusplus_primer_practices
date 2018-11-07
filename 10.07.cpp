#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>

int main()
{
	std::vector<int> ivec;
	std::list<int> lst;
	int i;
	while(std::cin >> i){
		lst.push_back(i);
	}
	//copy与fill_n均无法保存新函数
	copy(lst.cbegin(),lst.cend(),back_inserter(ivec));


	std::vector<int> vec;
	//分配大小为10的元素空间
	vec.reserve(10);
	//back_inserter接受容器参数 而非迭代器
	fill_n(back_inserter(vec),10,0);

	for(auto i : lst){
		std::cout << i;
	}

	for(auto i : ivec){
		std::cout << i;
	}

	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	for(auto i : vec){
		std::cout << i;
	}

	system("pause");
	return 0;
}

