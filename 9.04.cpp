#include<iostream>
#include<vector>

bool findVar(std::vector<int>::iterator, std::vector<int>::iterator, int);

int main()
{
	std::vector<int> vi;
	for(int i = 0; i != 10; ++i){
		vi.push_back(i);
	}
	int input,b,e;
	std::cout << "请输入想要查询的数与查询范围" <<std::endl;
	while(std::cin >> input >> b >> e){
		std::vector<int>::iterator beg = vi.begin();
		auto be = beg + b, en = beg + e;
		if(findVar(be,en,input)){
			std::cout << "找到了对应的数值！" << std::endl;
		}else{
			std::cout << "未能找到！" << std::endl;
		}
	}
	
	system("");
	return 0;
}


bool findVar(std::vector<int>::iterator be, std::vector<int>::iterator en, int i)
{
	for(;be!=en;++be){
		if(*be == i)
			return true;
	}
	return false;
}