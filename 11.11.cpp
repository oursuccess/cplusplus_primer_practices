#include<set>

int add(int i, int j) {
	return i + j;
}

int main()
{
	std::multiset<int,decltype(add)*> book(add);
	std::multiset<int, int(*)(int,int)> book2(add);
}
