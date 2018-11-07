#include<iostream>
#include<vector>

int main()
{

	std::vector<int> vi1,vi2;
	for(int i;std::cin >> i;){
		vi1.push_back(i);
	}

	//为什么输入换行之后^Z正常，但不换行直接输入^Z,vi2中读取元素被直接跳过了？j
	std::cin.clear();
	for(int i;std::cin >> i;){
		vi2.push_back(i);
	}
	for(auto i : vi2){
		std::cout << i << std::endl;
	}

	if(vi1 == vi2){
		std::cout << "vi1 equal to vi2" << std::endl;
	}else if(vi1 < vi2){
		std::cout << "vi1 is less than vi2" << std::endl;
	}else{
		std::cout << "vil is bigger than vi2" << std::endl;
	}

	system("pause");
	return 0;
}
