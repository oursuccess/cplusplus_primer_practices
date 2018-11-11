#ifndef BLOB
#define BLOB

#include<iostream>
#include<memory>
#include<exception>
#include<vector>

template<typename T>
class Blob{
	public:
		typedef T value_type;
		//use typename to declare that the sizename is member of class
		using size_type = typename std::vector<T>::size_type;

		Blob();
		Blob(std::initializer_list<T> il);
		//the nums of elems in Blob;
		size_type size() const { return data -> size(); }
		bool empty() const { return data -> empty(); }
		//insert and delete elements
		void push_back(T &&t) { data -> push_back(std::move(t)); }
		void push_back(const T &t) { data -> push_back(t); }
		void pop_back();

		//visit elem
		T& back();
		T& operator[](size_type i);

	private:
		std::shared_ptr<std::vector<T>> data;
		//if data[i] is invalid, throw a msg
		void check(size_type i, const std::string &msg) const;
};

template<typename T>
Blob<T>::Blob(){ data = std::make_shared<std::vector<T>>(); }

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il)
{
	data = std::make_shared<std::vector<T>>(il);
}

template<typename T>
void Blob<T>::pop_back()
{
	data -> pop_back();
}

template<typename T>
T& Blob<T>::back() 
{
	return data -> back();
}

template<typename T>
T& Blob<T>::operator[](size_type i) 
{
	check(i, "range invalid!");
	return (*data)[i];
}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if(data -> size() < i)
		std::cerr(msg);
}

//BlobPtr
template<typename T>
class BlobPtr{
	public:
		BlobPtr():curr(0){}
		BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

		T& operator*() const{
			auto p = check(curr, "dereference past end");
			return (*p)[curr];
		}

		BlobPtr& operator++();
		BlobPtr& operator--();

		//operator== should be a template
		friend bool operator==<T>(const BlobPtr &b1, const BlobPtr &b2);
		friend bool operator<(const BlobPtr &b1, const BlobPtr &b2);

	private:
		//if true, the check returns a shared_ptr to vector
		std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
		//keep a weak_ptr, declares that vector may be deleted
		std::weak_ptr<std::vector<T>> wptr;
		std::size_t curr;
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	return *this;
}

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t sz, const std::string& s) const
{
	auto tp = lock();
	if(tp.size() > sz)
		return tp;
	else throw std::out_of_range(s);
}

template<typename T>
bool operator==<T>(const BlobPtr<T> &b1, const BlobPtr<T> &b2){
	return b1.lock() == b2.lock() && b1.curr == b2.curr;
}

template<typename T>
bool operator<(const  BlobPtr<T> &b1, const BlobPtr<T> &b2){
	return b1.curr < b2.curr;
}

#endif
