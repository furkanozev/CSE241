#ifndef POLYGON_H_
#define POLYGON_H_
#include "shape.h"
#include <iostream>

using namespace std;
using namespace BaseShape;

namespace DerivedPolygon
{
	class Polygon : public Shape
	{
		public:
	
			// Point2D class
			class Point2D
			{
				public:
					Point2D() noexcept;		// Default constructor
					Point2D(double a, double b) noexcept;		// conversion constructor
					// getters
					double getx() const noexcept;
					double gety() const noexcept;
					// setters
					void setx(double point) noexcept;
					void sety(double point) noexcept;
					
				private:
					// coordinate of x and y
					double x;
					double y;
			};
			
			Polygon() noexcept;
			Polygon(string name) noexcept;
			
			virtual double area() const = 0;
			virtual double perimeter() const = 0;
			
			virtual Polygon& operator++() override = 0;
			virtual Polygon& operator++(int) override = 0;
			virtual Polygon& operator--() override = 0;
			virtual Polygon& operator--(int) override = 0;					
					
			virtual void print(ostream& os) = 0;
	};
}

#endif
