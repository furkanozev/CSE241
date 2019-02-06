#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <iostream>
#include <vector>
#include <fstream>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "polygon.h"
#include <cmath>
#include <new>

using namespace std;
using mypolygon::Polygon;		// Using mypolygon namespace 

/* An enum variable that defines the type of shape object */
enum class Shapes { Rectangle, Circle, Triangle };

// create namespace of mycomposedshape
namespace mycomposedshape
{
	class ComposedShape{
		
		public:
			
			/* Constructor */
			/* A total of 9 combinations are possible, so there are 9 overloaded constructors. */
			ComposedShape(Rectangle shape1, Rectangle shape2);		// Container is Rectangle , Inner is Rectangle.
			ComposedShape(Rectangle shape1, Circle shape2);			// Container is Rectangle , Inner is Circle.
			ComposedShape(Rectangle shape1, Triangle shape2);		// Container is Rectangle , Inner is Triangle.
			
			
			ComposedShape(Circle shape1, Rectangle shape2);			// Container is Circle , Inner is Rectangle.
			ComposedShape(Circle shape1, Circle shape2);			// Container is Circle , Inner is Circle.
			ComposedShape(Circle shape1, Triangle shape2);			// Container is Circle , Inner is Triangle.
			
			ComposedShape(Triangle shape1, Rectangle shape2);		// Container is Triangle , Inner is Rectangle.
			ComposedShape(Triangle shape1, Circle shape2);			// Container is Triangle , Inner is Circle.
			ComposedShape(Triangle shape1, Triangle shape2);		// Container is Triangle , Inner is Triangle.
			
			/* A total of 9 combinations are possible, so there are 9 overloaded OptimalFit functions. */
			void OptimalFit(Rectangle shape1, Rectangle shape2);	// Container is Rectangle , Inner is Rectangle.
			void OptimalFit(Rectangle shape1, Circle shape2);		// Container is Rectangle , Inner is Circle.
			void OptimalFit(Rectangle shape1, Triangle shape2);		// Container is Rectangle , Inner is Triangle.
			
			
			void OptimalFit(Circle shape1, Rectangle shape2);		// Container is Circle , Inner is Rectangle.
			void OptimalFit(Circle shape1, Circle shape2);			// Container is Circle , Inner is Circle.
			void OptimalFit(Circle shape1, Triangle shape2);		// Container is Circle , Inner is Triangle.
			
			void OptimalFit(Triangle shape1, Rectangle shape2);		// Container is Triangle , Inner is Rectangle.
			void OptimalFit(Triangle shape1, Circle shape2);		// Container is Triangle , Inner is Circle.
			void OptimalFit(Triangle shape1, Triangle shape2);		// Container is Triangle , Inner is Triangle.
			
			/* Getter for containers */
			Rectangle get_r_container();	
			Circle get_c_container();
			Triangle get_t_container();
			
			/* Getter for inners */
			Rectangle get_r_inner();
			Circle get_c_inner();
			Triangle get_t_inner();
	
			/* Getter Polygon vector */
			vector<Polygon> get_vector();
			
		
			/* File open and close functions. If entered file name and open with this name. 
				If didn't enter filename, then filename will be default name that is "result.svg" */
			void fileopen(string filename = "result.svg");
			void fileclose();
			/* Getter file */
			ofstream& getfile();
	
			/* for returning a Polygon object.  */
			Polygon& operator [](unsigned int index);
			const Polygon& operator [](unsigned int index) const;
			
			/* for adding a new shape(Point2D) to this Polygon vector . */
			Polygon operator +=(Polygon::Point2D &shape);
			
			/* for drawing(writing) the composed shape. */
			friend ostream& operator <<(ostream& os, ComposedShape& shape);
	
			
		private:
			Rectangle r_container;
			Circle c_container;
			Triangle t_container;
			
			Rectangle r_inner;
			Circle c_inner;
			Triangle t_inner;
			
			/* Polygon vector for shapes */
			vector<Polygon>poly_shapes;
			
			/* Enum type to determine which is type of container. */
			Shapes container;
			
			/* File */
			ofstream file;
	
	};
}
#endif
