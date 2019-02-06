#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <vector>
#include <fstream>
#include "shape.h"	
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include <cmath>
#include <new>

using namespace std;
using namespace BaseShape;
using namespace DerivedRect;
using namespace DerivedCirc;
using namespace DerivedTri;
namespace DerivedComp{
	

	class ComposedShape : public Shape{
		
		public:
			
			/* Constructor */
			/* A total of 9 combinations are possible, so there are 9 overloaded constructors. */
			ComposedShape() noexcept;
			ComposedShape(Rectangle shape1, Rectangle shape2) noexcept;		// Container is Rectangle , Inner is Rectangle.
			ComposedShape(Rectangle shape1, Circle shape2) noexcept;			// Container is Rectangle , Inner is Circle.
			ComposedShape(Rectangle shape1, Triangle shape2) noexcept;		// Container is Rectangle , Inner is Triangle.
			
			
			ComposedShape(Circle shape1, Rectangle shape2) noexcept;			// Container is Circle , Inner is Rectangle.
			ComposedShape(Circle shape1, Circle shape2) noexcept;			// Container is Circle , Inner is Circle.
			ComposedShape(Circle shape1, Triangle shape2) noexcept;			// Container is Circle , Inner is Triangle.
			
			ComposedShape(Triangle shape1, Rectangle shape2) noexcept;		// Container is Triangle , Inner is Rectangle.
			ComposedShape(Triangle shape1, Circle shape2) noexcept;			// Container is Triangle , Inner is Circle.
			ComposedShape(Triangle shape1, Triangle shape2) noexcept;		// Container is Triangle , Inner is Triangle.
			
			~ComposedShape() noexcept;
   			ComposedShape( const ComposedShape& a ) noexcept;
   			ComposedShape& operator=( const ComposedShape& a ) noexcept;
			
			/* A total of 9 combinations are possible, so there are 9 overloaded OptimalFit functions. */
			void OptimalFit(Rectangle shape1, Rectangle shape2) noexcept;	// Container is Rectangle , Inner is Rectangle.
			void OptimalFit(Rectangle shape1, Circle shape2) noexcept;		// Container is Rectangle , Inner is Circle.
			void OptimalFit(Rectangle shape1, Triangle shape2) noexcept;		// Container is Rectangle , Inner is Triangle.
			
			
			void OptimalFit(Circle shape1, Rectangle shape2) noexcept;		// Container is Circle , Inner is Rectangle.
			void OptimalFit(Circle shape1, Circle shape2) noexcept;			// Container is Circle , Inner is Circle.
			void OptimalFit(Circle shape1, Triangle shape2) noexcept;		// Container is Circle , Inner is Triangle.
			
			void OptimalFit(Triangle shape1, Rectangle shape2) noexcept;		// Container is Triangle , Inner is Rectangle.
			void OptimalFit(Triangle shape1, Circle shape2) noexcept;		// Container is Triangle , Inner is Circle.
			void OptimalFit(Triangle shape1, Triangle shape2) noexcept;		// Container is Triangle , Inner is Triangle.
			
			/* Getter for containers */
			Rectangle get_r_container() const noexcept;	
			Circle get_c_container()  const noexcept;
			Triangle get_t_container()  const noexcept;
			
			/* Getter for inners */
			Rectangle get_r_inner()  const noexcept;
			Circle get_c_inner()  const noexcept;
			Triangle get_t_inner() const noexcept;
	
			virtual void print(ostream& os) noexcept override;
			
			/* Getter vector */
			vector<Shape*> get_inners() const noexcept;
			
	
			/* for returning a shape(ShapeElem) as an object of ShapeElem.  */
			Shape& operator [](int index) throw(out_of_range&);
			const Shape& operator [](int index) const throw(out_of_range&);
			
			/* for adding a new shape(ShapeElem) to this composedShape . */
			Shape& operator +=(Shape &shape) noexcept;
			
			virtual double area() const noexcept override;
			virtual double perimeter() const noexcept override;
			void set_area(double x) noexcept;
			void set_perimeter(double x) noexcept;
			
			virtual ComposedShape& operator++() noexcept override;
			virtual ComposedShape& operator++(int) noexcept override;
			virtual ComposedShape& operator--() noexcept override;
			virtual ComposedShape& operator--(int) noexcept override;
			
		private:
			Rectangle r_container;
			Circle c_container;
			Triangle t_container;
			
			Rectangle r_inner;
			Circle c_inner;
			Triangle t_inner;

			double area_;
			double perimeter_;
			
		
			vector<Shape*>inners;
	
	};
}

#endif
