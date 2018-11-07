#include<memory>
#include<string>
#include<iostream>

using std::string;
using std::cin;
using std::endl;
using std::cout;

char* catWords(const char*, const char*);
string catWords(string,string);

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	cout << "s1: " << s1 << " s2: " << s2 << endl;

	string s3 = catWords(s1,s2);
	cout << "s3: " << s3 << endl;

	const char* c1 = "hello", *c2 = "world";
	std::cout << "c1: " << c1 << " c2: " << c2 << endl;
	char* c3 = catWords(c1,c2);
	std::cout << c3 << endl;

	system("pause");
	return 0;
}

char* catWords(const char* c1, const char* c2)
{
	//set new array: new T []
	//char* p = new char(sizeof(c1) + sizeof(c2) + 1);
	char* p = new char[strlen(c1) + strlen(c2) + 1];
	//c的长度为i，但末位为\0,故需要-1，而计数从0开始，因此-2
	//sizeof(*p) returns the length of a pointer
	for(int i = 0; i != strlen(c1); ++i){
		p[i] = c1[i];
	}
	
	int len = strlen(c1);
	for(int i = 0; i!= strlen(c2); ++i){
		p[i + len] = c2[i];
	}

	p[strlen(c1) + strlen(c2) +1] = '\0';

	for(int i = 0; i!= sizeof(p);++i){
		cout << p[i] << endl;
	}
	return p;
}

string catWords(string s1, string s2)
{
	return s1 + s2;
}
