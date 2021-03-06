#ifndef SALES
#define SALES

#include<iostream>
#include<string>

//this is from ch 16
//template <class T> class std::hash;

class Sales_data{
	public:
		//friend
		friend bool compareIsbn(const Sales_data&, const Sales_data&);
		friend std::istream& operator>>(std::istream &is, Sales_data& item);
		friend std::ostream& operator<<(std::ostream &os, const Sales_data &item);
		//ch16
		friend class std::hash<Sales_data>;
		friend bool operator==(const Sales_data &, const Sales_data &);
		friend Sales_data operator+(const Sales_data &item1, const Sales_data &item2);

	public:
		//constructor
		Sales_data(std::string s,unsigned u = 0,double r = 0):bookNo(s),units_sold(u),revenue(r){}
		Sales_data():Sales_data("",0,0.0){}
		Sales_data(std::istream&);
		
	public:
		//func
		std::string isbn() const {return bookNo;}
		std::ostream& printData(std::ostream& os = std::cout );

		//operater
		Sales_data& operator+=(const Sales_data &s)
		{
			units_sold += s.units_sold;
			revenue += s.revenue;
			return *this;
		}

	private:
		//private func

	private:
		//var
		std::string bookNo;
		unsigned units_sold;
		double revenue;
};

// = std::cin makes it a default constructor and cause an error
Sales_data::Sales_data(std::istream &in )
{
	double price;
	in >> bookNo >> units_sold >> price;
	revenue = price * units_sold;
}


std::istream& operator>>(std::istream &is,Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if(is){
		item.revenue = price * item.units_sold;
	}
	else{
		item = Sales_data();
	}
	return is;
}

//Sales_data::printData
std::ostream& Sales_data::printData(std::ostream& os)
{
	os << bookNo << " " << units_sold << " " << revenue;
	return os;
}

//为什么将compareIsbn置于新文件不可行？
bool compareIsbn(const Sales_data&, const Sales_data&);

//the followings are from ch 16
//define a hash version for Sales_data
namespace std{
	template<> //we are specialize a template
		struct hash<Sales_data>
		{
			//these are essetial
			typedef size_t result_type;
			typedef Sales_data argument_type;
			size_t operator()(const Sales_data &s) const;
		};
	size_t
		hash<Sales_data>::operator()(const Sales_data &s) const
		{
			return hash<std::string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
		}
}

bool operator==(const Sales_data &s1, const Sales_data &s2)
{
	return s1.bookNo == s2.bookNo && s1.units_sold == s2.units_sold && s1.revenue == s2.revenue;
}

std::ostream & operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " sales: " << item.units_sold << " ,earn " << item.revenue;
	return os;
}

Sales_data operator+(const Sales_data &item1, const Sales_data &item2)
{
	if(item1.isbn() == item2.isbn())
		return Sales_data(item1.isbn(), item1.units_sold + item2.units_sold, item1.revenue + item2.revenue);
}

//compare_isbn
bool compareIsbn(const Sales_data &item1, const Sales_data &item2)
{
	return item1.isbn() == item2.isbn();
}

#endif
