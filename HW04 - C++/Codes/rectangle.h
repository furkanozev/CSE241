#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <string>
#include <fstream>
#include <iostream>
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
		double getperimeter() const;
		double getarea() const;
		
		/* Print inner shape in file take ostream and rectangle shape*/
		friend ostream& operator <<(ostream& os, const Rectangle& rec);
		
		/* for incrementing and decrementing the shape positions by 1.0 */
		Rectangle operator++();			//Prefix incrementing
		Rectangle operator++(int);		//Postfix incrementing
		Rectangle operator--();			//Prefix decrementing
		Rectangle operator--(int);		//Postfix decrementing
		
		/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
		Rectangle operator+(double x);
		Rectangle operator-(double x);
		
		/*  Operators == , !=, >, >=, <, <= operators to compare two shapes with respect to their areas. */
		friend bool operator==(const Rectangle& rec1, const Rectangle& rec2);
		friend bool operator!=(const Rectangle& rec1, const Rectangle& rec2);
		friend bool operator>(const Rectangle& rec1, const Rectangle& rec2);
		friend bool operator>=(const Rectangle& rec1, const Rectangle& rec2);
		friend bool operator<(const Rectangle& rec1, const Rectangle& rec2); 
		friend bool operator<=(const Rectangle& rec1, const Rectangle& rec2);
		
		/* add new shape's area to static holder area member  . */
		void add_total_area();
		/* add new shape's perimeter to static holder perimeter member  . */
		void add_total_perimeter();
		
		/* Total area getter static function */
		static double get_total_area();
		/* Total perimeter getter static function */
		static double get_total_perimeter();

		
		/* Used inline function */
		inline string getcolor() const 				//function returns a color of shape.
		{
			return color;
		}
		
	
	private:
		double width;
		double height;
		double posx;
		double posy;
		string color = "green";
		
		/* Static members */
		static double total_area;
		static double total_perimeter;
};

#endif
