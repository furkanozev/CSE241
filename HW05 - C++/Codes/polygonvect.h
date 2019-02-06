#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_
#include <iostream>
#include <vector>
#include <new>
#include <cmath>
#include <fstream>
#include <string>

#include "polygon.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

#define PI 3.14159265

using namespace std;
using namespace DerivedPolygon;
using namespace DerivedRect;
using namespace DerivedCirc;
using namespace DerivedTri;

namespace DerivedPolyVec
{
	class PolygonVect : public Polygon
	{
		public:
		// Big three
			~PolygonVect() noexcept;			// Destructor
			PolygonVect( const PolygonVect& new_shape ) noexcept;		// Copy constructor
			PolygonVect& operator=( const PolygonVect& new_shape ) noexcept;		// Assigment operator
			
			PolygonVect() noexcept;
			PolygonVect(vector<Point2D> inners) noexcept;
			PolygonVect(Point2D shape) noexcept;
			PolygonVect(Rectangle shape) noexcept;
			PolygonVect(Circle shape) noexcept;
			PolygonVect(Triangle shape) noexcept;
			
			Point2D& operator [](int index) throw(out_of_range&);		// LEFT SIDE
	    	const Point2D& operator [](int index) const throw(out_of_range&);			// RIGHT SIDE
	    	
	    	int get_size() const noexcept;
			void set_size(int number) noexcept;
			
			virtual double perimeter() const noexcept override;
			virtual double area() const noexcept override;
			
			void set_area(double x) noexcept;
			void set_perimeter(double x) noexcept;
			
			/* for incrementing and decrementing the shape positions by 1.0 */
			virtual PolygonVect& operator++() noexcept override;			//Prefix incrementing
			virtual PolygonVect& operator++(int) noexcept override;		//Postfix incrementing
			virtual PolygonVect& operator--() noexcept override;			//Prefix decrementing
			virtual PolygonVect& operator--(int) noexcept override;		//Postfix decrementing
			
			virtual void print(ostream& os) noexcept override;
			
			vector<Point2D>& get_vec() noexcept
			{
				return shapes;
			}
			
			string getcolor() const noexcept;
			
		private:
			vector<Point2D> shapes;
			int size;
			double area_, perimeter_;	
			string color;
	};
}

#endif
