#ifndef GRAPH
#define GRAPH

#define pi 3.141516

class graph{
	public:
		graph(double l):length(l){}
		virtual double pcrimeter() = 0;
	protected:
		double length;
};

class graph_2d : public graph{
	public:
		graph_2d(double l, double w):graph(l),width(w){} 
		virtual double area() = 0;
	protected:
		double width;
};

class line : public graph{
	public:
		line(double l):graph(l){}
		double pcrimeter() { return length; }
};

class circle final : public graph_2d{
	public:
		circle(double radius, double tmp = 0):graph_2d(radius,tmp){}
		double radius() { return length;}
		double pcrimeter(){ return pi * radius(); }
		double area() { return pi * radius() * radius(); }
};

class rectangle final : public graph_2d{
	public:
		rectangle(double l, double w):graph_2d(l,w){}
		double length() { return graph::length; }
		double width() { return graph_2d::width; }
		double pcrimeter(){ return 2 * (length() + width()); }
		double area(){ return length() * width(); }
};

#endif
