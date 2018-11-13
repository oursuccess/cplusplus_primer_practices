#include<vector>

template<typename T>
void g(T&& val)
{
	std::vector<T> v;
}

int main()
{
	g(42);
	int i = 42;
	g(42);

	system("pause");
	return 0;
}
