#include<iostream>
#include<vector>

void firstNum(std::vector<int>);

int main()
{
	std::vector<int> vi1{1,2};
 	std::vector<int> vi2{3};
 	std::vector<int> vinu;

	firstNum(vi1);
	firstNum(vi2);
	firstNum(vinu);

	system("pause");
	return 0;
}

void firstNum(std::vector<int> vi)
{
	std::cout << vi[0] <<"xiabiao" << std::endl;
	std::cout << vi.front() << "front " << std::endl;
	std::cout << *vi.begin() << "begin" << std::endl;
	std::cout << vi.at(0) << "at " << std::endl;
}
