#ifndef FOLDER
#define FOLDER

//the folder contains every message users tagged in
//and consider efficient and modify
//the message should be stored as pointer
//and to not include the same message twice it should be stored as a set or check when stored in a vector

#include<set>

using std::set;

class Folder{
	//constuctor
	public:
		Folder();
		Folder(Folder& f){_messages = f._messages;}
		Folder(initializer_list<Message> &m){
			_messages.insert(&m);
		}
	
	//friend
	public:
		friend class Message;
	
	//operator
		Folder& operator=(const Folder& f){
			_messages = f._messages;
			return *this;
		}
	
	//deconstructor
	public:
		~Folder(){} = default;
	
	//func
	public:
		//choose messages
		// how to allow users to choose two iters one time?
		set<Message*> chooseMessage(Message &m){
			chooses.insert(&m);
			cout << "m has been choosed!" << endl;
			return chooses;
		}

		//delete from folders
		void deleteMessagesFromFolder(){
			_messages.remove(chooses.begin(),chooses.end());
		}


		//delete messages 
		void deleteMessages(){
			for_each(chooses.begin(),chooses.end(),);
		}
			
	
	//var
	private:
		set<Message*> _messages;
		set<Message*> chooses;
};


#endif
