#include <iostream>
#include "rectangle.h"

using namespace std;

namespace DerivedRect
{	
	/* Composition used in this part. */
	// Constructor 1: No parameter
	Rectangle::Rectangle() noexcept
					:Shape("rectangle")
	{	}
	
	// Constructor 2: get width and height
	Rectangle::Rectangle(double width_val, double height_val) noexcept
				:Shape("rectangle"), width(width_val), height(height_val)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();
		posx = 0;
		posy = 0;
		color = "red";
	}
	
	// Constructor 2: get width, height, posx, posy
	Rectangle::Rectangle(double width_val, double height_val, double posx_val, double posy_val, string color_) noexcept
				:Shape("rectangle"), width(width_val), height(height_val), posx(posx_val), posy(posy_val), color(color_)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();		
	}
	
	/* Static member initilaze */
	double Rectangle::total_area=0;
	double Rectangle::total_perimeter=0;
	
	/* Setter */
	void Rectangle::setwidth(double width_val) noexcept
	{
		width = width_val;	
	}
	
	void Rectangle::setheight(double height_val) noexcept
	{
		height = height_val;	
	}	
	
	void Rectangle::setposx(double posx_val) noexcept
	{
		posx = posx_val;	
	}
	
	void Rectangle::setposy(double posy_val) noexcept
	{
		posy = posy_val;	
	}
	
	void Rectangle::setcolor(string color_val) noexcept
	{ 
		color = color_val;
	}
	
	/* Getter */
	double Rectangle::getwidth() const noexcept
	{
		return width;
	}
	
	double Rectangle::getheight() const noexcept
	{
		return height;
	}
	
	 double Rectangle::getposx() const noexcept
	{
		return posx;
	}
	
	double Rectangle::getposy() const noexcept
	{
		return posy;
	}
	
	double Rectangle::perimeter() const noexcept
	{
		return (width+height)*2;
	}
	
	double Rectangle::area() const noexcept
	{
		return width*height;
	}
	
	//Prefix incrementing : Firstly increase value then return shape.
	Rectangle& Rectangle::operator++() noexcept
	{
		posx++;
		posy++;
		return (*this);
	}
	//Postfix incrementing : Firstly increase value then return original shape. To return original shape, it is necessary to copy the this shape.
	Rectangle& Rectangle::operator++(int) noexcept
	{
		Rectangle shape_temp(width,height,posx,posy,color);
		Rectangle* ptr_st = &shape_temp;
		posx++;
		posy++;
		return (*ptr_st);
	}
	//Prefix decrementing : Firstly decrease value then return shape.
	Rectangle& Rectangle::operator--() throw(string)
	{
		// position can not be negative.
		try
		{
			if(posx-1>= 0 && posy-1>= 0)
			{
				posx--;
				posy--;
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
	Rectangle& Rectangle::operator--(int) throw(string)
	{
		// position can not be negative.
		Rectangle shape_temp(width,height,posx,posy,color);
		Rectangle* ptr_st = &shape_temp;
		try
		{
			if(posx-1>= 0 && posy-1>= 0)
			{
				posx--;
				posy--;
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
	Rectangle Rectangle::operator+(double x) noexcept
	{
		Rectangle shape(width,height,posx,posy);
		shape.width += x;
		shape.height += x;
		return shape;
	}
	Rectangle Rectangle::operator-(double x) throw(string)
	{
		Rectangle shape(width,height,posx,posy);
		try
		{
			if(shape.width-x >= 0 && shape.height-x >= 0)
			{
				shape.width -= x;
				shape.height -= x;
			}
			else throw "Width or Height can not be negative.";
		}
		catch(string s)
		{
			cerr<<endl<<s<<endl;
		}
		return shape;
	}
	
	void Rectangle::print(ostream& os) noexcept
	{
		
		os<<"\n<rect x=\""<<posx<<"\" y=\""<<posy<<"\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\""<<color<<"\" />\n";
	}
	
	/* add new shape's area to static holder area member  . */
	void Rectangle::add_total_area() noexcept
	{
		total_area += (width*height);	
	}
	/* add new shape's perimeter to static holder perimeter member  . */
	void Rectangle::add_total_perimeter() noexcept
	{
		total_perimeter += (2*(width+height));
	}
	
	/* Total area getter static function */
	double Rectangle::get_total_area() noexcept
	{
		return total_area;
	}
	/* Total perimeter getter static function */
	double Rectangle::get_total_perimeter() noexcept
	{
		return total_perimeter;
	}
}
