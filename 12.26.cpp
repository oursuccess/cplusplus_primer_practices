#include<iostream>
#include<memory>
#include<string>

using std::string;
using std::cin;
using std::allocator;
using std::cout;
using std::uninitialized_copy;
using std::uninitialized_fill_n;

int main()
{
	string s;
	cin >> s;
	//wrong elem below
	//allocator<string> allos;
	//wrong the same?
	//correct need to update the arguement of q
	allocator<char> allos;
	auto p = allos.allocate(s.size() * 2);
	
	auto q = uninitialized_fill_n(p,s.size(),'s');
	//无法将参数1从“char”转换为“std::initializer_list<_Elem>”
	//string 内容应为char 因此allocator模版接受的额外信息应为char
	uninitialized_copy(s.begin(), s.end(), q);

	cout << p ;

	system("pause");
	return 0;
}

