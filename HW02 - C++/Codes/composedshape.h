#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <vector>
#include <fstream>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include <cmath>

using namespace std;

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
		
		/* Vectors to keep my inner shapes. Inner can be 3 shape so I need to 3 different vectors. */
		vector<Rectangle> get_rec_vec();
		vector<Circle> get_cir_vec();
		vector<Triangle> get_tri_vec();
		
		/* Fýle open and close functions. If entered file name and open with this name. 
			If didn't enter filename, then filename will be default name that is "result.svg" */
		void fileopen(string filename = "result.svg");
		void fileclose();
		
		/* 3 different draw container funcions overloaded. */
		void drawcontainer(Rectangle shape);
		void drawcontainer(Circle shape);
		void drawcontainer(Triangle shape);
		
		/* 3 different draw inner funcions overloaded. */
		void draw(vector<Rectangle> shape);
		void draw(vector<Circle> shape);
		void draw(vector<Triangle> shape);
		
	private:
		Rectangle r_container;
		Circle c_container;
		Triangle t_container;
		
		Rectangle r_inner;
		Circle c_inner;
		Triangle t_inner;
		
		vector<Rectangle>rec_vec;
		vector<Circle>cir_vec;
		vector<Triangle>tri_vec;
		
		ofstream file;
		
		
		
		
};

#endif
