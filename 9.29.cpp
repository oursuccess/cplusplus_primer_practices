#include<vector>
#include<fstream>
#include<iostream>

int main(int argc, char* argv[])
{
	std::vector<int> vi;
	int i;
	while(std::cin >> i){
		vi.push_back(i);
	}

	std::cout << vi.size() << std::endl;
	std::ofstream ou(argv[1],std::ofstream::app);
	if(ou){
		for(auto i : vi){
			ou << i <<"\t";
		}
		ou << std::endl;
	}
	ou.close();

	vi.resize(100);
	std::cout << vi.size() << std::endl;
	//redifinition of ou
	//should use .open
	//close() , not clear()
	ou.open(argv[1],std::ofstream::app);
	if(ou){
		for(auto i : vi){
			ou << i <<"\t";
		}
		ou << std::endl;
	}
	ou.close();

	vi.resize(10);
	std::cout << vi.size() << std::endl;
	ou.open(argv[1],std::ofstream::app);
	if(ou){
		for(auto i : vi){
			ou << i <<"\t";
		}
		ou << std::endl;
	}
	ou.close();

	system("pause");
	return 0;
}
