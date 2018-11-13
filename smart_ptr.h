#ifndef SMART_PTR
#define SMART_PTR

//shared_ptr:
//support these functions:
//shared_ptr<T> p --default construct
//shared_ptr<T> p = make_shared<T>(args) --copy and move assign, and args could be the followings: (), (n,'arg'), and(n)
//shared_ptr<T> q(q) --copy construct
//*p --dereference
//p.get() --returns the pointer p stored
//swap(p,q) --swap p and q
//p.swap(q) --same as above
//p.unique() --if use_count == 1, return true
//p.use_count() --return the use count of p
//and p should automatically deconstruct the elem
//shared_ptr<T> p(q,d) --assign p by pointer q, and use d as deconstructor(has default arguments)
//p.reset(q,d) --reset p by shared_ptr q, and could use d as deconstructor
//p.reset() --reset p,and if use_count equals to 0, deconstruct the memory

//out the shared_ptr:
//make_shared<T>(arg);

template<typename T>
class shared_ptr{
	//construcor
	public:
		shared_ptr(): ptr(new T),ptr_use_count(new size_t(1)),deconstruct(nullptr){}
		shared_ptr(const shared_ptr &s, void (*de)(T *)= nullptr):ptr(s.ptr),ptr_use_count(s.ptr_use_count),deconstruct(de){ ++*ptr_use_count; }
		shared_ptr(const T *t, void (*de)(T*) = nullptr):ptr(t),ptr_use_count(new size_t(1)),deconstruct(de){}
		shared_ptr(T *t, void (*de)(T*) = nullptr):ptr(t),ptr_use_count(new size_t(1)),deconstruct(de){}
		~shared_ptr(){
			if(!--*ptr_use_count){
				deleteThis();
			}
		}
	
	//operator
	public:
		shared_ptr& operator=(const shared_ptr &s)
		{
			if(*this == s)
				return *this;
			++*s.ptr_use_count;
			if(!--*ptr_use_count)
				deleteThis;
			ptr = s.ptr;
			ptr_use_count = s.ptr_use_count;
			deconstruct = s.deconstruct;
			return *this;
		}

		shared_ptr& operator=(shared_ptr &&stmp)
		{
			if(*this == s)
				return *this;
			++*s.ptr_use_count;
			if(!--*ptr_use_count)
				deleteThis;
			ptr = s.ptr;
			ptr_use_count = s.ptr_use_count;
			deconstruct = s.deconstruct;
			stmp.ptr = nullptr;
			s.ptr_use_count = nullptr;
			s.deconstruct = nullptr;
			return *this;
		}

		const T* operator->() const 
		{
			return ptr;
		}

		T* operator->() 
		{
			return ptr;
		}

		const T& operator*() const 
		{
			return *ptr;
		}

		T& operator*()
		{
			return *ptr;
		}
	
	//friend
	
		friend bool operator==(const shared_ptr &s1, const shared_ptr &s2);
		friend void swap(shared_ptr &s1, shared_ptr &s2);
		friend shared_ptr make_shared(T);

	//function
		bool unique()
		{
			return *ptr_use_count == 1 ? true : false;
		}

		size_t use_count()
		{
			return *ptr_use_count;
		}

		void reset()
		{
			if(--*ptr_use_count)
				deleteThis();
			ptr = nullptr;
			deconstruct = nullptr;
			ptr_use_count = nullptr;
		}

		void reset(const shared_ptr &s, void (*)(T*) = nullptr)
		{
			*this = s;
		}

		void swap(shared_ptr &s)
		{
			using std::swap;
			swap(ptr, s.ptr);
			swap(ptr_use_count, s.ptr_use_count);
			swap(deconstruct, s.deconstruct);
		}
	
	//member
	private:
			T* ptr;
			size_t* ptr_use_count;
			void (*deconstruct)(T*) ;
			void deleteThis(){
				if(deconstruct){
					deconstruct(ptr);
				}else{
					delete ptr;
				}
				delete ptr_use_count;
			}
};

template<typename T>
bool operator==(const shared_ptr<T> &s1, const shared_ptr<T> &s2)
{
	return s1.ptr == s2.ptr ? true : false;
}

template<typename T>
void swap(shared_ptr<T> &s1, shared_ptr<T> &s2)
{
	using std::swap;
	swap(s1.ptr, s2.ptr);
	swap(s1.ptr_use_count, s2.ptr_use_count);
	swap(s1.deconstruct, s2.deconstruct);
}

template<typename T>
shared_ptr<T> make_shared(T t)
{
	return shared_ptr<T>(new T(t));
}

#endif
