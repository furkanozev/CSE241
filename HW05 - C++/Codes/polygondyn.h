#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_
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

namespace DerivedPolyDyn
{
	class PolygonDyn : public Polygon
	{
		public:
		// Big three
			~PolygonDyn() noexcept;			// Destructor
			PolygonDyn( const PolygonDyn& new_shape ) noexcept;		// Copy constructor
			PolygonDyn& operator=( const PolygonDyn& new_shape )  noexcept;		// Assigment operator
			
			PolygonDyn() noexcept;
			PolygonDyn(vector<Point2D> inners)noexcept;
			PolygonDyn(Point2D shape) noexcept;
			PolygonDyn(Rectangle shape) noexcept;
			PolygonDyn(Circle shape) noexcept;
			PolygonDyn(Triangle shape) noexcept;
			
			Point2D& operator [](int index) throw(string);		// LEFT SIDE
	    	const Point2D& operator [](int index) const throw(string);			// RIGHT SIDE
	    	
	    	int get_size() const noexcept;
			void set_size(int number) noexcept;
			
			virtual double perimeter() const noexcept override;
			virtual double area() const noexcept override;
			
			void set_area(double x) noexcept;
			void set_perimeter(double x) noexcept;
			
			/* for incrementing and decrementing the shape positions by 1.0 */
			virtual PolygonDyn& operator++() noexcept override;			//Prefix incrementing
			virtual PolygonDyn& operator++(int) noexcept override;		//Postfix incrementing
			virtual PolygonDyn& operator--() noexcept override;			//Prefix decrementing
			virtual PolygonDyn& operator--(int) noexcept override;		//Postfix decrementing
			
			virtual void print(ostream& os) noexcept override;
			
			Point2D* get_arr() noexcept
			{
				return shapes;
			}

			string getcolor() const noexcept;
			
		private:
			Point2D* shapes;
			int size;
			double area_, perimeter_;	
			string color;
	};
}

#endif
