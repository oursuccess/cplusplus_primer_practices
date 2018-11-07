#pragma once

#include<set>
#include<string>

class Message;

class Folder {
public:
	//constructor

	//friend

	//operator

	//func
	void addMsg(Message *m) { messages.insert(m); }
	void remMsg(Message *m) { messages.erase(m); }

	//var
private:
	std::set<Message *> messages;

};
