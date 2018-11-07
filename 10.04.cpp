#include<iostream>
#include<numeric>
#include<vector>
#include<fstream>

int main(int argc, char* argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		double i;
		std::vector<double> dvec;
		while(in >> i){
			dvec.push_back(i);
		}

		std::ofstream ou(argv[2],std::ofstream::app);
		for(auto i : dvec){
			std::cout << i << std::endl;
			ou << i << "\t";
		}

		std::cout << accumulate(dvec.cbegin(),dvec.cend(),0);
		ou << accumulate(dvec.cbegin(),dvec.cend(),0);
	}

	system("pause");
	return 0;
}


