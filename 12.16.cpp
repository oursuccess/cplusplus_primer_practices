#include<iostream>
#include<memory>

using std::unique_ptr;

int main()
{
	//无法使用拷贝赋值 只能默认初始化  
	unique_ptr<int> up(new int(42));

	unique_ptr<int> up2 = up;

	system("pause");
	return 0;
}
