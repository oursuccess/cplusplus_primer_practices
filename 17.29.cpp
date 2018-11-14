#include<iostream>
#include<utility>
#include<random>

using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::pair;


//set two class may be much better
class makeRandom{
	typedef std::default_random_engine random;
	typedef std::uniform_int_distribution<unsigned> randomRange;
	public:
		//constructor
		makeRandom() : e(){}
		makeRandom(unsigned s) : e(s) {}
		makeRandom(unsigned min, unsigned max) : e(),range(min,max),set(true){}

		//func
		unsigned out() {
			if(set)
				return range(e);
			else 
				return e();
		}

		//operator
		//friend ostream& operator<<(ostream &, const makeRandom &);

	private:
		random e;
		randomRange range;
		bool set;
};

ostream& operator<<(ostream &os, makeRandom &m)
{
	return os << m.out() << endl;
}

int main()
{
	makeRandom e;
	cout << "e" << endl;
	for(auto i = 0; i != 10; ++i){
		cout << e << endl;
	}

	makeRandom f(255);
	cout << "e(255)" << endl;
	for(auto i = 0; i != 10; ++i){
		cout << f << endl;
	}

	makeRandom g(0,256);
	cout << "e(0,256)" << endl;
	for(auto i = 0; i != 10; ++i){
		cout << g << endl;
	}

	system("pause");
	return 0;
}
