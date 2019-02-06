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
		/* Used inline function */
		inline string getcolor() const 				//function returns a color of shape.
		{
			return color;
		}
		
		
		void draw(ofstream& file);					// Draw container shape function.
		void drawcontainer(ofstream& file);			// Draw inner shape function.
		
	private:
		double edge;
		double posx1;
		double posy1;
		double posx2;
		double posy2;
		double posx3;
		double posy3;
		string color = "green";
};

#endif
