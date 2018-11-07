/*
//首先声明class，然后在window_mgr中定义Screen的模板，之后是定义Screen类，并声明clear为友元。
//这样可行吗？能声明后即创建Screen的模板，并初始化Screen?
//尝试不声明Window_mgr的clear函数
//书上有详细步骤…… window_mgr中声明，但不定义clear……问题是，报错的是screens啊
//教程去掉了window_mgr类内成员的初始化函数…… 过分了
*/

#ifndef WINDOW_MGR
#define WINDOW_MGR


class Screen;

/*
//test
Screen::Screen(pos ht, pos wd, char c);
//报错，提示需要析构函数等
*/

class Window_mgr{
	using ScreenIndex = std::vector<Screen>::size_type;
	public:
	//constructor
	//默认构造函数不能有函数体
	Window_mgr();
	
	void clear(ScreenIndex);
	
	private:
	//这里有对未定义类vector的无效引用
	//那为什么上面的类型别名就可以？
	//试下提前声明Screen的三参数版本构造函数
	//试试将window_mgr声明于screen下方
	//去掉这里的初始化函数体……
	//std::vector<Screen> screens{Screen(24,80, ' ')};
	std::vector<Screen> screens;
};



#include<string>

/*
//ScreenIndex尚未声明
//去掉clear中的形参呢？
//报错，提示无法使用未完成类window_mgr的友元
using ScreenIndex = std::vector<Screen>::size_type;
Window_mgr::clear(ScreenIndex);
//同样报错，而且报的更多了……
*/

class Screen{
	using pos = std::string::size_type;
	
	// friend
	friend void Window_mgr::clear(ScreenIndex);
	
	//constructor
	public:
	Screen() = default;
	Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,'c'){};
	
	//func
	Screen& set(char c){contents[cursor] = c; return *this;}
	Screen& set(pos r, pos c, char ch){contents[r*width+c] = c; return *this;}
	Screen& move(pos r, pos c){cursor = r*width + c;return *this;}
	//这里需要专门做一个do_display函数吗？
	//避免重复代码，并为未来增加函数功能做准备
	Screen& display(std::ostream& os){do_display(os); return *this;}
	const Screen& display(std::ostream& os) const {do_display(os);return *this;}
	
	private:
	//不要忘了这里的const
	void do_display(std::ostream& os) const{os << contents;}
	
	//var
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

Window_mgr::Window_mgr()
{
	/*
	//vector初始化方式：
	//vector<T> v1
	//vector<T> v2(v1)
	//vector<T> v2 = v1;
	//vector<T> v3(n,val);
	//vector<T> v4(n);
	//vector<T> v5{a,b,c...}
	//vector<T> v5 = {a,b,c...}
	*/
	//这里实在初始化screens这个string的vector，但事实上早已定义并默认初始化，因此需要执行的是插入元素操作；
	//screens{Screen(24,80,' ')};
	screens.push_back(Screen(24,80,' '));
}

void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

#endif





