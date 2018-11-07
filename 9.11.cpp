#include<iostream>
#include<vector>


int main()
{
	std::vector<int> v1; //v1为空vector
	std::vector<int> v2 = {1,2,3};//v2中的元素为1，2，3
	std::vector<int> v3 = v2;//v3为v2的拷贝初始化
	std::vector<int> v4(v3);//v4为v3的拷贝初始化
	std::vector<int> v5(10);//v5包含10个默认初始化（而非值初始化）的元素 //0,值初始化而非默认初始化 p299
	std::vector<int> v6(10,1);//v6包含10个1
	std::vector<int> v7{1,2,3,4,5,6,7};//v7中的元素为1-7
	std::vector<int> v8(v7.begin() + 1,v7.begin() + 5);//v8的元素为2-6 //5而非6
	
	
	
	for(auto i:v1)
		std::cout << i << std::endl;
	for(auto i:v2)
		std::cout << i << std::endl;
	for(auto i:v3)
		std::cout << i << std::endl;
	for(auto i:v4)
		std::cout << i << std::endl;
	for(auto i:v5)
		std::cout << i << std::endl;
	for(auto i:v6)
		std::cout << i << std::endl;
	for(auto i:v7)
		std::cout << i << std::endl;
	for(auto i:v8)
		std::cout << i << std::endl;
	system("pause");
	return 0;
}