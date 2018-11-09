#include<vector>
#include<string>
#include<iostream>
#include<memory>
#include"Quote.h"

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::cout;
using std::vector;
using std::cin;
using std::endl;

int main()
{
	Bulk_quote bq1("test2",20,20,0.5);
	double sum = 0.0;

	vector<Quote> vq;
	for(int i = 0; i != 10; ++i){
		vq.push_back(bq1);
	}
	for(auto q : vq){
		sum += print_total(cout,q,50);
	}
	cout << "sum for vector<Quote>: " << sum << endl;
	sum = 0.0;

	vector<Bulk_quote> vb;
	for(int i = 0; i != 10; ++i){
		vb.push_back(bq1);
	}
	for(auto q : vb){
		sum += print_total(cout,q,50);
	}
	cout << "sum for vector<Quote>: " << sum << endl;
	sum = 0.0;

	vector<shared_ptr<Bulk_quote>> vsb;
	for(int i = 0; i != 10; ++i){
		vsb.push_back(make_shared<Bulk_quote>(bq1));
	}
	for(auto pq : vsb){
		sum += print_total(cout,*pq,50);
	}
	cout << "sum for vector<Quote>: " << sum << endl;
	sum = 0.0;



	system("pause");
	return 0;
}
