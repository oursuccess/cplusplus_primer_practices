#ifndef NODEFAULT
#define NODEFAULT

class NoDefault{
	//constructor
	public:
	NoDefault(int i):var1(i),var2(i){printf("%d, %d",var1,var2);};
	
	//var
	private:
	int var1;
	int var2;
};

class C{
	//constructor
	public:
	//default constructor of 'C' is implicitly deleted because field ='a' has no default constructor
	//显式标注 = default是错误的，因为程序无法自动生成默认构造函数;
	//可以先声明b，但不定义，在构造C的时候，才会真正出现b这个变量
	C():b(0){};
	
	//var
	private:
	//为什么这儿要加入 int i?
	//为什么这里没有对var的输出？
	//大括号之后是什么？
	
	
	NoDefault b;
	
	//{} 的含义为声明变量的空间
	//NoDefault b{2};
};



/*
	//另一种实现方式
	class C{
		c();
		
		private:
		NoDefault *b=new NoDefault();
		b(0);
	};
*/

#endif