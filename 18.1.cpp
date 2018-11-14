#include<exception>
#include<iostream>

int main()
{
	try{
	std::range_error r("error");
	std::exception *p = &r;

	//range_error
	//throw r;
	//this is exception!
	throw *p;
	}

catch(std::range_error &r){
	std::cout << "range_error!";
}

catch(std::exception &e)
{
	std::cout << "exception!";
}
	system("pause");
	return 0;
}

