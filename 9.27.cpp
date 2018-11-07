#include<iostream>
#include<forward_list>

int findDeleteOdds(std::forward_list<int>&);

int main()
{
	int i;
	std::forward_list<int> fli;
	while(std::cin >> i){
		fli.push_front(i);
		//forward_list doesn't support push_back?
		//support push_front...
	}
	
	for(auto i : fli){
		std::cout << i << std::endl;
	}

	for(std::forward_list<int>::iterator iofl = fli.begin(),prev = fli.before_begin();iofl != fli.end();){
		if(*iofl % 2){
			iofl = fli.erase_after(prev);
		}
		else{
			prev = iofl;
			++iofl;
		}

	}

	for(auto i : fli){
		std::cout << i << std::endl;
	}

	system("pause");
	return 0;
}
