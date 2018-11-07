#include<iostream>
#include<vector>

int main()
{
	std::vector<int> vi{1,2,3,4,5,6,7,8,9,0};
	auto iter = vi.begin();
	while(iter != vi.end()){
		if(*iter % 2){
			iter = vi.insert(iter,*iter++);
			++iter;
		}
		else{
			iter = vi.erase(iter);
		}
	}

	for(auto i : vi){
		std::cout << i << std::endl;
	}


	system("pause");
	return 0;
}
