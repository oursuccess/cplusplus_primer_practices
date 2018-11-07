#include<iostream>
#include<string>
#include"7.06.h"

int main()
{
	Sales_item total,item;
	double price;
	while(rea(std::cin,item)){
		if(total.isbn() == item.isbn()){
			total.combine(item);
		}else{
			prin(std::cout,total);
			//同一类型可以直接赋值
			total = item;
		}
	}
	prin(std::cout, total);
	
	return 0;
}


//Sales_item成员函数定义
Sales_item& Sales_item::combine(const Sales_item& rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_item& Sales_item::update(const Sales_item &rhs){
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}

//Sales_item接口函数
Sales_item add(const Sales_item &rhs1, const Sales_item &rhs2){
	if(rhs1.isbn() == rhs2.isbn()){
		//同一类型应该也可以直接初始化？ 未尝试，但未报错
		Sales_item temp(rhs1);
		temp.units_sold += rhs2.units_sold;
		temp.revenue += rhs2.units_sold;
		return temp;
	}else{
		std::cout << "please check isbn!" ;
		return rhs1;
	}
}
	
std::istream& rea(std::istream& in, Sales_item &rhs){
	double price;
	in >> rhs.bookNo >> rhs.units_sold >> price;
	rhs.revenue = price * rhs.units_sold;
	return in;
}

//注意声明 ou和in分别要声明为ostream和istream
std::ostream& prin(std::ostream& ou,const Sales_item &rhs){
	ou << rhs.bookNo << rhs.units_sold << rhs.revenue;
	return ou;
}
	