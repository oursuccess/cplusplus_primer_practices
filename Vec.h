#pragma once

#include<string>
#include<memory>
#include<utility>

template<typename T>
class Vec{
	public:
		Vec() : elements(nullptr),first_free(nullptr),cap(nullptr){}
		Vec(std::initializer_list<T> il);
		Vec(const Vec &);
		Vec(Vec &&) noexcept;

		Vec&  operator=(const Vec&);
		Vec&  operator=(Vec&&) noexcept;

		~Vec();

		void push_back(const T &);
		size_t size() const { return first_free - elements; }
		size_t capacity() const { return cap - elements; }
		T *begin() const { return elements; }
		T *end() const { return first_free; }

		void reserve(size_t);
		void resize(size_t, T);

	private:
		static std::allocator<T> alloc;
		void chk_n_alloc() { 
			if(size() == capacity())
				reallocate();
		}
		std::pair<T*,T*> alloc_n_copy(const T*, const T*);
		void free();
		void reallocate();
		void reallocate(size_t);
		T *elements;
		T *first_free;
		T *cap;
};

template<typename T>
std::allocator<T> Vec<T>::alloc;

template<typename T>
Vec<T>::Vec(std::initializer_list<T> il)
{
	reallocate(il.size() * 2);
	alloc_n_copy(il.begin(),il.end());
}

template<typename T>
void Vec<T>::push_back(const T& s)
{
	chk_n_alloc();
	alloc.construct(first_free++,s);
}

template<typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *beg, const T *end)
{
	auto data  = alloc.allocate(end - beg);
	return { data, unitialized_copy(beg, end, data) };
}

template<typename T>
void Vec<T>::free()
{
	if(elements){
		for(auto p = first_free; p != elements; ){
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

template<typename T>
Vec<T>::Vec(const Vec &v)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T>
Vec<T>::~Vec() { free(); }

template<typename T>
Vec<T>& Vec<T>::operator=( const Vec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename T>
Vec<T>::Vec(Vec &&rhs) noexcept
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

template<typename T>
Vec<T>& Vec<T>::operator=(Vec &&rhs) noexcept
{
	if(this != &rhs){
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template<typename T>
void Vec<T>::reallocate(size_t sz)
{
	auto newcapacity = sz;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

template<typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	reallocate(newcapacity);
}

template<typename T>
void Vec<T>::reserve(size_t size)
{
	if(size > capacity()){
		auto newcapacity = size;
		reallocate(size);
	}
}

template<typename T>
void Vec<T>::resize(size_t sz, T s)
{
	if(sz > capacity()){
		auto newcapacity = sz * 2;
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for(size_t i = 0; i != size(); ++i)
		{
			alloc.construct(dest++, std::move(*elem++));
		}
		free();
		dest = unitialized_fill_n(dest, sz - size(), s);
		elements = newdata;
		first_free = dest;
		cap = elements + sz;
	}else if(sz > size()){
		first_free = uninitialized_fill_n(dest, sz - size(), s);
	}else{
		for(size_t i = size() - sz; i; --i){
			alloc.destroy(--first_free);
		}
		alloc.deallocate(first_free, cap - first_free);
	}
}

