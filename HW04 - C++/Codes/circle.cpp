#include <iostream>
#include "circle.h"
# define M_PI		3.14159265358979323846	
	
using namespace std;
	
	
	/* Composition used in this part. */
	// Constructor 1: No parameter
	Circle::Circle()
	{	}
	
	// Constructor 2: get width and height
	Circle::Circle(double radius_val)
					:radius(radius_val)
	{
		centerx = radius;
		centery = radius;
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();
	}
	
	// Constructor 2: get width, height, posx, posy
	Circle::Circle(double radius_val, double centerx_val, double centery_val)
					:radius(radius_val), centerx(centerx_val), centery(centery_val)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();
	}
	
	/* Static member initilaze */
	double Circle::total_area=0;
	double Circle::total_perimeter=0;
	
	/* Setter */
	void Circle::setradius(double radius_val)
	{
		radius = radius_val;
	}
	
	void Circle::setcenterx(double centerx_val)
	{
		centerx = centerx_val;
	}
	
	void Circle::setcentery(double centery_val)
	{
		centery = centery_val;
	}
	
	void Circle::setcolor(string color_val)
	{
		color = color_val;
	}
	
	/* Getter */
	double Circle::getradius()  const
	{
		return radius;
	}
	
	double Circle::getcenterx()  const
	{
		return centerx;
	}
	
	double Circle::getcentery()  const
	{
		return centery;
	}
	
	double Circle::getperimeter() const
	{
		return (2*M_PI*radius);
	}
	
	double Circle::getarea() const
	{
		return (M_PI*radius*radius);
	}
	
	/* ostream << rectangle : Print shape in file. ostream should be file (ofstream&) */ 
	ostream& operator <<(ostream& os, const Circle& cir)
	{
		os<<"\t<circle cx=\""<<cir.getcenterx()<<"\" cy=\""<<cir.getcentery()<<"\" r=\""<<cir.getradius()<<"\" fill=\""<<cir.getcolor()<<"\"/>\n";
		return os;
	}
	
	//Prefix incrementing : Firstly increase value then return shape.
	Circle Circle::operator++()
	{
		centerx++;
		centery++;
		return Circle(radius, centerx, centery);
	}
	//Postfix incrementing : Firstly increase value then return original shape. To return original shape, it is necessary to copy the this shape.
	Circle Circle::operator++(int)
	{
		Circle temp(radius, centerx, centery);
		centerx++;
		centery++;
		return temp;
	}
	//Prefix decrementing : Firstly decrease value then return shape.
	Circle Circle::operator--()
	{
		if(centerx-1>= 0) centerx--;
		if(centery-1>= 0) centery--;
		return Circle(radius, centerx, centery);
	}
	//Postfix decrementing : Firstly decrease value then return original shape. To return original shape, it is necessary to copy the this shape.
	Circle Circle::operator--(int)
	{
		Circle temp(radius, centerx, centery);
		if(centerx-1>= 0) centerx--;
		if(centery-1>= 0) centery--;
		return temp;
	}
	
	/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
	Circle Circle::operator+(double x)
	{
		Circle shape(radius,centerx,centery);
		shape.radius += x;
		return shape;
	}
	Circle Circle::operator-(double x)
	{
		Circle shape(radius,centerx,centery);
		if(shape.radius-x >= 0) shape.radius -= x;
		return shape;
	}
	
	/*  Operators == , !=, >, >=, <, <= operators to compare two shapes with respect to their areas. return boolean value true or false. */
	bool operator==(const Circle& cir1, const Circle& cir2) 
	{ 
		if(cir1.getarea() == cir2.getarea()) return true;
		else return false; 
	}
	bool operator!=(const Circle& cir1, const Circle& cir2) 
	{ 
		if(cir1.getarea() != cir2.getarea()) return true;
		else return false; 
	}
	bool operator>(const Circle& cir1, const Circle& cir2) 
	{ 
		if(cir1.getarea() > cir2.getarea()) return true;
		else return false; 
	}
	bool operator>=(const Circle& cir1, const Circle& cir2) 
	{ 
		if(cir1.getarea() >= cir2.getarea()) return true;
		else return false; 
	}
	bool operator<(const Circle& cir1, const Circle& cir2) 
	{ 
		if(cir1.getarea() < cir2.getarea()) return true;
		else return false; 
	}
	bool operator<=(const Circle& cir1, const Circle& cir2) 
	{ 
		if(cir1.getarea() <= cir2.getarea()) return true;
		else return false; 
	}
	
	/* add new shape's area to static holder area member  . */
	void Circle::add_total_area()
	{
		total_area += (M_PI*radius*radius);	
	}
	/* add new shape's perimeter to static holder perimeter member  . */
	void Circle::add_total_perimeter()
	{
		total_perimeter += (2*M_PI*radius);
	}
	
	/* Total area getter static function */
	double Circle::get_total_area()
	{
		return total_area;
	}
	/* Total perimeter getter static function */
	double Circle::get_total_perimeter()
	{
		return total_perimeter;
	}
	
