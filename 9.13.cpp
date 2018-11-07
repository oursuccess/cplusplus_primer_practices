#include<iostream>
#include<list>
#include<vector>
#include<fstream>

int main(int argc,char * argv[])
{
	std::ifstream in(argv[1],std::ifstream::in);
	if(in){
		int i;
		//vector<int> 也一样采用迭代器
		std::vector<int> li;
		while(in >> i){
			li.push_back(i);
		}
		std::vector<double> vd(li.begin(),li.end());
		for(auto i : vd){
			std::cout << i << std::endl;
		}
	}
	
	system("pause");
	return 0;
}