//����
//��дһ�����ض�̬�����int��vector�ĺ���
//�ٱ�дһ�����ܴ�vector�ĺ������κ�����ȡ��׼���룬����ֵ������vector��
//���������������ܴ�vector����ӡ��ֵ
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
