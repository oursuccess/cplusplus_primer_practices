#include<iostream>
#include<vector>
#include<numeric>
#include<fstream>

int main(int argc,char* argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		int i;
		std::vector<int> ivec;
		while(in >> i){
			ivec.push_back(i);
		}

		for(auto i : ivec){
			std::cout << i << std::endl;
		}

		std::ofstream ou(argv[2],std::ofstream::app);
		if(ou){
			for(auto i : ivec){
				ou << i << "\t";
			}
			ou << std::endl;
		}
		ou << accumulate(ivec.begin(),ivec.end(),0);
		std::cout << accumulate(ivec.begin(),ivec.end(),0);
	}

	system("pause");
	return 0;
}
