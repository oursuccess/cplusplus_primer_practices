#include<iostream>
#include<vector>

using namespace std;

int p(int i , int j)
{
    return i+j;
}

int s(int i , int j)
{
    return i-j;
}


int main()
{
    int i,j;
	//mingw里的报错看不懂  应该是<int (*)(int, int)>
    vector<int (*)(int, int)> vt;

    while(cin >> i >> j){
        cout << p(i,j) << s(i,j) << endl;
    }


    return 0;
}
