#include<iostream>
#include<string>
#include<fstream>

std::string autoIndent(std::string,const char*,const char*);

int main(int argc,char *argv[])
{
	std::string s;
	std::ofstream ou(argv[1],std::ofstream::app);
	if(ou){
		std::cout << "please type in names: " << std::endl;
		//*app not app
		const char* pre = "and: ", *app = "(s);";
		while(std::cin >> s){
			ou << autoIndent(s,pre,app) << std::endl;
		}
	}

	system("pause");
	return 0;
}

std::string autoIndent(std::string s, const char* pre, const char* app)
{
	//return pre + s + app;
	//
	/*
	s.append(app);
	s.insert(s.begin(),pre);
	return s;
	*/
	//insert(pos,str) or(iter,iter,iter)
	return s.insert(0,pre).append(app);
}
