#include<iostream>
#include<fstream>

//һ���ݼ�����ֵ��0��lambda

int main()
{
	int i;
	while(std::cin >> i){
		if([&i]() -> bool{ return --i;}())
			std::cout << i << " ";
	}

	system("pause");
	return 0;
}
