#include<iostream>
#include<list>
#include<vector>

int ia[] = {0,1,1,2,3,5,8,13,21,55,89};

int main()
{
	//怎样使用数组初始化容器？
	//
	std::vector<int> vi;
	std::list<int> li;
	//sizeof(a[]),nota.size()
	//not sizeof,use sizeof(a[])/sizeof(elem)  of end(a)-begin(a)
	for(int i = 0;i!=sizeof(ia)/sizeof(*ia);++i){
		vi.push_back(ia[i]);
		li.push_back(ia[i]);
	}

	std::cout << "vi: " << std::endl;
	for(auto i : vi){
		std::cout << i << std::endl;
	}

	std::cout << "li: " << std::endl;
	for(auto i : li){
		std::cout << i << std::endl;
	}

	std::cout << sizeof(ia) << " " << vi.size() << " " << li.size() << std::endl;

	for(std::vector<int>::iterator iov = vi.begin();iov!=vi.end();){
		if(*iov%2){
			++iov;
		}else{
			iov = vi.erase(iov);
		}
	}

	for(auto iol = li.begin(); iol != li.end();){
		if(*iol%2){
			//li.erase
			iol = li.erase(iol);
		}else{
			++iol;
		}
	}

	std::cout << "vi: " << std::endl;
	for(auto i : vi){
		std::cout << i << std::endl;
	}

	std::cout << "li: " << std::endl;
	for(auto i : li){
		std::cout << i << std::endl;
	}

	system("pause");
	return 0;
}
