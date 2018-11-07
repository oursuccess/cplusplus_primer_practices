#ifndef SCREEN
#define SCREEM

#include<iostream>

class Screen{
	public:
	using pos = std::string::size_type;
	
	//constrcutor
	Screen() = default;
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
	
	//func
	char gercursor() const{ return contents[cursor];}
	inline char getcursor(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	void some_member() const;
	
	private:
	mutable size_t access_ctr;
	
	private:
	//var
	pos cursor = 0;
	pos height = 0,width = 0;
	std::string contents;
	
};

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row +c;
	return *this;
}

char Screen::getcursor(pos r, pos c) const
{
	pos row = r*width;
	return contents[row + c];
}

void Screen::some_member() const
{
	++access_ctr;
}

#endif

#ifndef WINDOW_MGR
#define WINDOW_MGR

#include<vector>

class Window_mgr{
	
	
	private:
	std::vector<Screen> Screens{Screen(24,80,' ')};
};

#endif