#include<iostream>
#include<set>
#include<string>

bool compareIsbn(const std::string &s,const std::string &s2)
{
	return s < s2;
}

class Sales_data{
	public:
		std::string isbn() const{return bookNo;}
	private:
		std::string bookNo;
};

int main()
{
	std::multiset<Sales_data,decltype(compareIsbn)*> bookstore(compareIsbn);
	auto testVar = bookstore.begin();
	std::multiset<Sales_data,bool(*)(const std::string&,const std::string &)>::iterator test2(bookstore.begin());

	return 0;
}
