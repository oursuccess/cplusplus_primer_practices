#pragma once

#include<iostream>
#include<set>
#include<string>
#include<ctime>
#include<memory>

using std::istream;
using std::ostream;
using std::string;
using std::set;
using namespace std;

//the mails user get
//and can be stored and sorted to different folders
//every modify to this mail should be displayed to other place this message shows
//which means that a message should be copyed by reference or pointer
//and it should include a array which contains every folder it is tagged in
//so it could notice others to change: when copy or delete

class Message{
	//constructor
	public:
		Message(unsigned pr = 0):prior(pr){}
		Message(const string s,unsigned pr = 0):prior(pr){}

		Message(istream& is, unsigned pr = 0):t(time(null),prior(pr){
			is >> *_contents;
		}

		Message(const Message& m, unsigned pr = 0){
			_contents = new  string(*m._contents);
			time = time(null);
			prior = pr;
		}
	
	//friend
	public:
		friend class Folder;
	
	//operator
	public:
		//operator=: copy message to this, and delete this message,refresh all folders
		Message& operator=(const Message&);
		//operator<<: put the message out to the ostream
		friend ostream& operator<<(ostream&,const Message&);
		//operator>>: get the input and append it to this message
		friend instream& operator>>(istream&,Message&);
	
	//deconstructor
	public:
		~Message();
	
	//func
	public:
		//operate:
		//add to a folder
		bool addToFolder(Folder&);
		//remove from a folder
		void removeFromFolder(Folder&);
		//show folders this message in
		//void showFolders();
		//delete message
		//bool deleteMessage();
		//duplicate
		//Message& duplicate();
	
	//var
	private:
		//_contents of message
		//use shared_ptr, and you can not delete messages as your will
		string* _contents;
		set<Folder*> _folders;
		//sort by date a;
		//priority of a message the larger,the prior
		unsigned prior;
		time t;
		//change modify time
		void changeTime(){time = time(null);}

		//get the time last modify file
		string getTime(){
			char tmp[64];
			strftime(tmp,sizeof(tmp),"%Y-%m-%d %H:%M:%S",localtime(&nowtime));
			return tmp;
		}

};

Message& operator=(const Message& m)
{
	this -> changeTime();
	//use shared_ptr, so no need to care for free of memory
	_contents = m._contents;
	//when assign a message with another message, should U change all the folders that you want to change?
	//no
}

ostream& operator<<(ostream& os, const Message& m)
{
	os << "contents: " << *m._contents << "\tmodified time: " << getTime();
	return os;
}

istream& operator>>(istream& is, Message& m)
{
	changeTime();
	string tmp;
	is >> tmp;
	*m._contents += tmp;
	return is;
}

void addToFolder(Folder& f)
{
	_folders.insert(&f);
}
