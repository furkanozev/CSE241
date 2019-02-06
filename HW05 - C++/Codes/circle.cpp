#include <iostream>
#include "circle.h"
# define M_PI		3.14159265358979323846	
	
using namespace std;
	
namespace DerivedCirc
{	
	/* Composition used in this part. */
	// Constructor 1: No parameter
	Circle::Circle() noexcept
				:Shape("circle")
	{	}
	
	// Constructor 2: get width and height
	Circle::Circle(double radius_val) noexcept
					:Shape("circle"), radius(radius_val)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();
		centerx = radius;
		centery = radius;
		color = "red";
	}
	
	// Constructor 2: get width, height, posx, posy
	Circle::Circle(double radius_val, double centerx_val, double centery_val, string color_) noexcept
					:Shape("circle"), radius(radius_val), centerx(centerx_val), centery(centery_val), color(color_)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();
	}
	
	/* Static member initilaze */
	double Circle::total_area=0;
	double Circle::total_perimeter=0;
	
	/* Setter */
	void Circle::setradius(double radius_val) noexcept
	{
		radius = radius_val;
	}
	
	void Circle::setcenterx(double centerx_val) noexcept
	{
		centerx = centerx_val;
	}
	
	void Circle::setcentery(double centery_val) noexcept
	{
		centery = centery_val;
	}
	
	void Circle::setcolor(string color_val) noexcept
	{
		color = color_val;
	}
	
	/* Getter */
	double Circle::getradius()  const noexcept
	{
		return radius;
	}
	
	double Circle::getcenterx()  const noexcept
	{
		return centerx;
	}
	
	double Circle::getcentery()  const noexcept
	{
		return centery;
	}
	
	double Circle::perimeter() const noexcept
	{
		return (2*M_PI*radius);
	}
	
	double Circle::area() const noexcept
	{
		return (M_PI*radius*radius);
	}
	
	//Prefix incrementing : Firstly increase value then return shape.
	Circle& Circle::operator++() noexcept
	{
		centerx++;
		centery++;
		return (*this);
	}
	//Postfix incrementing : Firstly increase value then return original shape. To return original shape, it is necessary to copy the this shape.
	Circle& Circle::operator++(int) noexcept
	{
		Circle shape_temp(radius,centerx,centery,color);
		Circle* ptr_st = &shape_temp;
		centerx++;
		centery++;
		return (*ptr_st);
	}
	//Prefix decrementing : Firstly decrease value then return shape.
	Circle& Circle::operator--() throw(string)
	{
		try
		{
			if(centerx-1>= 0 && centery-1>= 0)
			{
			centerx--;
			centery--;
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
	Circle& Circle::operator--(int) throw(string)
	{
		Circle shape_temp(radius,centerx,centery,color);
		Circle* ptr_st = &shape_temp;
		try
		{
			if(centerx-1>= 0 && centery-1>= 0)
			{
			centerx--;
			centery--;
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
	Circle Circle::operator+(double x) noexcept
	{
		Circle shape(radius,centerx,centery);
		shape.radius += x;
		return shape;
	}
	Circle Circle::operator-(double x) throw(string)
	{
		Circle shape(radius,centerx,centery);
		try
		{
			if(shape.radius-x >= 0) shape.radius -= x;
			else throw "Radius can not be negative.";
		}
		catch(string s)
		{
			cerr<<endl<<s<<endl;
		}
		return shape;
	}
	
	void Circle::print(ostream& os) noexcept
	{
		
		os<<"\n<circle cx=\""<<centerx<<"\" cy=\""<<centery<<"\" r=\""<<radius<<"\" fill=\""<<color<<"\"/>\n";

	}
	
	/* add new shape's area to static holder area member  . */
	void Circle::add_total_area() noexcept
	{
		total_area += (M_PI*radius*radius);	
	}
	/* add new shape's perimeter to static holder perimeter member  . */
	void Circle::add_total_perimeter() noexcept
	{
		total_perimeter += (2*M_PI*radius);
	}
	
	/* Total area getter static function */
	double Circle::get_total_area() noexcept
	{
		return total_area;
	}
	/* Total perimeter getter static function */
	double Circle::get_total_perimeter() noexcept
	{
		return total_perimeter;
	}
}
