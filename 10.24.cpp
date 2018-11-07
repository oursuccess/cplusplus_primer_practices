//使用bind和check_size在vector<int>中查找第一个大于string长度的值

#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>

bool check_size(std::string,int);

int main()
{
	std::string s;
	std::cin >> s;

	auto bheck_size = bind(check_size,s,std::placeholders::_1);
	int i;
	std::vector<int> vi;
	std::cin.clear();
	if(std::cin){
		std::cout << "type in nums";
		while(std::cin >> i){
			vi.push_back(i);
		}
	}
	auto iter = find_if(vi.begin(),vi.end(),bheck_size);
	std::cout << *iter;

	system("pause");
	return 0;
}
bool check_size(std::string s, int i)
{
	return i > s.size();
}
