#include<iostream>
#include<list>
#include<vector>

int main(){
	std::list<int> li;
	for(int i;std::cin >> i;){
		li.push_back(i);
	}

	std::cin.clear();

	std::vector<int> vi;
	for(int i;std::cin >> i;){
		vi.push_back(i);
	}

	//li couldn't 与 vi比较
	//
	/*if(li == vi){
		std::cout << "li equal to vi" << std::endl;
	}else{
		std::cout << "li does not equal to vi" << std::endl;
	}*/
	//为什么说iov未声明？
	if(li.size() == vi.size()){
		std::list<int>::iterator iol = li.begin(); std::vector<int>::iterator iov = vi.begin();
		for(;iol != li.end();++iol,++iov){
			if(*iol != *iov){
				std::cout << "li doesn't equal to vi" << std::endl;
				break;
			}
		}
		//iterator不能-1？list<T>::iterator未定义 -
		if(iol == li.end() && *(--iol) == *(iov - 1)){
			std::cout << "li equal to vi" <<  std::endl;
		}
	}else{
		std::cout << "li doesnot equal to vi" << std::endl;
	}


	system("pause");
	return 0;
}
