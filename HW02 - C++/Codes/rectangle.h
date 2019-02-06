#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <string>
#include <fstream>

using namespace std;

class Rectangle{
	
	public:
		/* Constructor: 
		1- No parameter and using set functions to set values.
		2- Parameters are width and height and using set functions to set posx, posy, others.
		3- All of the parameters have been entered. */
		Rectangle();
		Rectangle(double width_val, double height_val);
		Rectangle(double width_val, double height_val, double posx_val, double posy_val);
		
		/* Setter */
		void setwidth(double width_val);			// function sets a value to width.
		void setheight(double height_val);			// function sets a value to height.
		void setposx(double posx_val);				//function sets a value to positionx of shape.
		void setposy(double posy_val);				//function sets a value to positiony of shape.
		void setcolor(string color_val);			//function sets a value to color of shape.
		
		/* Getter functions is const*/
		double getwidth() const;					//function returns a width of shape.
		double getheight() const;					//function returns a height of shape.
		double getposx() const;						//function returns a positionx of shape.
		double getposy() const;						//function returns a positiony of shape.
		/* Used inline function */
		inline string getcolor() const 				//function returns a color of shape.
		{
			return color;
		}
		
		void drawcontainer(ofstream& file);			// Draw container shape function. I can't overload these functions because print container is different than print inner.
		void draw(ofstream& file);					// Draw inner shape function.
	
	private:
		double width;
		double height;
		double posx;
		double posy;
		string color = "green";
};

#endif
