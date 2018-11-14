#include<iostream>

using namespace std;
using std::cout;
using std::endl;

int main()
{
	cout << boolalpha;
	cout << "boolalpha: " << "true: " << true << " false: " << false;
	cout << "noboolalpha: " << noboolalpha << "true: " << true << " false: " << false << endl;

	cout << "showbase: " << showbase << 29 << " " << 23 << " "<< 0X283 << " " << 034 << endl;
	cout << "noshowbase: " << noshowbase << 29 << " " << 23 << " " << 0X283 << " " << 034 << endl;

	cout << "showpointer: " << showpoint << 2.0 << " " << 0.0 << endl;
	cout << "noshowpoint: " << noshowpoint << 2.0 << " " << 0.0 << endl;

	cout << "showpos: " << showpos << 2 << " " << 3 << endl;
	cout << "noshowpos: " << noshowpos << 2 << " " << 3 << " " << -1 << endl;

	cout << "oct: " << oct << 28 << " " << 282838 << endl;
	cout << "hex: " << hex << 28 << " " << 282838 << endl;
	cout << uppercase << 28 << " " << 282838 << endl;
	cout << " dec and nouppercase: " << dec << 28 << " " << 282838 << endl;

	cout << "left: " << left << 28 << " " << 3 << endl;
	cout << "right: " << right << 28 << " " << 3 << endl;

	cout << "scientific: " << scientific << sqrt(2) << endl;
	cout << "fixed: " << fixed << sqrt(2) << endl;
	cout << "hexfloat: " << hexfloat << sqrt(2) << endl;
	cout << "defaultfloat: " << defaultfloat << sqrt(2) << endl;

	cout << "flush: " << flush;

	cout << "ends: " << ends;
	cout << "unitbuf: " << unitbuf;
	cout << 1 << 2 << 3;
	cout << "nounitbuf: " << nounitbuf;

	system("pause");
	return 0;
}
