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
	{	}
	
	// Constructor 2: get edge and all point of triangle.
	Triangle::Triangle(double edge_val, double posx1_val, double posy1_val, double posx2_val, double posy2_val, double posx3_val, double posy3_val)
						:edge(edge_val), posx1(posx1_val), posy1(posy1_val), posx2(posx2_val), posy2(posy2_val), posx3(posx3_val), posy3(posy3_val)
	{	}
	
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
	
	
	/* Get the file from composed shape. And These functions is used to asist the composedshape. */
	// Draw inner shapes in file.
	void Triangle::draw(ofstream& file)
	{
		file<<"\t<polygon points=\""<<posx1<<" "<<posy1<<" "<<posx2<<" "<<posy2<<" "<<posx3<<" "<<posy3<<"\" fill=\""<<color<<"\"/>"<<endl;
	}
	
	// Draw Container shapes in file.
	void Triangle::drawcontainer(ofstream& file)
	{
		file<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> <polygon points=\""<<posx1<<" "<<posy1<<" "<<posx2<<" "<<posy2<<" "<<posx3<<" "<<posy3<<" "<<"\" fill=\"red\"/>\n";
	}
