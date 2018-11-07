#include<vector>
#include<string>
#include<memory>
#include<stdexcept>
#include<iostream>
#include"StrBlob.h"


void StrBlob::check(size_type i, const std::string &msg) const
{
	if(i >= data -> size())
		throw std::out_of_range(msg);
}

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>> ()){}
StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)){}

void StrBlob::pop_back()
{
	check(0,"class is void!");
	data -> pop_back();
}

std::string& StrBlob::front()
{
	check(0,"class is void!");
	return data -> front();
}

const std::string& StrBlob::back() const
{
	check(0,"class is void");
	return data -> back();
}

const std::string& StrBlob::front() const
{
	check(0,"class is void!");
	return data -> front();
}

std::string& StrBlob::back()
{
	check(0,"class is void");
	return data -> back();
}

std::ostream& operator<<(std::ostream& ou, const StrBlob& tmp)
{
	for(auto s : *tmp.data){
		ou << s << " ";
	}
	return ou;
}

StrBlob& StrBlob::operator=(const StrBlob& tmp)
{
	data = tmp.data;
	return *this;
}

