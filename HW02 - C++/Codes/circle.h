#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <string>
#include <fstream>

using namespace std;

class Circle{
	
	public:
		/* Constructor: 
		1- No parameter and using set functions to set values.
		2- Parameter is radius and using set functions to set centerx, centery and others.
		3- All of the parameters have been entered. */
		Circle();
		Circle(double radius_val);
		Circle(double radius_val, double centerx_val, double centery_val);
		
		/* Setter */
		void setradius(double radius_val);				// function sets a value to radius.
		void setcenterx(double centerx_val);			// function sets a value to position x of center.
		void setcentery(double centery_val);			// function sets a value to position y of center.
		void setcolor(string color_val);				//function sets a value to color of shape.
		
		/* Getter functions is const */
		double getradius() const;						//function returns a radius of shape.
		double getcenterx() const;						//function returns a center x coordinate of shape.
		double getcentery() const;						//function returns a center y coordinate of shape.
		/* Used inline function */
		inline string getcolor() const 				//function returns a color of shape.
		{
			return color;
		}
		
		void draw(ofstream& file);						// Draw container shape function.
		void drawcontainer(ofstream& file);				// Draw inner shape function.
		
	private:
		double radius;
		double centerx;
		double centery;
		string color="green";
};

#endif
