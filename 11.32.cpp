#include<iostream>
#include<map>
#include<string>
#include<set>
#include<utility>

//将读取的作者与书籍的组合按字典序输出

int main()
{
	std::string name,book;
	std::multimap<std::string,std::string> bookOfAuthor;  //声明一个<string,string>类型的multimap容器
	while(std::cin >> name){ //读入作者名称
		std::cin >> book;  //读入书籍名称
		bookOfAuthor.insert(make_pair(name,book)); //将作者与书名插入容器
	}

	std::map<std::string,std::set<std::string>> bookSorted; //声明一个<string,set<string>>的map容器
	for(auto p : bookOfAuthor){ //遍历上面的<string,string>容器
		//set容器无法进行insert操作 错误
		//insert({}) 即使是单元素的set也不能省略大括号
		bookSorted[p.first].insert({p.second}); //将其元素插入新的容器中
	}


	for(auto p : bookOfAuthor){
		std::cout << p.first << " " << p.second << std::endl;zha 
	}

	for(auto p : bookSorted){
		std::cout << p.first << " ";
			for (auto s : p.second) {
				std::cout << s << " ";
			}
	}


	system("pause");
	return 0;
}

