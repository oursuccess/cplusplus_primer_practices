#include"Blob.h"

int main()
{
	int i = 8, j = 0, k = 2;
	Blob<int> bi{i,j};
	bi.push_back(k);


	system("pause");
	return 0;
}
