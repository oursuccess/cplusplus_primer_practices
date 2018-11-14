#include<string>
#include<regex>
#include<iostream>

using namespace std;

smatch m;

bool valid(const smatch &m)
{
	if(m[1].matched)
		//return (m[2].matched && m[3].matched) || (m[2].length() == 0 && (m[3].length() == 0 || m[3].matched));
		//m[3] could not match
		return m[3].matched || (!m[3].matched && !m[2].matched );
	else return false;
}

int main()
{
	//[]? need () too
	string s("(\\d{5})([- ])?(\\d{4})?");
	//\\d{5} part 1($1)  \\d{4} part 3($3)
	string fmt = "$1-$3";
	regex r(s);

	string post;
	while(getline(std::cin,post)){
		//cout << regex_replace(post, r, fmt, std::regex_constants::format_no_copy) << endl;
		for(sregex_iterator it(post.begin(), post.end(), r), end_it; it != end_it; ++it){
			if(valid(*it))
			{
				cout << it -> str() << endl;
				cout << "valid: " << regex_replace(it -> str(),r,fmt,std::regex_constants::format_no_copy) << endl;
			}
			else
				cout << "not valid: " << it -> str() << endl;
		}
	}

	system("pause");
	return 0;
}
