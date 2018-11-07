#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

int main(int argc, char* argv[])
{
	std::ifstream infile(argv[1]);

	if(infile){
		int i;
		std::vector<int> vi;
		while(infile >> i){
			vi.push_back(i);
		}

		std::ofstream oufile(argv[2],std::ofstream::app);
		if(oufile){
			for(auto i : vi){
				oufile << i << "\t";
			}

			std::cout << "请输入想查找的值: " << std::endl;
			int i;
			std::cin >> i;
			std::cout << i << ": " << count(vi.begin(),vi.end(),i);
			oufile << i << ": " << count(vi.begin(),vi.end(),i);

		}

	}

	system("pause");
	return 0;
}
