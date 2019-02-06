#ifndef POLYLINE_H_
#define POLYLINE_H_
#include <iostream>
#include "polygon.h"

// Using mypolygon namespace 
using mypolygon::Polygon;

// create namespace of mypolyline
namespace mypolyline
{
	
	class Polyline
	{
		public:
	
			/* No need for destructor because no memmory to allocate*/
			Polyline( const Polyline& new_shape );		// Copy constructor
			Polyline& operator=( const Polyline& new_shape );		// Assigment operator
			
			Polyline();		// Default construcor
			/* A constructor that takes an vector of Point2D objects to represent the Polygon points */
			Polyline(vector<Polygon::Point2D> inners);
			/* A conversion constructor that converts from a 2D Point. */
			Polyline(Polygon::Point2D shape);
			/* Three conversion constructors that convert from other Rectangle, Triangle, and Circle objects. */
			Polyline(Rectangle shape);
			Polyline(Circle shape);
			Polyline(Triangle shape);
			
			/* Operator[] that returns a reference of Point2D object to the point at the given index.  */
			Polygon::Point2D& operator [](int index);
	    	const Polygon::Point2D& operator [](int index) const;
	    	
	    	/* Operator== that returns true if two Polylines are equal. Operator!= that returns true if two Polylines are not equal. */
	    	friend bool operator==(const Polyline& shape1, const Polyline& shape2);
			friend bool operator!=(const Polyline& shape1, const Polyline& shape2);
			
			/* Operator+ that adds two Polylines by concatenating the points and returns the result as a new object. */
			Polyline operator +(const Polyline& shape2);
			
			/* Operator<< for producing the SVG code. */
			friend ostream& operator <<(ostream& os,const Polyline& shape);
			
			/* getter size */
			int get_size() const;
			
		private:
			/* Polygon object used to work in class */
			Polygon object;
	};
}


#endif
