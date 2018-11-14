#include<iostream>

using namespace std;

int main()
{
	std::cout << "default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n' 
		<< "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		<< "hexadecimal and uppercase" << hexfloat << uppercase << 100 * sqrt(2.0) << '\n'
		<< " use defaults: " << defaultfloat << 100 * sqrt(2.0) << std::endl;

	system("pause");
	return 0;
}

