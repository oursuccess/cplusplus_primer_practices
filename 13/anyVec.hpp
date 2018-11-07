#pragma once

//a duplication of vector
//in order to support all operation vector give
//this class should have the following operations
//1. constructor
//	construct by typename
//		including these: construct by default, by initializer list, by other anyVec
//2. copy
//		copy the other anyVec
//3. insert more elems
//		push_back and insert  should consider capacity and reallocate if needed(capacity equal to size and need more space)
//4. delete elems
//		delete by elem, delete by iterator, delete by a range of itertors
//5. free space
//		when delete anyVec, free all space it occuipied

template<typename T> class anyVec
{
	//constructor
public:
	anyVec();
	anyVec(std::initializer_list<T>);
	anyVec(const anyVec&)
	//deconstructor
		~anyVec() {}
};



template<typename T>
anyVec<T>::anyVec<T>()
{
}
