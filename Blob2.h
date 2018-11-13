#ifndef BLOB
#define BLOB

#include<vector>
#include"smart_ptr.h"

template <typename T>
class Blob{
	public:
		typedef T value_type;
		typedef typename std::vector<T>::size_type size_type;

		//constructor
		Blob(const T &t = 0):data(new std::vector<T>(t)){};
		//Blob(std::initializer_list<T> il);

		//get nums in Blob
		size_type size() const { return data -> size(); }
		bool empty() const { return data -> empty(); }
		
		//push_back and pop_back
		void push_back(const T &t) { data -> push_back(t); }
		//move version
		void push_back(T &&t) { data -> push_back(std::move(t)); }
		void pop_back();
		//visit elem
		T& back();
		T& operator[](size_type i);

	private:
		shared_ptr<std::vector<T>> data;
		//check range of i
		void check(size_type i, const std::string &msg) const;
};

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
	check(i,"range_error");
	return (*data)[i];
}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if(data -> size() < i - 1)
		throw out_of_range(msg);
}

#endif
