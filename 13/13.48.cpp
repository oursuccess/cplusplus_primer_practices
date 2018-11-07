#include<vector>
#include"Mstring.h"

int main()
{
	std::vector<Mstring> vs;
	Mstring s("hello");
	for(int i = 0; i <= 100; ++i)
		vs.push_back(s);

	system("pause");
	return 0;
}
