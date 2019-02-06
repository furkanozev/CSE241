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
	{	}
	
	// Constructor 2: get width, height, posx, posy
	Rectangle::Rectangle(double width_val, double height_val, double posx_val, double posy_val)
				:width(width_val), height(height_val), posx(posx_val), posy(posy_val)
	{	}
	
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
	
	
	
	/* Get the file from composed shape. And These functions is used to asist the composedshape. */
	// Draw inner shapes in file.
	void Rectangle::draw(ofstream& file)
	{
		file<<"<rect x=\""<<posx<<"\" y=\""<<posy<<"\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\""<<color<<"\" />\n";
	}
	// Draw Container shapes in file.
	void Rectangle::drawcontainer(ofstream& file)
	{
		file<<"<svg version=\"1.1\" baseProfile=\"full\" width=\""<<width<<"\" height=\""<<height<<"\" xmlns=\"http://www.w3.org/2000/svg\"> <rect width=\"100%\" height=\"100%\" fill=\"red\" />\n";
	}
	
	