#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<fstream>


void elimDups(std::vector<std::string>& vs,char* argv[]);

int main(int argc, char* argv[])
{
	std::ifstream in(argv[1]);
	if(in){
		std::string s;
		std::vector<std::string> vs;
		while(in >> s){
			vs.push_back(s);
		}

		elimDups(vs,&argv[1]);
	}

	system("pause");
	return 0;
}


void elimDups(std::vector<std::string>& vs,char* argv[])
{
	 std::ofstream ou(argv[1],std::ofstream::app);
	 if(ou){
		 for(auto s : vs){
			 std::cout << s <<std::endl;
			 ou << s << "\t";
		 }
		 ou << std::endl;
		 ou.close();
	 }



	 sort(vs.begin(),vs.end());
	 ou.open(argv[2],std::ofstream::app);
	 if(ou){
		 for(auto s : vs){
			 std::cout << s << std::endl;
			 ou << s << "\t";
		 }
		 ou << std::endl;
		 ou.close();
	 }



	 std::vector<std::string>::iterator end_unique = unique(vs.begin(),vs.end());
	 ou.open(argv[3],std::ofstream::app);
	 if(ou){
		 for(auto s : vs){
			 std::cout << s << std::endl;
			 ou << s << "\t";
		 }
		 ou << std::endl;
		 ou.close();
	 }
	 
	 vs.erase(end_unique,vs.end());
	 ou.open(argv[4],std::ofstream::app);
	 if(ou){
		 for(auto s : vs){
			 std::cout << s << std::endl;
			 ou << s << "\t";
		 }
		 ou << std::endl;
		 ou.close();
	 }
}
	 
