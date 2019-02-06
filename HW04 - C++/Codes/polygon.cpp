#include "polygon.h"

using namespace std;

// create namespace of mypolygon
namespace mypolygon
{
	/* Destructor */
	Polygon::~Polygon()
	{
		/* deallocate memory */
		delete[] shapes;
		shapes = NULL;
	}
	
	/* Copy constructor */
	Polygon::Polygon( const Polygon &new_shape )
	{
		/* Allocate memory, initilaze size then copy points from parameter object */
		int i;
		size = new_shape.size;
		shapes = new Point2D [size];
		for(i=0; i<size; i++)
		{
			shapes[i] = new_shape[i]; // '[]' index operator used in here instead of new_shape.shapes[i].
		}
	}
	
	/* Assigment operator */
	Polygon& Polygon::operator=( const Polygon& new_shape )
	{
		/* Deallocate old memory then allocate new memory and update size. After that copy points from parameter object */
		int i;
		size = new_shape.size;
		delete[] shapes;
		shapes = new Point2D [size];
		for(i=0; i<size; i++)
		{
			shapes[i] = new_shape[i]; // '[]' index operator used in here instead of new_shape.shapes[i].
		}
		return *this;		// return this object
	}
	
	/* Default constructor */
	Polygon::Polygon()
	{
		// size will be 0 and pointer will be null
		size = 0;
		shapes = NULL;
	}
	/* A constructor that takes an vector of Point2D objects to represent the Polygon points */
	Polygon::Polygon(vector<Point2D> inners)
	{
		int i = 0;
		size = inners.size();		// assign size 
		shapes = new Point2D[size];	// Memory allocated up to size.
		for(Polygon::Point2D shape: inners)
		{
			// Copy Point2D object from vector into Polygon object.
			shapes[i] = shape;
			i++;
		}
	}
	
	/* A conversion constructor that converts from a 2D Point. */
	Polygon::Polygon(Point2D shape)
	{
		// Allocate memory to 1 Point2D object then copy in array
		size = 1;		// size will be 1.
		shapes = new Point2D;
		(*shapes) = shape;
	}
	
	/* Conversion constructors that convert from Rectangle object. */
	Polygon::Polygon(Rectangle shape)
	{
		size = 4;		// size will be 4.
		// Allocate memory to 4 Point2D object then copy in array
		shapes = new Point2D[4];
		shapes[0].setx(shape.getposx());
		shapes[0].sety(shape.getposy());
		shapes[1].setx(shape.getposx() + shape.getwidth());
		shapes[1].sety(shape.getposy());
		shapes[2].setx(shape.getposx() + shape.getwidth());
		shapes[2].sety(shape.getposy() + shape.getheight());
		shapes[3].setx(shape.getposx());
		shapes[3].sety(shape.getposy() + shape.getheight());
	}
	
	/* Conversion constructors that convert from Circle object. */
	Polygon::Polygon(Circle shape)
	{
		size = 100;		// size will be 100.
		// Allocate memory to 100 Point2D object then copy in array
		int i;
		double angle = 0;
		shapes = new Point2D[100];
		for(i=0; i<100; i++)
		{
			// Circle parametric equation
			//	x = cx + r * cos(a)
			//	y = cy + r * sin(a)	
			angle = (360.0/100) * i;
			shapes[i].setx(shape.getcenterx() + shape.getradius() * cos(angle * PI / 180.0));
			shapes[i].sety(shape.getcentery() + shape.getradius() * sin(angle * PI / 180.0));
		}
	}
	
	/* Conversion constructors that convert from Triangle object. */
	Polygon::Polygon(Triangle shape)
	{
		size = 3;	// size will be 3.
		// Allocate memory to 3 Point2D object then copy in array
		shapes = new Point2D[3];
		shapes[0].setx(shape.getposx1());
		shapes[0].sety(shape.getposy1());
		shapes[1].setx(shape.getposx2());
		shapes[1].sety(shape.getposy2());
		shapes[2].setx(shape.getposx3());
		shapes[2].sety(shape.getposy3());
	}
	
	/* Operator[] that returns a reference of Point2D object to the point at the given index.  */
	// Left Sýde
	Polygon::Point2D& Polygon::operator [](int index)
	{
		// error check
		if(size > index && index >= 0)
    	{
    		return shapes[index];
		}
    	else
    	{
    		exit(1);
		}
	}
	// Rýght Sýde
    const Polygon::Point2D& Polygon::operator [](int index) const
    {
    	// error check
    	if(size > index && index >= 0)
    	{
    		return shapes[index];
		}
    	else
    	{
    		exit(1);
		}
	}
	
	/* Operator== that returns true if two Polygons are equal. */
	bool operator==(const Polygon& shape1, const Polygon& shape2)
	{
		int i;
		/* If size not equal, it will return false */
		if(shape1.size != shape2.size)
		{
			return false;
		}
		else
		{
			/* Else, checks whether all points are the same. */
			for(i=0; i<shape1.size; i++)
			{
				/* If any point is different, it will be false */
				if(shape1.shapes[i].getx() != shape2.shapes[i].getx() || shape1.shapes[i].gety() != shape2.shapes[i].gety())
				{
					return false;
				}
			}
			/* There is no different points so all points are same then return true */
			return true;
		}
	}
	
	/* Operator!= that returns true if two Polygons are not equal. */
	bool operator!=(const Polygon& shape1, const Polygon& shape2)
	{
		/* return opposite of == operator */
		bool result = (shape1 == shape2);
		return (!result);
	}
	
	/* Operator+ that adds two Polygons by concatenating the points and returns the result as a new object. */
	Polygon Polygon::operator +(const Polygon& shape2)
	{
		int i;
		/* Create vector and all points will be collected here. */
		vector<Point2D> inn_vec;
		for(i=0; i<size; i++)
		{
			inn_vec.push_back(shapes[i]);
		}
		for(i=0; i<shape2.size; i++)
		{
			inn_vec.push_back(shape2.shapes[i]);
		}
		/* Create an object that takes vector as a parameter */
		Polygon new_shape(inn_vec);
		/* return new object */
		return new_shape;
	}
	
	/* Operator<< for producing the SVG code. */
	ostream& operator <<(ostream& os, const Polygon& shape)
	{	
		int i;
		os<<"<svg xmlns=\"http://www.w3.org/2000/svg\">"<<"\n\t<polygon points=\"";
		for(i=0; i<shape.size; i++)
		{
			os<<" "<<shape[i].getx()<<" "<<shape[i].gety()<<" ";		// '[]' index operator used in here instead of shape.shapes[i].getx() and gety().
		}
		os<<"\" fill=\"green\" stroke=\"blue\" stroke-width=\"0.1\" /> </svg>";
		return os;
	}
	
	/* Size setter */
	void Polygon::set_size(int number)
	{
		size = number;
	}
	/* Size getter */
	int Polygon::get_size() const
	{
		return size;
	}
	
	/* Point2D nested class's default constructor */
	Polygon::Point2D::Point2D()
							:x(0),y(0)
	{	}
	/* Point2D nested class's constructor that take coordinate */
	Polygon::Point2D::Point2D(double a, double b)
							:x(a),y(b)
	{	}
	
	/* Point2D getter x coordinate */
	double Polygon::Point2D::getx() const
	{
		return x;
	}
	/* Point2D getter y coordinate */
	double Polygon::Point2D::gety() const
	{
		return y;
	}
	/* Point2D setter x coordinate */
	void Polygon::Point2D::setx(double point)
	{
		x = point;
	}
	/* Point2D setter y coordinate */
	void Polygon::Point2D::sety(double point)
	{
		y = point;
	}
}
