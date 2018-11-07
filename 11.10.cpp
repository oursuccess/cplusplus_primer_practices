#include<vector>
#include<list>
#include<map>

int main()
{
	std::map<std::vector<int>::iterator,int> m1;
	//为什么下面的双向迭代器不要求<比较运算，却能通过编译？
	std::map<std::list<int>::iterator,int> m2;

	system("pause");
	return 0;
}
