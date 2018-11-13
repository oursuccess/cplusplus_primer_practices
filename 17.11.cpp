#include<bitset>
#include<iostream>

template<size_t T>
class exam{
	public:
		exam() : s() {}
		size_t get_size() { return T;}
		void set_solution(size_t n, bool b) { s.set(n,b); }
		std::bitset<T> get_solution() const { return s; }
		size_t score( const std::bitset<T> &a);
	
	private:
		std::bitset<T> s;

};

template <size_t T>
size_t exam<T>::score(const std::bitset<T> &a)
{
	size_t ret = 0;

	for(size_t i = 0; i < T; ++i)
		if(s[i] == a[i])
			++ret;
	return ret;
}

int main()
{
	exam<80> e;
	e.set_solution(0,1);
	e.set_solution(79,1);
	std::cout << e.get_solution() << std::endl;

	std::bitset<80> a;
	std::cout << e.get_size() << "right" << e.score(a) << std::endl;

	return 0;
}
