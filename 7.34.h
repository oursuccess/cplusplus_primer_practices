#ifndef SCREEN
#define SCREEN

#include<string>

class Screen{
	
	//friend
	
	//constructor
	public:
	Screen() = default;
	Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c){}
	
	//func
	public:
	Screen set(char);
	Screen set(pos, pos,char);
	Screen move(pos, pos);
	Screen display(std::ostream &os){do_display(os); return *this;}
	Screen display(std::ostream &os) const {do_display(os); return *this;}
	
	private:
	void do_display(std::ostream &os) const{ os << contents;}
	
	//var
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
	//将pos的别名置于类最后
	//pos未声明……
	//type alias
	using pos = std::string::size_type;
};

inline Screen Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

inline Screen Screen::set(pos r, pos c, char ch)
{
	contents[r*width+c] = ch;
	return *this;
}

inline Screen Screen::move(pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}


#endif