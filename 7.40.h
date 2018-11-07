#ifndef BOOK
#define BOOK

#include<string>
//忘了iostream
#include<iostream>

class Book{
	//构造函数和结构函数不声明为public会凉
	public:
	//constructor
	Book(std::string name,std::string isb,std::string pub,std::string auth,unsigned ed,unsigned yea,unsigned mon,double pri):
	bookName(name),isbn(isb),publisher(pub),author(auth),edition(ed),year(yea),month(mon),price(pri){printBook(std::cout);}
	//可以这样直接用printBook输出吗？
	
	//default constructor
	Book():Book("","","","",0,0,0,0){}
	
	//delegating constructor
	Book(std::string name,double price):Book(name,"","","",0,0,0,price){}
	//这样可以吗？
	Book(std::string name,std::string auth,unsigned ed,double pri):Book(){
		bookName = name;
		author = auth;
		edition = ed;
		price = pri;
	}
	/*
	//这样可以吗？
	// 委托构造函数无法与函数初始化列表共同出现？
	Book(std::string name,std::string author,double price):Book(),bookName(name){}
	*/
	
	//func
	std::ostream& printBook(std::ostream& os = std::cout)
	{
		os << bookName << isbn << publisher << author << edition << year << month << price;
		return os;
	}
	
	
	//var
	private:
	std::string bookName;
	std::string isbn;
	std::string publisher;
	std::string author;
	unsigned edition;
	
	/*
	//类里能包含类吗？
	class pubTime{
		unsigned year;
		unsigned month;
	};
	*/
	unsigned year;
	unsigned month;
	double price;
};

#endif