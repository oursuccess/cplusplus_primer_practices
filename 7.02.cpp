#include<iostream>
#include<string>
#include<stdexcept>
#include"7.01.h"

int main()
{
	Sales_data total,rhs;
	double price = 0;
	while(std::cin >> rhs.bookNo >> rhs.units_sold >> price){
		rhs.revenue = price * rhs.units_sold;
		if(total.isbn() == rhs.isbn())
			total.combine(rhs);
		else{
			std::cout << total.bookNo << total.units_sold << total.revenue <<std::endl;
			total.update(rhs);
		}
	}
	std::cout << total.bookNo << total.units_sold << total.revenue <<std::endl;
	
	return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
	
Sales_data& Sales_data::update(const Sales_data& rhs){
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const{
	return revenue/units_sold;
}


Sales_data add(const Sales_data& rhs1, const Sales_data& rhs2){
	if(rhs1.isbn() == rhs2.isbn())
	{
		Sales_data tmp;
		tmp.bookNo = rhs1.bookNo;
		tmp.units_sold = rhs1.units_sold + rhs2.units_sold;
		tmp.revenue = rhs1.revenue + rhs2.revenue;
		return tmp;
	}else{
		throw std::runtime_error("Data must refer to same ISBN!");
	}
}
	
/*
//bug过多
	std::ostream& prin(std::ostream& o, const Sales_data& rhs){
	o << rhs.bookNo << " " << rhs.units_sold << " " << rhs.revenue << " " << rhs.avg_price();
	return o;
}

std::istream& rea(std::istream& i, Sales_data& rhs){
	double price = 0;
	i >> rhs.bookNo >> " " >> rhs.units_sold >> " " >> price;
	rhs.revenue = price * rhs.units_sold;
	return i;
}
*/
	
	
	