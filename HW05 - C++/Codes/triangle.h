#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "shape.h"
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
using namespace BaseShape;

namespace DerivedTri
{
	class Triangle : public Shape{
		
		public:
			/* Constructor: 
			1- No parameter and using set functions to set values.
			2- Parameter is edge and using set functions to set all point of triangle.
			3- All of the parameters have been entered. */
			Triangle() noexcept;
			Triangle(double edge_val) noexcept;
			Triangle(double edge_val, double posx1_val, double posy1_val, double posx2_val, double posy2_val, double posx3_val, double posy3_val, string color_ = "red") noexcept;
			
			/* Setter */
			void setedge(double edge_val) noexcept;				// function sets a value to edge.
			void setposx1(double posx_val) noexcept;				// function sets a value to coordinate x of point1.
			void setposy1(double posy_val) noexcept;				// function sets a value to coordinate y of point1.		
			void setposx2(double posx_val) noexcept;				// function sets a value to coordinate x of point2.
			void setposy2(double posy_val) noexcept;				// function sets a value to coordinate y of point2.
			void setposx3(double posx_val) noexcept;				// function sets a value to coordinate x of point3.
			void setposy3(double posy_val) noexcept;				// function sets a value to coordinate y of point3.
			void setcolor(string color_val) noexcept;			//function sets a value to color of shape.
			
			/* Getter functions is const */
			double getedge() const noexcept;						//function returns a edge of shape.
			double getposx1() const noexcept;					//function returns a coordinate x of point1.
			double getposy1() const noexcept;					//function returns a coordinate y of point1.
			double getposx2() const noexcept;					//function returns a coordinate x of point2.
			double getposy2() const noexcept;					//function returns a coordinate y of point2.
			double getposx3() const noexcept;					//function returns a coordinate x of point3.
			double getposy3() const noexcept;					//function returns a coordinate y of point3.
			virtual double perimeter() const noexcept override;
			virtual double area() const noexcept override;
					
			/* for incrementing and decrementing the shape positions by 1.0 */
			virtual Triangle& operator++() noexcept override;			//Prefix incrementing
			virtual Triangle& operator++(int) noexcept override;		//Postfix incrementing
			virtual Triangle& operator--() throw(string) override;			//Prefix decrementing
			virtual Triangle& operator--(int) throw(string) override;		//Postfix decrementing
			
			/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
			Triangle operator+(double x) noexcept;
			Triangle operator-(double x) throw(string);
			
			virtual void print(ostream& os) noexcept override;
			
			/* add new shape's area to static holder area member  . */
			void add_total_area() noexcept;
			/* add new shape's perimeter to static holder perimeter member  . */
			void add_total_perimeter() noexcept;
			
			/* Total area getter static function */
			static double get_total_area() noexcept;
			/* Total perimeter getter static function */
			static double get_total_perimeter() noexcept;
			
			/* Used inline function */
			inline string getcolor() const noexcept				//function returns a color of shape.
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
}
#endif
