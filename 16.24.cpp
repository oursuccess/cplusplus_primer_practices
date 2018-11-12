
#include"Blob.h"

int main()
{
	int i = 8, j = 0, k = 2;
	Blob<int> bi{i,j};
	bi.push_back(k);

	std::vector<int> vi{1,2,2,3,4,5,6,7,8};
	Blob<int> bi2(vi.begin(),vi.end());

	std::cout << bi2.size() << "bi.back: " << bi2.back();


	system("pause");
	return 0;
}
