#ifndef SCREEN
#define SCREEN

#include<string>

class Screen{
	//type alias
	using pos = std::string::size_type;
	
	//friend
	
	
	//constructor
	//在有构造函数时将不再合成默认构造函数，因此需要显式声明
	public:
	Screen() = default;
	Screen(pos ht, pos wd):height(ht),width(wd){}
	Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c){}
	
	//func
	//声明时默认为非inline函数
	Screen& set(char);
	Screen& set(pos, pos, char);
	
	Screen& move(pos r, pos c);
	
	char get(pos , pos) const;
	
	//display根据参数是否常量进行的重载
	Screen& display(std::ostream&);
	const Screen& display(std::ostream&) const;
	
	private:
	void do_display(std::ostream& os) const {os << contents;}
	
	//var
	private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
};

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos ht, pos wd, char c)
{
	contents[ht*width + wd] = c;
	return *this;
}

//忘了函数名
inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}	

//wangle必须声明为引用
Screen& Screen::display(std::ostream& os)
{
	//这儿需要再次声明Screen空间吗？
	do_display(os);
	return *this;
}

const Screen& Screen::display(std::ostream& os) const
{
	do_display(os);
	return *this;
}

#endif