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
	//�޷�������1�ӡ�char��ת��Ϊ��std::initializer_list<_Elem>��
	//string ����ӦΪchar ���allocatorģ����ܵĶ�����ϢӦΪchar
	uninitialized_copy(s.begin(), s.end(), q);

	cout << p ;

	system("pause");
	return 0;
}

