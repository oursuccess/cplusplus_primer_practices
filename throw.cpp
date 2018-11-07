#include<iostream>
#include<stdexcept>

using namespace std;

int error(string s)
{
	throw runtime_error(s);
	return 0;
}

int some_function()
{
	double d = 0;
	cin >> d;
	if(!d) error("wrong!");
	return 0;
}

int main()
{
	try{
		some_function();
		return 0;
	}

	catch(runtime_error& s){
		cerr << s.what();
		return 1;
	}
}
