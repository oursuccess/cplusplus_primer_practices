//需求：
//编写一个返回动态分配的int的vector的函数
//再编写一个接受此vector的函数，次函数读取标准输入，并将值保存至vector中
//第三个函数：接受此vector，打印其值
//

#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

vector<int>* setNewVecInt();
vector<int>* getIntForVec(vector<int>*,istream&in = cin);
void printVec(vector<int>*,ostream& ou = cout);

int main()
{
	vector<int>* np = setNewVecInt();
	vector<int>* np2 = getIntForVec(np);
	printVec(np);
	printVec(np2);

	delete np;
	delete np2;
	if(np){
		printVec(np);
	}

	system("pause");
	return 0;
}

vector<int>* setNewVecInt()
{
	return new(vector<int>);
}

vector<int>* getIntForVec(vector<int>* vp, istream& in)
{
	int i;
	while(in >> i){
		vp -> push_back(i);
	}

	return vp;
}

void printVec(vector<int> *np,ostream& ou)
{
	for(auto i : *np){
		cout << i << " ";
	}
	cout << endl;
}
