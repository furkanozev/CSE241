#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <vector>
#include <fstream>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include <cmath>
#include <new>

using namespace std;

/* An enum variable that defines the type of shape object */
enum class Shapes { Rectangle, Circle, Triangle };

class ComposedShape{
	
	public:
		/* Nested Class: ShapeElem => It will have an inner public class ShapeElem that holds two variable members.*/
		class ShapeElem
		{
			public:
				
				/* Constructor : parameter is pointer then cast to void pointer*/
				ShapeElem(Rectangle* r_inner);
				ShapeElem(Circle* c_inner);
				ShapeElem(Triangle* t_inner);
				
				/* Getter */
				double get_area();			// Get area
				double get_perimeter();		// Get perimeter
				
				/* getter ShapeObject (void*) */
				void* getptr();
				/* getter enum shape */
				Shapes getshape();
				
				/* Overloaded operator<<  for drawing(writing) the shape to an ostream object such as an SVG file or cout object */
				friend ostream& operator <<(ostream& os, ShapeElem Shape);
				
			private:
				/* An enum variable that defines the type of shape object  */
				Shapes shape;
				/* A void * that holds a pointer to one of the shape objects  */
				void* ShapeObject;
		};
		
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

		/* Getter ShapeElem vector */
		vector<ShapeElem> get_inners();
		
	
		/* File open and close functions. If entered file name and open with this name. 
			If didn't enter filename, then filename will be default name that is "result.svg" */
		void fileopen(string filename = "result.svg");
		void fileclose();
		/* Getter file */
		ofstream& getfile();

		/* for returning a shape(ShapeElem) as an object of ShapeElem.  */
		ComposedShape::ShapeElem& operator [](int index);
		
		/* for adding a new shape(ShapeElem) to this composedShape . */
		ComposedShape::ShapeElem operator +=(ShapeElem &shape);
		
		/* for drawing(writing) the composed shape. */
		friend ostream& operator <<(ostream& os, ComposedShape& shape);

		
	private:
		Rectangle r_container;
		Circle c_container;
		Triangle t_container;
		
		Rectangle r_inner;
		Circle c_inner;
		Triangle t_inner;
		
		/* Enum type to determine which is type of container. */
		Shapes container;
		
		/* ShapeElem vector for inners */
		vector<ShapeElem>inners;
		
		/* File */
		ofstream file;

};

#endif
