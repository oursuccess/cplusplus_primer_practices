#include<iostream>
#include<memory>

struct destination{
	int i;
};

struct connection{
	int i;
};

connection connect(destination* d)
{
	std::cout << d -> i;
}

void disconnect(connection c)
{
	std::cout << c.i;
}

void end_connection(connection *p){disconnect(*p);}

void f(destination &d)
{
	connection c = connect(&d);
	std::shared_ptr<connection> p(&c,end_connection);

	//other func
	
}

int main()
{
	return 0;
}
