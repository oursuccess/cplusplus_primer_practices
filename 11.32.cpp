#include<iostream>
#include<map>
#include<string>
#include<set>
#include<utility>

//����ȡ���������鼮����ϰ��ֵ������

int main()
{
	std::string name,book;
	std::multimap<std::string,std::string> bookOfAuthor;  //����һ��<string,string>���͵�multimap����
	while(std::cin >> name){ //������������
		std::cin >> book;  //�����鼮����
		bookOfAuthor.insert(make_pair(name,book)); //��������������������
	}

	std::map<std::string,std::set<std::string>> bookSorted; //����һ��<string,set<string>>��map����
	for(auto p : bookOfAuthor){ //���������<string,string>����
		//set�����޷�����insert���� ����
		//insert({}) ��ʹ�ǵ�Ԫ�ص�setҲ����ʡ�Դ�����
		bookSorted[p.first].insert({p.second}); //����Ԫ�ز����µ�������
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

