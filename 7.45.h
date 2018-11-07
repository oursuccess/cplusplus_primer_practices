#ifndef NODEFAULT
#define NODEFAULT
//???为什么define C会出错？

class NoDefault{
	//constructor
	public:
	NoDefault(int i):var1(i),var2(i){printf("%d,%d\t",var1,var2);}
	
	
	//var
	private:
	int var1;
	int var2;
	
};

class C{
	//constructor
	public:
	C():b(0){}
	//C(int i):b(i){}
	
	//var
	private:
	NoDefault b;
};

#endif