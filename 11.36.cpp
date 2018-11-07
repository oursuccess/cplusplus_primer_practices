#include<fstream>
#include"11.36.h"

using namespace std;

int main(int argc,char *argv[])
{
	ifstream input(argv[1]),mapFile(argv[2]);
	wordTransform(mapFile,input);

	system("pause");
	return 0;
}
