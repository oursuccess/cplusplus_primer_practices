#include<memory>
using std::unique_ptr;

int main()
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//ix is of type int ,not *int
	//IntP p0(ix);
	IntP p1(pi);
	IntP p2(pi2);
	IntP p3(&ix);
	IntP p4(new int(2048));
	IntP p5(p2.get());

	return 0;
}
