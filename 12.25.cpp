#include<memory>
#include<iostream>

int main()
{
	int *pa = new int[10];
	for(int i = 0; i!=10;++i){
		pa[i] = i;
	}

	std::cout << pa[1];

	delete [] pa;
	std::cout << pa[1];
	std::cout << pa;
	std::cout << pa[3];

	system("pause");
	return 0;
}
