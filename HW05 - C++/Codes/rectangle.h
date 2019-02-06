#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "shape.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
using namespace BaseShape;

namespace DerivedRect
{
	class Rectangle : public Shape{
		
		public:
			/* Constructor: 
			1- No parameter and using set functions to set values.
			2- Parameters are width and height and using set functions to set posx, posy, others.
			3- All of the parameters have been entered. */
			Rectangle() noexcept;
			Rectangle(double width_val, double height_val) noexcept;
			Rectangle(double width_val, double height_val, double posx_val, double posy_val, string color_ = "red") noexcept;
			
			/* Setter */
			void setwidth(double width_val) noexcept;			// function sets a value to width.
			void setheight(double height_val) noexcept;			// function sets a value to height.
			void setposx(double posx_val) noexcept;				//function sets a value to positionx of shape.
			void setposy(double posy_val) noexcept;				//function sets a value to positiony of shape.
			void setcolor(string color_val) noexcept;			//function sets a value to color of shape.
			
			/* Getter functions is const*/
			double getwidth() const noexcept;					//function returns a width of shape.
			double getheight() const noexcept;					//function returns a height of shape.
			double getposx() const noexcept;						//function returns a positionx of shape.
			double getposy() const noexcept;						//function returns a positiony of shape.
			virtual double perimeter() const noexcept override;
			virtual double area() const noexcept override;
			
			/* for incrementing and decrementing the shape positions by 1.0 */
			virtual Rectangle& operator++() noexcept override;			//Prefix incrementing
			virtual Rectangle& operator++(int) noexcept override;		//Postfix incrementing
			virtual Rectangle& operator--() throw(string) override;			//Prefix decrementing
			virtual Rectangle& operator--(int) throw(string) override;		//Postfix decrementing
			
			/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
			Rectangle operator+(double x) noexcept;
			Rectangle operator-(double x) throw(string);
			
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
			double width;
			double height;
			double posx;
			double posy;
			string color;
			
			/* Static members */
			static double total_area;
			static double total_perimeter;
	};
}

#endif
