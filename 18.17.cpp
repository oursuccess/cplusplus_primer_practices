
namespace Exercise{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

int main()
{
	//original ver : could not find limit
	double dvar = 3.14;
	int iobj = limit + 1;
	++ivar;
	++::ivar;

	system("pause");
	return 0;
}

