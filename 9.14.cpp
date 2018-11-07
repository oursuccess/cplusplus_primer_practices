#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<fstream>

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		std::list<char*> lc;
		std::cout << 1 << std::endl;
		char[100] cs;
		//std::string s;
		std::cout << 2 << std::endl;
		//这里是有问题的，此时尚未给指针指向的对象分配空间（野指针），需要先in给对象，然后取对象地址传入list
		//那怎么才能传递给一个动态数组？ char[100]不对么？
		while(in >> cs){
			std::cout << 3 << std::endl;
			lc.push_back(&cs);
			std::cout << cs<<std::endl;
		}

		std::vector<std::string> vs(lc.begin(),lc.end());
		std::ofstream ou(argv[2],std::ofstream::app);
		for(auto s : vs){
			ou << s;
			std::cout << s << std::endl;
		}
	}else{
		std::cerr << "could not open" << argv[1] << std::endl;
	}

	system("pause");
	return 0;
}

