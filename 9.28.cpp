#include<iostream>
#include<forward_list>
#include<string>

std::forward_list<std::string>::iterator findNIns(std::forward_list<std::string>&,std::string,std::string);

int main()
{
	std::string s;
	std::forward_list<std::string> fls;
	while(std::cin >> s){
		fls.push_front(s);
	}

	for(auto s : fls){
		std::cout << s << std::endl;
	}

	//need to clear the statement of std::cin
	std::cin.clear();
	std::string s1,s2;
	std::cin >> s1 >> s2;
	findNIns(fls,s1,s2);

	for(auto s : fls){
		std::cout << s << std::endl;
	}

	system("pause");
	return 0;
}

std::forward_list<std::string>::iterator findNIns(std::forward_list<std::string>& fl, std::string finds, std::string inserts)
{
	auto iofls = ++fl.begin(), prev = fl.begin();
	while(iofls != fl.end()){
		if(*prev == finds){
			//insert_after(iter,t) insert_after(iter,n,t),insert_after(iter,iter,iter),insert_after(iter,{});
			return fl.insert_after(prev,inserts);
		}else{
			++prev;
			++iofls;
		}
	}

	return	fl.insert_after(prev,inserts);
}
