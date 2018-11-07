#include<memory>
#include<vector>
#include<iostream>

using std::shared_ptr;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::make_shared;
using std::istream;
using std::ostream;

shared_ptr<vector<int>> setNewVecInt();
shared_ptr<vector<int>> getNumForVec(shared_ptr<vector<int>>, istream& = cin);
void printNum(shared_ptr<vector<int>>,ostream& = cout);

int main()
{
	auto sp = setNewVecInt();
	auto sp2 = getNumForVec(sp);
	printNum(sp);
	printNum(sp2);

	system("pause");
	return 0;
}

shared_ptr<vector<int>> setNewVecInt()
{
	return make_shared<vector<int>>();
}

shared_ptr<vector<int>> getNumForVec(shared_ptr<vector<int>> spvi, istream& in)
{
	int i;
	while(in >> i){
		spvi -> push_back(i);
	}
	
	return spvi;
}

void printNum(shared_ptr<vector<int>> spvi, ostream& os)
{
	for(auto i : *spvi)
	{
		os << i << " ";
	}
	os << endl;
}
