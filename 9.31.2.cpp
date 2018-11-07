#include<iostream>
#include<forward_list>

int main()
{
	std::forward_list<int> fli{1,2,3,4,5,6,7,8,9,0};
	auto iter = fli.begin();
	auto prev = fli.before_begin();

	while(iter != fli.end()){
		if(*iter % 2){
			iter = fli.insert_after(iter,*iter);
			++iter;
			++prev;
			++prev;
		}
		else{
			//forward_list doesn't have --operator for iterator
			iter = fli.erase_after(prev);
		}
	}

	for(auto i : fli)
	{
		std::cout << i << std::endl;
	}

	system("pause");
	return 0;
}
