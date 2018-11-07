#include<iostream>
#include<fstream>
#include<list>
#include<deque>

int main(int argc, char*argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		int i;
		std::list<int> li;
		while(in >> i){
			li.push_back(i);
		}

		std::deque<int> di1,di2;
		for(auto i : li){
			i%2?di1.push_back(i):di2.push_back(i);
		}

		std::cout << "di1: " << std::endl;
		std::ofstream ou1(argv[2],std::ofstream::app);
		for(std::deque<int>::value_type i : di1){
			std::cout << i << std::endl;
			ou1 << i << "\t";
		}

		
		std::ofstream ou2(argv[3],std::ofstream::app);
		std::cout << "di2: " << std::endl;
		for(auto i : di2){
			std::cout << i << std::endl;
			ou2 << i << "\t";
		}

		system("pause");
		return 0;
	}
}
