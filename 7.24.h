#ifndef SCREEN
#define SCREEN

#include<string>

class Screen{
	
	//type alias
	using pos = std::string::size_type;
	
	public:
	//func
	//constructor
	Screen() = default;
	Screen(pos ht, pos wd):height(ht),width(wd),contents(ht*wd,' '){};
	
	//这里不能用数值+string初始化string
	/*
	//string初始化：
	//string s1       默认初始化，s1为一个空串
	//string s2(s1)   s2为s1的副本
	//string s2 = s1  与上方等价
	//string s3("value") 使用字面值（去掉了最后的空字符）初始化s3
	//string s3 = "value" 与上方等价
	//string s4(n, 'c') 将s4初始化n个c组成的常量
	*/
	Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c){};
	
	//func
	inline char getcursor(pos ht, pos wd) const;
	
	private:
	//var
	pos cursor =0;
	pos height = 0, width = 0;
	std::string contents;
	
};

char Screen::getcursor(pos r, pos c) const{
	pos row = r * width;
	return contents[row + c];
}

#endif