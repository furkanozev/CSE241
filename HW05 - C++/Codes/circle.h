#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "shape.h"
#include <string>
#include <fstream>

using namespace std;
using namespace BaseShape;

namespace DerivedCirc
{
	class Circle : public Shape{
		
		public:
			/* Constructor: 
			1- No parameter and using set functions to set values.
			2- Parameter is radius and using set functions to set centerx, centery and others.
			3- All of the parameters have been entered. */
			Circle() noexcept;
			Circle(double radius_val) noexcept;
			Circle(double radius_val, double centerx_val, double centery_val, string color_ = "red") noexcept;
			
			/* Setter */
			void setradius(double radius_val) noexcept;				// function sets a value to radius.
			void setcenterx(double centerx_val) noexcept;			// function sets a value to position x of center.
			void setcentery(double centery_val) noexcept;			// function sets a value to position y of center.
			void setcolor(string color_val) noexcept;				//function sets a value to color of shape.
			
			/* Getter functions is const */
			double getradius() const noexcept;						//function returns a radius of shape.
			double getcenterx() const noexcept;						//function returns a center x coordinate of shape.
			double getcentery() const noexcept;						//function returns a center y coordinate of shape.
			virtual double perimeter() const noexcept override;
			virtual double area() const noexcept override;
			
			
			/* for incrementing and decrementing the shape positions by 1.0 */
			virtual Circle& operator++() noexcept override;		//Prefix incrementing
			virtual Circle& operator++(int) noexcept override;		//Postfix incrementing
			virtual Circle& operator--() throw(string) override;		//Prefix decrementing
			virtual Circle& operator--(int) throw(string) override;		//Postfix decrementing
			
			/* take a double as a parameter and they will add this double to the size of the shape to make the new shape */
			Circle operator+(double x) noexcept;
			Circle operator-(double x) throw(string);
			
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
			inline string getcolor() const noexcept 				//function returns a color of shape.
			{
				return color;
			}
			
		private:
			double radius;
			double centerx;
			double centery;
			string color;
			
			/* Static members */
			static double total_area;
			static double total_perimeter;
	};
}

#endif
