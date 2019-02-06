#ifndef POLYGON_H_
#define POLYGON_H_
#include <iostream>
#include <vector>
#include <new>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include <cmath>
#include <fstream>
#include <string>

#define PI 3.14159265

using namespace std;
// create namespace of mypolygon
namespace mypolygon
{
	
	class Polygon{
		
		public:
	
			// Point2D class
			class Point2D{
				public:
					Point2D();		// Default constructor
					Point2D(double a, double b);		// conversion constructor
					// getters
					double getx() const;
					double gety() const;
					// setters
					void setx(double point);
					void sety(double point);
					
				private:
					// coordinate of x and y
					double x;
					double y;
			};
			
			// Big three
			~Polygon();			// Destructor
			Polygon( const Polygon& new_shape );		// Copy constructor
			Polygon& operator=( const Polygon& new_shape );		// Assigment operator
			
			Polygon();		// Default constructor
			/* A constructor that takes an vector of Point2D objects to represent the Polygon points */
			Polygon(vector<Point2D> inners);
			/* A conversion constructor that converts from a 2D Point. */
			Polygon(Point2D shape);
			/* Three conversion constructors that convert from other Rectangle, Triangle, and Circle objects. */
			Polygon(Rectangle shape);
			Polygon(Circle shape);
			Polygon(Triangle shape);
			
			/* Operator[] that returns a reference of Point2D object to the point at the given index.  */
			Point2D& operator [](int index);		// LEFT SIDE
	    	const Point2D& operator [](int index) const;			// RIGHT SIDE
	    	
	    	/* Operator== that returns true if two Polygons are equal. Operator!= that returns true if two Polygons are not equal. */
	    	friend bool operator==(const Polygon& shape1, const Polygon& shape2);
			friend bool operator!=(const Polygon& shape1, const Polygon& shape2);
			
			/* Operator+ that adds two Polygons by concatenating the points and returns the result as a new object. */
			Polygon operator +(const Polygon& shape2);
			
			/* Operator<< for producing the SVG code. */
			friend ostream& operator <<(ostream& os, const Polygon& shape);
			
			/* getter and setter */
			int get_size() const;
			void set_size(int number);
			
		private:
			Point2D* shapes;
			int size;
	};
}

#endif
