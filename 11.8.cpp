#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
	std::string s;
	std::vector<std::string> vs;

	while(std::cin >> s){
		//find默认为空容器
		//或 而非 与
		if(!vs.size() || find(vs.begin(),vs.end(),s) == vs.end()){
			vs.push_back(s);
		}
	}

	for(auto s : vs){
		std::cout << s << " ";
	}
	
	system("pause");
	return 0;
}

