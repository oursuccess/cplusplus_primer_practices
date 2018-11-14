#include<iostream>

int main()
{
	do{
		int i = 2;
		std::cout << i;
		//error : use of undeclared argument i
	}while(--i);

	system("pause");
	return 0;
}
