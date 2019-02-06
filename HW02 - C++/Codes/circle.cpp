#include <iostream>
#include "circle.h"	
	
using namespace std;	
	
	/* Composition used in this part. */
	// Constructor 1: No parameter
	Circle::Circle()
	{	}
	
	// Constructor 2: get width and height
	Circle::Circle(double radius_val)
					:radius(radius_val)
	{	}
	
	// Constructor 2: get width, height, posx, posy
	Circle::Circle(double radius_val, double centerx_val, double centery_val)
					:radius(radius_val), centerx(centerx_val), centery(centery_val)
	{	}
	
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
	
	
	// Draw inner shapes in file.
	void Circle::draw(ofstream& file)
	{
		file<<"\t<circle cx=\""<<centerx<<"\" cy=\""<<centery<<"\" r=\""<<radius<<"\" fill=\""<<color<<"\"/>\n";
	}
	// Draw Container shapes in file.
	void Circle::drawcontainer(ofstream& file)
	{
		file<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> <circle cx=\""<<centery<<"\" cy=\""<<centery<<"\" r=\""<<radius<<"\" fill=\"red\"/>\n";
	}
	