#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	std::cout << std::left
		<< setw(12) << sqrt(2.0) <<setw(12) << sqrt(3.0) << setw(12)  << sqrt(4.0)
		<< '\n' << setw(12) << sqrt(5.0) << setw(12) << sqrt(6.0) <<'\n';

	system("pause");
	return 0;
}
