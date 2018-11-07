#ifndef NODEFAULT
#define NODEFAULT

class NoDefault{
	//constructor
	public:
	NoDefault(int i):var(i),dir(i){printf("%d,%d\t",var,dir);}
	
	
	//var
	private:
	int var;
	int dir;
};

#endif