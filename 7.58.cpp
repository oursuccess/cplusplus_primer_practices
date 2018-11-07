#include<vector>
#include"7.58.h"

double Example::rate = 6.5;
//expected initializer before '<' token
//'(' instead of '<'
//vector的初始化方式： ( { =
std::vector<double> Example::vec(Example::vecSize);

int main()
{
	
	return 0;
}