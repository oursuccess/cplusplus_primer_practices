#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

void printi(int i)
{
	std::cout << i << " ";
}


int main()
{
	std::vector<int> vi1(10,0);
	std::vector<int> vi2(vi1);
	std::vector<int> vi3{1,2,3,4,5,6,7,8,9,0};
	std::vector<int> vi4,vi5,vi6,vi7;

	for_each(vi1.begin(),vi1.end(),[](int i){std::cout << i << " ";});
	for_each(vi2.begin(),vi2.end(),printi);
	for_each(vi3.begin(),vi3.end(),printi);

	replace(vi1.begin(),vi1.end(),0,2);
	for_each(vi1.begin(),vi1.end(),printi);
	
	int max;
	std::cout << "typein max: ";
	std::cin >> max;

	replace_if(vi3.begin(),vi3.end(),[max](int i) -> bool{return i > max;},max);
	for_each(vi3.begin(),vi3.end(),printi);
	std::cout << std::endl;

	replace_copy(vi3.begin(),vi3.end(),back_inserter(vi4),max,0);
	for_each(vi4.begin(),vi4.end(),printi);

	int min;
	std::cout << " typein min: ";
	std::cin >> min;
	replace_copy_if(vi4.begin(),vi4.end(),inserter(vi5,vi5.begin()),[min](int i) -> bool {return i < min;},min);
	for_each(vi5.begin(),vi5.end(),printi);

	system("pause");
	return 0;
}
