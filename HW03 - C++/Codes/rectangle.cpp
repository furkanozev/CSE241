#include <iostream>
#include "rectangle.h"

using namespace std;

	
	/* Composition used in this part. */
	// Constructor 1: No parameter
	Rectangle::Rectangle()
	{	}
	
	// Constructor 2: get width and height
	Rectangle::Rectangle(double width_val=0, double height_val=0)
				:width(width_val), height(height_val)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();
	}
	
	// Constructor 2: get width, height, posx, posy
	Rectangle::Rectangle(double width_val, double height_val, double posx_val, double posy_val)
				:width(width_val), height(height_val), posx(posx_val), posy(posy_val)
	{
		/* Add area and perimeter of new's shape */
		add_total_area();
		add_total_perimeter();		
	}
	
	/* Static member initilaze */
	double Rectangle::total_area=0;
	double Rectangle::total_perimeter=0;
	
	/* Setter */
	void Rectangle::setwidth(double width_val)
	{
		width = width_val;	
	}
	
	void Rectangle::setheight(double height_val)
	{
		height = height_val;	
	}	
	
	void Rectangle::setposx(double posx_val)
	{
		posx = posx_val;	
	}
	
	void Rectangle::setposy(double posy_val)
	{
		posy = posy_val;	
	}
	
	void Rectangle::setcolor(string color_val)
	{
		color = color_val;
	}
	
	/* Getter */
	double Rectangle::getwidth() const
	{
		return width;
	}
	
	double Rectangle::getheight() const
	{
		return height;
	}
	
	 double Rectangle::getposx() const
	{
		return posx;
	}
	
	double Rectangle::getposy() const
	{
		return posy;
	}
	
	double Rectangle::getperimeter() const
	{
		return (width+height)*2;
	}
	
	double Rectangle::getarea() const
	{
		return width*height;
	}
	
	/* ostream << rectangle : Print shape in file. ostream should be file (ofstream&) */ 
	ostream& operator <<(ostream& os, const Rectangle& rec)  
	{  

	    os<<"<rect x=\""<<rec.getposx()<<"\" y=\""<<rec.getposy()<<"\" width=\""<<rec.getwidth()<<"\" height=\""<<rec.getheight()<<"\" fill=\""<<rec.getcolor()<<"\" />\n";
	    return os;
	}  
	
	//Prefix incrementing : Firstly increase value then return shape.
	Rectangle Rectangle::operator++()
	{
		posx++;
		posy++;
		return Rectangle(width,height,posx,posy);
	}
	//Postfix incrementing : Firstly increase value then return original shape. To return original shape, it is necessary to copy the this shape.
	Rectangle Rectangle::operator++(int)
	{
		Rectangle temp(width,height,posx,posy);
		posx++;
		posy++;
		return temp;
	}
	//Prefix decrementing : Firstly decrease value then return shape.
	Rectangle Rectangle::operator--()
	{
		// position can not be negative.
		if(posx-1>= 0) posx--;
		if(posy-1>= 0) posy--;
		return Rectangle(width,height,posx,posy);
	}
	//Postfix decrementing : Firstly decrease value then return original shape. To return original shape, it is necessary to copy the this shape.
	Rectangle Rectangle::operator--(int)
	{
		// position can not be negative.
		Rectangle temp(width,height,posx,posy);
		if(posx-1>= 0) posx--;
		if(posy-1>= 0) posy--;
		return temp;
	}
	
	/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
	Rectangle Rectangle::operator+(double x)
	{
		Rectangle shape(width,height,posx,posy);
		shape.width += x;
		shape.height += x;
		return shape;
	}
	Rectangle Rectangle::operator-(double x)
	{
		Rectangle shape(width,height,posx,posy);
		if(shape.width-x >= 0) shape.width -= x;
		if(shape.height-x >= 0) shape.height -= x;
		return shape;
	}
	
	/*  Operators == , !=, >, >=, <, <= operators to compare two shapes with respect to their areas. return boolean value true or false. */
	bool operator==(const Rectangle& rec1, const Rectangle& rec2) 
	{ 
		if(rec1.getarea() == rec2.getarea()) return true;
		else return false; 
	}
	bool operator!=(const Rectangle& rec1, const Rectangle& rec2) 
	{ 
		if(rec1.getarea() != rec2.getarea()) return true;
		else return false; 
	}
	bool operator>(const Rectangle& rec1, const Rectangle& rec2) 
	{ 
		if(rec1.getarea() > rec2.getarea()) return true;
		else return false; 
	}
	bool operator>=(const Rectangle& rec1, const Rectangle& rec2) 
	{ 
		if(rec1.getarea() >= rec2.getarea()) return true;
		else return false; 
	}
	bool operator<(const Rectangle& rec1, const Rectangle& rec2) 
	{ 
		if(rec1.getarea() < rec2.getarea()) return true;
		else return false; 
	}
	bool operator<=(const Rectangle& rec1, const Rectangle& rec2) 
	{ 
		if(rec1.getarea() <= rec2.getarea()) return true;
		else return false; 
	}
	
	/* add new shape's area to static holder area member  . */
	void Rectangle::add_total_area()
	{
		total_area += (width*height);	
	}
	/* add new shape's perimeter to static holder perimeter member  . */
	void Rectangle::add_total_perimeter()
	{
		total_perimeter += (2*(width+height));
	}
	
	/* Total area getter static function */
	double Rectangle::get_total_area()
	{
		return total_area;
	}
	/* Total perimeter getter static function */
	double Rectangle::get_total_perimeter()
	{
		return total_perimeter;
	}
	
