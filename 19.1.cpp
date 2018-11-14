#include<cstdlib>

class test{
	public:
		int num(){return i;}
	private:
		int i;
};
		
void* operator new(size_t n){
	return static_cast<test *>(malloc(n * sizeof(test)));
}

void operator delete(void *p){
	free(p);
}

int main()
{


}

