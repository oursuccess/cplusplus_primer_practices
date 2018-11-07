
/*
//声明错误，无法包括一个尚未定义的对象
//forward declaration
class X;

class Y{
	X item;
};


class X{
	Y *ptry;
};
*/


//下面正确，首先声明Y，随后声明成员为Y的指针的X，之后是成员为X的Y。
//目测指向类的指针大小固定
class Y;

class X{
	Y *ptr;
};

class Y{
	X item;
};


int main()
{
	X a;
	Y b;
	
	return 0;
}