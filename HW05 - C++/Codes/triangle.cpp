#include <iostream>
#include "triangle.h"	

using namespace std;

namespace DerivedTri
{
	/* Composition used in this part. */
	// Constructor 1: No parameter
	Triangle::Triangle() noexcept
					:Shape("triangle")
	{	}
	
	// Constructor 2: get edge
	Triangle::Triangle(double edge_val) noexcept
						:Shape("triangle"), edge(edge_val)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();	
		posx1 = edge / 2;
		posy1 = 0;
		posx2 = 0;
		posy2 = (edge / 2) * sqrt(3);
		posx3 = edge;
		posy3 = (edge / 2) * sqrt(3);
		color = "red";
	}
	
	// Constructor 2: get edge and all point of triangle.
	Triangle::Triangle(double edge_val, double posx1_val, double posy1_val, double posx2_val, double posy2_val, double posx3_val, double posy3_val, string color_) noexcept
						:Shape("triangle"), edge(edge_val), posx1(posx1_val), posy1(posy1_val), posx2(posx2_val), posy2(posy2_val), posx3(posx3_val), posy3(posy3_val), color(color_)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();	
	}
	
	/* Static member initilaze */
	double Triangle::total_area=0;
	double Triangle::total_perimeter=0;
	
	/* Setter */
	void Triangle::setedge(double edge_val) noexcept
	{
		edge = edge_val;
	}
	
	void Triangle::setposx1(double posx_val) noexcept
	{
		posx1 = posx_val;
	}
	
	void Triangle::setposy1(double posy_val) noexcept
	{
		posy1 = posy_val;
	}
	
	void Triangle::setposx2(double posx_val) noexcept
	{
		posx2 = posx_val;
	}
	
	void Triangle::setposy2(double posy_val) noexcept
	{
		posy2 = posy_val;
	}
	
	void Triangle::setposx3(double posx_val) noexcept
	{
		posx3 = posx_val;
	}
	
	void Triangle::setposy3(double posy_val) noexcept
	{
		posy3 = posy_val;
	}
	
	void Triangle::setcolor(string color_val) noexcept
	{
		color = color_val;
	}
	
	/* Getter */
	double Triangle::getedge()  const noexcept
	{
		return edge;
	}
	
	double Triangle::getposx1() const noexcept
	{
		return posx1;
	}
	
	double Triangle::getposy1() const noexcept
	{
		return posy1;
	}
	
	double Triangle::getposx2() const noexcept
	{
		return posx2;
	}
	
	double Triangle::getposy2() const noexcept
	{ 
		return posy2;
	}
	
	double Triangle::getposx3() const noexcept
	{
		return posx3;
	}
	
	double Triangle::getposy3() const noexcept
	{	
		return posy3;
	}
	
	double Triangle::perimeter() const noexcept
	{
		return (3*edge);
	}
	
	double Triangle::area() const noexcept
	{
		return (pow(edge,2)*sqrt(3)/4);
	}
	
	//Prefix incrementing : Firstly increase value then return shape.
	Triangle& Triangle::operator++() noexcept
	{
		posx1++;
		posy1++;
		posx2++;
		posy2++;
		posx3++;
		posy3++;
		return (*this);
	}
	//Postfix incrementing : Firstly increase value then return original shape. To return original shape, it is necessary to copy the this shape.
	Triangle& Triangle::operator++(int) noexcept
	{
		Triangle shape_temp(edge,posx1,posy1,posx2,posy2,posx3,posy3,color);
		Triangle* ptr_st = &shape_temp;
		posx1++;
		posy1++;
		posx2++;
		posy2++;
		posx3++;
		posy3++;
		return (*ptr_st);
	}
	//Prefix decrementing : Firstly decrease value then return shape.
	Triangle& Triangle::operator--() throw(string)
	{
		try
		{
			if(posx1-1>= 0 && posy1-1>= 0 && posx2-1>= 0 && posy2-1>= 0 && posx3-1>= 0 && posy3-1>= 0)
			{
				posx1--;
				posy1--;
				posx2--;
				posy2--;
				posx3--;
				posy3--;
			}
			else throw "Coordinate can not be negative.";
		}
		catch(string s)
		{
			cerr<<endl<<s<<endl;
		}
		return (*this);
	}
	//Postfix decrementing : Firstly decrease value then return original shape. To return original shape, it is necessary to copy the this shape.
	Triangle& Triangle::operator--(int) throw(string)
	{
		Triangle shape_temp(edge,posx1,posy1,posx2,posy2,posx3,posy3,color);
		Triangle* ptr_st = &shape_temp;
		try
		{
			if(posx1-1>= 0 && posy1-1>= 0 && posx2-1>= 0 && posy2-1>= 0 && posx3-1>= 0 && posy3-1>= 0)
			{
				posx1--;
				posy1--;
				posx2--;
				posy2--;
				posx3--;
				posy3--;
			}
			else throw "Coordinate can not be negative.";
		}
		catch(string s)
		{
			cerr<<endl<<s<<endl;
		}
		return (*ptr_st);
	}
	
	/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
	Triangle Triangle::operator+(double x) noexcept
	{
		Triangle shape(edge,posx1,posy1,posx2,posy2,posx3,posy3);
		shape.edge += x;
		return shape;
	}
	Triangle Triangle::operator-(double x) throw(string)
	{
		Triangle shape(edge,posx1,posy1,posx2,posy2,posx3,posy3);
		try
		{
			if(shape.edge-x >= 0) shape.edge -= x;
			else throw "Edge can not be negative.";
		}
		catch(string s)
		{
			cerr<<endl<<s<<endl;
		}
		return shape;
	}
	
	void Triangle::print(ostream& os) noexcept
	{
		
		os<<"\n<polygon points=\""<<posx1<<" "<<posy1<<" "<<posx2<<" "<<posy2<<" "<<posx3<<" "<<posy3<<"\" fill=\""<<color<<"\"/>"<<endl;
	}
	
	/* add new shape's area to static holder area member  . */
	void Triangle::add_total_area() noexcept
	{
		total_area += (edge*edge*sqrt(3)/4);	
	}
	/* add new shape's perimeter to static holder perimeter member  . */
	void Triangle::add_total_perimeter() noexcept
	{
		total_perimeter += (3*edge);
	}
	
	/* Total area getter static function */
	double Triangle::get_total_area() noexcept
	{
		return total_area;
	}
	/* Total perimeter getter static function */
	double Triangle::get_total_perimeter() noexcept
	{
		return total_perimeter;
	}
	
}
