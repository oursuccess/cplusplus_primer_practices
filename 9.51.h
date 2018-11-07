#ifndef DATE
#define DATA

#include<string>

class Date_Me{
	//constructor
	public:
		Date_Me(unsigned y,unsigned m,unsigned d):year(y),month(m),date(d){}
		Date_Me():Date_Me(0,0,0){}
		Date_Me(std::string);


	//interface func
	public:
		//std::ostream&
		void printDate(std::ostream& os = std::cout){ os << "year: " << year << "\tmonth: " << month << "\tdate: " << date;}


	//val
	private:
		unsigned year;
		unsigned month;
		unsigned date;
};


#endif
