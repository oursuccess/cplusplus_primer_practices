#include<iostream>
#include<memory>
#include<string>

using std::string;
using std::cin;
using std::endl;
using std::cout;

int main()
{
	string s;
	std::cin >> s;
	char* p = new char[s.size() + 1];
	for(int i = 0; i != s.size(); ++i){
		p[i] = s[i];
	}

	cout << s << endl;
	cout << p << endl;

	s += s;

	for(int i = 0; i != s.size(); ++i){
		p[i] = s[i];
	}
	cout << s << endl;
	cout << p << endl;

	system("pause");
	return 0;
}
