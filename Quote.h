#pragma once
//this class appears in ch 15

#include<string>
#include<iostream>

using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Quote{
	public:
		//constructor
		Quote() = default;
		Quote(const std::string &book, double sales_price):bookNo(book),price(sales_price){}
		Quote(const Quote& qt){
			bookNo = qt.bookNo;
			price = qt.price;
			//debug
			//cout << "this is the Quote" << endl;
		}
		
		//operator
		Quote& operator=(const Quote& qt){
			bookNo = qt.bookNo;
			price = qt.price;
			cout << " this is the quote = " << endl;
			return *this;
		}

		//func
		std::string isbn() const { return bookNo;}

		//virtual
		virtual double net_price(std::size_t n) const{return n * price;}
		
		//deconstructor
		virtual ~Quote() = default;

		//ex 15.11
		virtual void debug() const { cout << "bookNo : " << bookNo << " price: " << price;}

	private:
		std::string bookNo;

	protected:
		double price = 0.0;
};

class Disc_quote : public Quote{
	public:
		Disc_quote() = default;
		Disc_quote(const std::string &s, double pr, std::size_t sz, double dc):Quote(s,pr),quantity(sz),discount(dc){}
		Disc_quote(const Disc_quote& dq):Quote(dq){
			quantity = dq.quantity;
			discount = dq.discount;
			//cout << " this is the disc_quote " << endl;
		}

		Disc_quote& operator=(const Disc_quote& dq){
			Quote::operator=(dq);
			quantity = dq.quantity;
			discount = dq.discount;
			//cout << " this is the disc_quote = " <<endl;
			return *this;
		}

		double net_price(std::size_t) const override = 0;

	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class Bulk_quote : public Disc_quote{
	public:
		Bulk_quote(const std::string &s, double pr, std::size_t sz, double dc):Disc_quote(s,pr,sz,dc){}
		Bulk_quote(const Bulk_quote& bq):Disc_quote(bq){}

		//operator
		Bulk_quote& operator=(Bulk_quote& bq){
			Disc_quote::operator=(bq);
			//cout << " this is the Bulk_quote = " << endl;
			return *this;
		}

		double net_price(std::size_t n) const override
		{
			if(n > quantity)
				return n * price * discount;
			else return n * price;
		}
};

class Less_quote : public Disc_quote{
	public: 
		Less_quote(const std::string &s, double pr, std::size_t sz, double dc):Disc_quote(s,pr,sz,dc){}
		Less_quote(const Less_quote& bq):Disc_quote(bq){}

		//operator
		Less_quote& operator=(Less_quote& bq){
			Disc_quote::operator=(bq);
			//cout << "this is the Less_quote = " << endl;
			return *this;
		}

		double net_price(std::size_t n) const override
		{
			if(n > quantity)
				return quantity * price * discount + (n - quantity) * price;
			else return n * price * discount;
		}
};

class Test_quote : public Disc_quote{
	public:
		using Disc_quote::Disc_quote;
		double net_price(std::size_t n) const override
		{
			if(n > quantity)
				return quantity * price * discount + (n - quantity) * price;
			else return n * price * discount;
		}
};

//use final to protect from inherited
//e.g. class Bulk_quote final : public Quote; 
/*
class Bulk_quote : public Quote{
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string&, double, std::size_t, double);

		//override
		double net_price(std::size_t) const override;
		
		//exer 15.11
		void debug() const override { Quote::debug(); cout << " min_qty: " << min_qty << " discount: " << discount;}

	private:
		std::size_t min_qty = 0;
		double discount = 0.0;
};


Bulk_quote::Bulk_quote(const std::string &s, double d1, std::size_t sz, double d2):Quote(s,d1),min_qty(sz),discount(d2){}

double Bulk_quote::net_price(std::size_t n) const 
{
	if(n > min_qty)
		return n * price * discount;
	else return n * price;
}

//class less_quote 
//ex no15.7
class Less_quote : public Quote{
	public:
		Less_quote() = default;
		Less_quote(const std::string&, double, std::size_t, double);

		double net_price(std::size_t) const override;

		//exer 15.11
		void debug() const override {Quote::debug(); cout << " max_qty: " << max_qty << " discount: " << discount;}

	private:
		std::size_t max_qty = 0;
		double discount = 0.0;
};

Less_quote::Less_quote(const std::string& s, double pr, std::size_t sz, double dc):Quote(s,pr),max_qty(sz),discount(dc){}

double Less_quote::net_price(std::size_t n) const
{
	if(n > max_qty)
		return max_qty * price * discount + (n - max_qty) * price;
	else return n * price * discount;
}
*/

//print_total, the virtual function
double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

