#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Triangle{
	
	public:
		/* Constructor: 
		1- No parameter and using set functions to set values.
		2- Parameter is edge and using set functions to set all point of triangle.
		3- All of the parameters have been entered. */
		Triangle();
		Triangle(double edge_val);
		Triangle(double edge_val, double posx1_val, double posy1_val, double posx2_val, double posy2_val, double posx3_val, double posy3_val);
		
		/* Setter */
		void setedge(double edge_val);				// function sets a value to edge.
		void setposx1(double posx_val);				// function sets a value to coordinate x of point1.
		void setposy1(double posy_val);				// function sets a value to coordinate y of point1.		
		void setposx2(double posx_val);				// function sets a value to coordinate x of point2.
		void setposy2(double posy_val);				// function sets a value to coordinate y of point2.
		void setposx3(double posx_val);				// function sets a value to coordinate x of point3.
		void setposy3(double posy_val);				// function sets a value to coordinate y of point3.
		void setcolor(string color_val);			//function sets a value to color of shape.
		
		/* Getter functions is const */
		double getedge() const;						//function returns a edge of shape.
		double getposx1() const;					//function returns a coordinate x of point1.
		double getposy1() const;					//function returns a coordinate y of point1.
		double getposx2() const;					//function returns a coordinate x of point2.
		double getposy2() const;					//function returns a coordinate y of point2.
		double getposx3() const;					//function returns a coordinate x of point3.
		double getposy3() const;					//function returns a coordinate y of point3.
		double getperimeter() const;
		double getarea() const;
		
		/* Print inner shape in file take ostream and rectangle shape*/
		friend ostream& operator <<(ostream& os, const Triangle& tri);
				
		/* for incrementing and decrementing the shape positions by 1.0 */
		Triangle operator++();			//Prefix incrementing
		Triangle operator++(int);		//Postfix incrementing
		Triangle operator--();			//Prefix decrementing
		Triangle operator--(int);		//Postfix decrementing
		
		/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
		Triangle operator+(double x);
		Triangle operator-(double x);
		
		/*  Operators == , !=, >, >=, <, <= operators to compare two shapes with respect to their areas. */
		friend bool operator==(const Triangle& tri1, const Triangle& tri2);
		friend bool operator!=(const Triangle& tri1, const Triangle& tri2);
		friend bool operator>(const Triangle& tri1, const Triangle& tri2);
		friend bool operator>=(const Triangle& tri1, const Triangle& tri2);
		friend bool operator<(const Triangle& tri1, const Triangle& tri2); 
		friend bool operator<=(const Triangle& tri1, const Triangle& tri2);
		
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
		double edge;
		double posx1;
		double posy1;
		double posx2;
		double posy2;
		double posx3;
		double posy3;
		string color = "green";
		
		/* Static members */
		static double total_area;
		static double total_perimeter;
};

#endif
