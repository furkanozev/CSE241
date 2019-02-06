#include "polyline.h"

using namespace std;
// create namespace of mypolyline
namespace mypolyline
{

	Polyline::Polyline( const Polyline &new_shape )
	{
		// Call Polygon object's copy constructor.
		object = new_shape.object;
	}
	
	/* Assigment operator */
	Polyline& Polyline::operator=( const Polyline& new_shape )
	{
		// Call Polygon object's assigment operator.
		object = new_shape.object;
		return *this;
	}
	
	/* Default constructor */
	Polyline::Polyline()
	{
		/* Create polygon object with default constructor of Polygon then assign new object into object. */
		Polygon temp;
		object = temp;
	}
	
	/* A constructor that takes an vector of Point2D objects to represent the Polyline points */
	Polyline::Polyline(vector<Polygon::Point2D> inners)
	{
		// Create new polygon object with call constructor that take vector.
		Polygon temp(inners);
		// Then call assigment operator to copy data from temp to object.
		object = temp;
	}
	
	/* A conversion constructor that converts from a 2D Point. */
	Polyline::Polyline(Polygon::Point2D shape)
	{
		// Create new polygon object with call constructor that take Point2D object.
		Polygon temp(shape);
		// Then call assigment operator to copy data from temp to object.
		object = temp;
	}
	
	Polyline::Polyline(Rectangle shape)
	{
		// Create new polygon object with call constructor that take Rectangle object.
		Polygon temp(shape);
		// Then call assigment operator to copy data from temp to object.
		object = temp;
	}
	
	Polyline::Polyline(Circle shape)
	{
		// Create new polygon object with call constructor that take Circle object.
		Polygon temp(shape);
		// Then call assigment operator to copy data from temp to object.
		object = temp;
	}
	
	Polyline::Polyline(Triangle shape)
	{
		// Create new polygon object with call constructor that take Triangle object.
		Polygon temp(shape);
		// Then call assigment operator to copy data from temp to object.
		object = temp;
	}
	
	/* Operator[] that returns a reference of Point2D object to the point at the given index.  */
	// Left Sýde
	Polygon::Point2D& Polyline::operator [](const int index)
	{
		// Call Polygon object index operator then return it
		return object[index];
	}
	
    const Polygon::Point2D& Polyline::operator [](const int index) const
    {
    	// Call Polygon object index operator then return it
    	return object[index];
	}
	
	/* Operator== that returns true if two Polyline are equal. */
	bool operator==(const Polyline& shape1, const Polyline& shape2)
	{
		// Call Polygon object == operator then return it's result.
		return (shape1.object == shape2.object);
	}
	
	/* Operator!= that returns true if two Polyline are not equal. */
	bool operator!=(const Polyline& shape1, const Polyline& shape2)
	{
		// Call Polygon object == operator then return it's result.
		return (shape1.object != shape2.object);
	}
	
	/* Operator+ that adds two Polyline by concatenating the points and returns the result as a new object. */
	Polyline Polyline::operator +(const Polyline& shape2)
	{
		/* Create Polygon with Copy constructor and + operator */
		Polygon new_polygon = object + shape2.object;
		/* Create new Polyline object */
		Polyline new_polyline;
		/* Ýntiliaze new polyline's polygon object */
		new_polyline.object = new_polygon;
		// return new polyline object
		return new_polyline;
	}
	
	/* Operator<< for producing the SVG code. */
	ostream& operator <<(ostream& os,const Polyline& shape)
	{	
		int i;
		os<<"<svg xmlns=\"http://www.w3.org/2000/svg\">"<<"\n<polyline points=\"";
		for(i=0; i<shape.get_size(); i++) // Instead of shape.object.get_size() 
		{
			os<<" "<<shape[i].getx()<<" "<<shape[i].gety()<<" ";		// '[]' index operator used in here instead of shape.object[i].gety() and gety().
		}
		os<<"\" fill=\"yellow\" stroke=\"red\" stroke-width=\"4\" /> </svg>";
		return os;
	}
	
	// Instead of shape.object.get_size() 
	int Polyline::get_size() const
	{
		return object.get_size();
	}
}
