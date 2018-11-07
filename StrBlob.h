#ifndef STRBLOB
#define STRBLOB

#include<vector>
#include<string>
#include<memory>
#include<stdexcept>
#include<iostream>

class StrBlobPtr;

class StrBlob {
	typedef std::vector<std::string>::size_type size_type;

	//friend
public:
	friend class StrBlobPtr;

	//constructor
public:
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);

	//operator
	friend std::ostream& operator<<(std::ostream&, const StrBlob&);
	StrBlob& operator=(const StrBlob&);

	//func
public:
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back() const;
	StrBlobPtr begin() {return StrBlobPtr(*this);}
	StrBlobPtr end() {auto ret = StrBlobPtr(*this, data->size()); return ret;}

	//func
private:
	void check(size_type i, const std::string &msg) const;

	//var
private:
	std::shared_ptr<std::vector<std::string>> data;

};

#endif
