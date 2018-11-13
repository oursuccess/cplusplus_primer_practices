#include<iostream>

template<typename T>
void f1(T t1,T t2)
{
	std::cout << t1 << " t2: " << t2 << std::endl;
}

template<typename T1, typename T2>
void f2(T1 t1, T2 t2)
{
	std::cout << t1 << " t2: " << t2 << std::endl;
}

int main()
{
	int i = 0, j = 42, *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;

	f1(p1,p2);
	f2(p1,p2);
	f1(cp1, cp2);
	f2(cp1, cp2);
	//error : no matching function to f1(p1, cp1)
	//f1(p1,cp1);
	//this is correct
	f1(*p1,*cp1);
	f2(p1,cp1);

	system("pause");
	return 0;
}

