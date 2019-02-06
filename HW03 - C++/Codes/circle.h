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
		double getperimeter() const;
		double getarea() const;
		
		
		/* Print inner shape in file take ostream and rectangle shape*/
		friend ostream& operator <<(ostream& os, const Circle& cir);
		
		/* for incrementing and decrementing the shape positions by 1.0 */
		Circle operator++();		//Prefix incrementing
		Circle operator++(int);		//Postfix incrementing
		Circle operator--();		//Prefix decrementing
		Circle operator--(int);		//Postfix decrementing
		
		/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
		Circle operator+(double x);
		Circle operator-(double x);
		
		/*  Operators == , !=, >, >=, <, <= operators to compare two shapes with respect to their areas. */
		friend bool operator==(const Circle& cir1, const Circle& cir2);
		friend bool operator!=(const Circle& cir1, const Circle& cir2);
		friend bool operator>(const Circle& cir1, const Circle& cir2);
		friend bool operator>=(const Circle& cir1, const Circle& cir2);
		friend bool operator<(const Circle& cir1, const Circle& cir2); 
		friend bool operator<=(const Circle& cir1, const Circle& cir2);
		
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
		double radius;
		double centerx;
		double centery;
		string color="green";
		
		/* Static members */
		static double total_area;
		static double total_perimeter;
};

#endif
