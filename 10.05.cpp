#include<vector>
#include<fstream>
#include<iostream>
#include<array>
using namespace std;

int main(int argc, char* argv[])
{
	const char* c1 = "hello";
	const char* c2 = "world";
	const char c3[] = "this";
	const char c4[] = "is";	
	char c5[] = "hello";
	char c6[] = "world";
	//std::vector<char> c7{'h','e','l','l','o'};
	array<char,100> c8={'h','e','l','l','o','\0'};


	std::vector<const char*> cpvec1{c1,c2};//'\0'
	std::vector<const char*> cpvec2{c3,c4};
	//vector<const char[]) cpvec3 couldn't use
	//vector<char [100]) cpvec3{c5,c6} couldn't use
	//vector<char [100]) cpvec3; could use
	//but couldn't add new elements
	//数组的vector连续存储，但不确定数组的长度，而指针的vector长度确定 故cpvec1 2无问题
	//
	//std::vector<std::vector<char>> cpvec3;
	//cpvec3.push_back(c7);

	vector<array<char,100>> cpvec3{c8};
	cpvec3.push_back(array<char,100>{'w','o','r','l','d','\0'});

	//为什么cout << s 输出的是数组而非指针？
	//*s输出的是字符串的首字母
	for(auto s : cpvec1){
		std::cout << *s << std::endl;
	}

	for(auto s : cpvec2){
		std::cout << s << std::endl;
	}

	for(auto s : cpvec3){
		std::cout << s.data() << std::endl;
		}

	std::cout << equal(cpvec1.cbegin(),cpvec1.cend(),cpvec2.cbegin());
	//std::cout << equal(cpvec1.cbegin(),cpvec1.cend(),cpvec3.cbegin());
	//元素类型不同 无法比较
	std::cout << equal(cpvec2.cbegin(),cpvec2.cend(),cpvec3.cbegin());
	
	system("pause");
	return 0;
}
