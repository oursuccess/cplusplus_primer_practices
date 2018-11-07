#include<iostream>
#include<string>
#include<fstream>

int main()
{
	std::string s{"ab2c3d7R4E6"};
	std::string numbers{"0123456789"};
	std::string alphabets;
	for(char c = 'A'; c!='z';++c){
		alphabets.push_back(c);
	}

	unsigned i = s.find_first_of(numbers);
	for(auto iter = s.begin();static_cast<int>(i)-s.size() && iter != s.end();){
		std::cout << i << static_cast<int>(i) << std::endl;
		i = s.find_first_of(numbers,i);
		iter =s.begin() + i++;
		std::cout << *(iter) << std::endl;
	}

	system("pause");
	return 0;
}
