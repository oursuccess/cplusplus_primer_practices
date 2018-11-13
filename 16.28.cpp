#include<iostream>
#include"smart_ptr.h"
#include"Blob.h"

int main()
{
	int i = 0, k = 2, l = 3;
	Blob<int> bi;
	bi.push_back(i);
	bi.push_back(k);
	bi.push_back(l);

	Blob<int> bj(bi);

	system("pause");
	return 0;
}
