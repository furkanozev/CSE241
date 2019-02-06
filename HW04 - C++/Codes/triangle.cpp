#include <iostream>
#include "triangle.h"	

using namespace std;

	/* Composition used in this part. */
	// Constructor 1: No parameter
	Triangle::Triangle()
	{	}
	
	// Constructor 2: get edge
	Triangle::Triangle(double edge_val)
						:edge(edge_val)
	{
		posx1 = edge / 2;
		posy1 = 0;
		posx2 = 0;
		posy2 = edge/2.0*sqrt(3);
		posx3 = edge;
		posy3 = edge/2.0*sqrt(3);;
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();	
	}
	
	// Constructor 2: get edge and all point of triangle.
	Triangle::Triangle(double edge_val, double posx1_val, double posy1_val, double posx2_val, double posy2_val, double posx3_val, double posy3_val)
						:edge(edge_val), posx1(posx1_val), posy1(posy1_val), posx2(posx2_val), posy2(posy2_val), posx3(posx3_val), posy3(posy3_val)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();	
	}
	
	/* Static member initilaze */
	double Triangle::total_area=0;
	double Triangle::total_perimeter=0;
	
	/* Setter */
	void Triangle::setedge(double edge_val)
	{
		edge = edge_val;
	}
	
	void Triangle::setposx1(double posx_val)
	{
		posx1 = posx_val;
	}
	
	void Triangle::setposy1(double posy_val)
	{
		posy1 = posy_val;
	}
	
	void Triangle::setposx2(double posx_val)
	{
		posx2 = posx_val;
	}
	
	void Triangle::setposy2(double posy_val)
	{
		posy2 = posy_val;
	}
	
	void Triangle::setposx3(double posx_val)
	{
		posx3 = posx_val;
	}
	
	void Triangle::setposy3(double posy_val)
	{
		posy3 = posy_val;
	}
	
	void Triangle::setcolor(string color_val)
	{
		color = color_val;
	}
	
	/* Getter */
	double Triangle::getedge()  const
	{
		return edge;
	}
	
	double Triangle::getposx1() const
	{
		return posx1;
	}
	
	double Triangle::getposy1() const
	{
		return posy1;
	}
	
	double Triangle::getposx2() const
	{
		return posx2;
	}
	
	double Triangle::getposy2() const
	{
		return posy2;
	}
	
	double Triangle::getposx3() const
	{
		return posx3;
	}
	
	double Triangle::getposy3() const
	{	
		return posy3;
	}
	
	double Triangle::getperimeter() const
	{
		return (3*edge);
	}
	
	double Triangle::getarea() const
	{
		return (edge*edge*sqrt(3)/4);
	}
	
	/* ostream << rectangle : Print shape in file. ostream should be file (ofstream&) */ 
	ostream& operator <<(ostream& os, const Triangle& tri)
	{
		os<<"\t<polygon points=\""<<tri.getposx1()<<" "<<tri.getposy1()<<" "<<tri.getposx2()<<" "<<tri.getposy2()<<" "<<tri.getposx3()<<" "<<tri.getposy3()<<"\" fill=\""<<tri.getcolor()<<"\"/>"<<endl;
		return os;
	}
	
	//Prefix incrementing : Firstly increase value then return shape.
	Triangle Triangle::operator++()
	{
		posx1++;
		posy1++;
		posx2++;
		posy2++;
		posx3++;
		posy3++;
		return Triangle(edge, posx1, posy1, posx2, posy2, posx3, posy3);
	}
	//Postfix incrementing : Firstly increase value then return original shape. To return original shape, it is necessary to copy the this shape.
	Triangle Triangle::operator++(int)
	{
		Triangle temp(edge, posx1, posy1, posx2, posy2, posx3, posy3);
		posx1++;
		posy1++;
		posx2++;
		posy2++;
		posx3++;
		posy3++;
		return temp;
	}
	//Prefix decrementing : Firstly decrease value then return shape.
	Triangle Triangle::operator--()
	{
		if(posx1-1>= 0) posx1--;
		if(posy1-1>= 0) posy1--;
		if(posx2-1>= 0) posx2--;
		if(posy2-1>= 0) posy2--;
		if(posx3-1>= 0) posx3--;
		if(posy3-1>= 0) posy3--;
		return Triangle(edge, posx1, posy1, posx2, posy2, posx3, posy3);
	}
	//Postfix decrementing : Firstly decrease value then return original shape. To return original shape, it is necessary to copy the this shape.
	Triangle Triangle::operator--(int)
	{
		Triangle temp(edge, posx1, posy1, posx2, posy2, posx3, posy3);
		if(posx1-1>= 0) posx1--;
		if(posy1-1>= 0) posy1--;
		if(posx2-1>= 0) posx2--;
		if(posy2-1>= 0) posy2--;
		if(posx3-1>= 0) posx3--;
		if(posy3-1>= 0) posy3--;
		return temp;
	}
	
	/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
	Triangle Triangle::operator+(double x)
	{
		Triangle shape(edge,posx1,posy1,posx2,posy2,posx3,posy3);
		shape.edge += x;
		return shape;
	}
	Triangle Triangle::operator-(double x)
	{
		Triangle shape(edge,posx1,posy1,posx2,posy2,posx3,posy3);
		if(shape.edge-x >= 0) shape.edge -= x;
		return shape;
	}
	
	/*  Operators == , !=, >, >=, <, <= operators to compare two shapes with respect to their areas. return boolean value true or false. */
	bool operator==(const Triangle& tri1, const Triangle& tri2) 
	{ 
		if(tri1.getarea() == tri2.getarea()) return true;
		else return false; 
	}
	bool operator!=(const Triangle& tri1, const Triangle& tri2) 
	{ 
		if(tri1.getarea() != tri2.getarea()) return true;
		else return false; 
	}
	bool operator>(const Triangle& tri1, const Triangle& tri2) 
	{ 
		if(tri1.getarea() > tri2.getarea()) return true;
		else return false; 
	}
	bool operator>=(const Triangle& tri1, const Triangle& tri2) 
	{ 
		if(tri1.getarea() >= tri2.getarea()) return true;
		else return false; 
	}
	bool operator<(const Triangle& tri1, const Triangle& tri2) 
	{ 
		if(tri1.getarea() < tri2.getarea()) return true;
		else return false; 
	}
	bool operator<=(const Triangle& tri1, const Triangle& tri2) 
	{ 
		if(tri1.getarea() <= tri2.getarea()) return true;
		else return false; 
	}
	
	/* add new shape's area to static holder area member  . */
	void Triangle::add_total_area()
	{
		total_area += (edge*edge*sqrt(3)/4);	
	}
	/* add new shape's perimeter to static holder perimeter member  . */
	void Triangle::add_total_perimeter()
	{
		total_perimeter += (3*edge);
	}
	
	/* Total area getter static function */
	double Triangle::get_total_area()
	{
		return total_area;
	}
	/* Total perimeter getter static function */
	double Triangle::get_total_perimeter()
	{
		return total_perimeter;
	}
