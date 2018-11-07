#ifndef EXAMPLE
#define EXAMPLE

#include<vector>

class Example{
	public:
	/*
	//'constexpr' needed for in-class initialization of static data member 'double Example::rate' of non-integral type[-fpermissive]
	static double rate = 6.5;
	//'vecSize' is not a type
	static const int vecSize = 20;
	//'std::vector<double> Example::vec' is not a static data member of 'class Example'
	static std::vector<double> vec(vecSize);
	*/
	
	//right version:
	//declare in class but define out
	static double rate;
	//except for const int
	static const int vecSize = 20;
	static std::vector<double> vec;
};

#endif