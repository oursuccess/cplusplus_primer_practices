#include<set>
#include<iostream>
#include<unordered_set>
#include"Sales_data.h"

int main()
{
	std::unordered_multiset<Sales_data> uss;
	Sales_data s1("b1",10,2), s2("b2",1,3), s3("b3",2,4);

	uss.insert(s1);
	uss.insert(s2);
	uss.insert(s3);

	std::cout << uss.size() << std::endl;
	for(auto s : uss)
	{
		s.printData();
	}

	system("pause");
	return 0;
}
