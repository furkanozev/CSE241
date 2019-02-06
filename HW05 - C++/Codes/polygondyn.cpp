#include "polygondyn.h"

namespace DerivedPolyDyn
{
	/* Destructor */
	PolygonDyn::~PolygonDyn() noexcept
	{
		/* deallocate memory */
		delete[] shapes;
		shapes = NULL;
	}
	
	/* Copy constructor */
	PolygonDyn::PolygonDyn( const PolygonDyn &new_shape ) noexcept
	{
		/* Allocate memory, initilaze size then copy points from parameter object */
		int i;
		size = new_shape.size;
		shapes = new Point2D [size];
		for(i=0; i<size; i++)
		{
			shapes[i] = new_shape[i]; // '[]' index operator used in here instead of new_shape.shapes[i].
		}
		area_ = new_shape.area();
		perimeter_ = new_shape.perimeter();
		name = new_shape.getname();
		color = new_shape.getcolor();
	}
	
	/* Assigment operator */
	PolygonDyn& PolygonDyn::operator=( const PolygonDyn& new_shape ) noexcept
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
		area_ = new_shape.area();
		perimeter_ = new_shape.perimeter();
		name = new_shape.getname();
		color = new_shape.getcolor();
		return *this;		// return this object
	}
	
	/* Default constructor */
	PolygonDyn::PolygonDyn() noexcept
				:Polygon("polygondyn")
	{
		// size will be 0 and pointer will be null
		size = 0;
		shapes = NULL;
		area_ = 0;
		perimeter_ = 0;
		color = "blue";
	}
	
	/* A constructor that takes an vector of Point2D objects to represent the Polygon points */
	PolygonDyn::PolygonDyn(vector<Point2D> inners) noexcept
								:Polygon("polygondyn")
	{
		int i = 0;
		size = inners.size();		// assign size 
		shapes = new Point2D[size];	// Memory allocated up to size.
		for(Point2D shape: inners)
		{
			// Copy Point2D object from vector into Polygon object.
			shapes[i] = shape;
			i++;
		}
		area_ = 0;
		perimeter_ = 0;
	}
	
	/* A conversion constructor that converts from a 2D Point. */
	PolygonDyn::PolygonDyn(Point2D shape) noexcept
								:Polygon("polygondyn")
	{
		// Allocate memory to 1 Point2D object then copy in array
		size = 1;		// size will be 1.
		shapes = new Point2D;
		(*shapes) = shape;
		area_ = 0;
		perimeter_ = 0;
	}
	
	/* Conversion constructors that convert from Rectangle object. */
	PolygonDyn::PolygonDyn(Rectangle shape) noexcept
								:Polygon("polygondyn")
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
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/* Conversion constructors that convert from Circle object. */
	PolygonDyn::PolygonDyn(Circle shape) noexcept
							:Polygon("polygondyn")
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
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/* Conversion constructors that convert from Triangle object. */
	PolygonDyn::PolygonDyn(Triangle shape) noexcept
								:Polygon("polygondyn")
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
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/* Operator[] that returns a reference of Point2D object to the point at the given index.  */
	// Left Sýde
	PolygonDyn::Point2D& PolygonDyn::operator [](int index) throw(string)
	{
		// error check
		try
		{
			if(size > index && index >= 0)
	    	{
	    		return shapes[index];
			}
			else throw "Out of Range error.";
		}	
    	catch(string s)
		{
			cerr<<endl<<s<<endl;
			return shapes[0];
		}
	}
	// Rýght Sýde
    const PolygonDyn::Point2D& PolygonDyn::operator [](int index) const throw(string)
    {
    	// error check
		try
		{
			if(size > index && index >= 0)
	    	{
	    		return shapes[index];
			}
			else throw "Out of Range error.";
		}	
    	catch(string s)
		{
			cerr<<endl<<s<<endl;
			return shapes[0];
		}
	}
	
	/* Size setter */
	void PolygonDyn::set_size(int number) noexcept
	{
		size = number;
	}
	/* Size getter */
	int PolygonDyn::get_size() const noexcept
	{
		return size;
	}
	
	double PolygonDyn::perimeter() const noexcept
	{
		return perimeter_;
	}
	
	double PolygonDyn::area() const noexcept
	{
		return area_;
	}
	
	//Prefix incrementing : Firstly increase value then return shape.
	PolygonDyn& PolygonDyn::operator++() noexcept
	{
		int i;
		for(i = 0 ; i < size ; i++)
		{
			shapes[i].setx(shapes[i].getx() + 1);
			shapes[i].sety(shapes[i].gety() + 1);
		}
		return (*this);
	}
	//Postfix incrementing : Firstly increase value then return original shape. To return original shape, it is necessary to copy the this shape.
	PolygonDyn& PolygonDyn::operator++(int) noexcept
	{
		PolygonDyn shape_temp = (*this);
		PolygonDyn* ptr_st = &shape_temp;
		int i;
		for(i = 0 ; i < size ; i++)
		{
			shapes[i].setx(shapes[i].getx() + 1);
			shapes[i].sety(shapes[i].gety() + 1);
		}
		return (*ptr_st);
	}
	//Prefix decrementing : Firstly decrease value then return shape.
	PolygonDyn& PolygonDyn::operator--() noexcept
	{ 
		for(int i = 0 ; i < size ; i++)
		{
			// position can not be negative.
			if(shapes[i].getx()-1>= 0 && shapes[i].gety()-1>= 0)
			{
				shapes[i].setx(shapes[i].getx() - 1);
				shapes[i].sety(shapes[i].gety() - 1);
			}
		}
		return (*this);
	}
	//Postfix decrementing : Firstly decrease value then return original shape. To return original shape, it is necessary to copy the this shape.
	PolygonDyn& PolygonDyn::operator--(int) noexcept
	{
		// position can not be negative.
		PolygonDyn shape_temp = (*this);
		PolygonDyn* ptr_st = &shape_temp;
		for(int i = 0 ; i < size ; i++)
		{
			// position can not be negative.
			if(shapes[i].getx()-1>= 0 && shapes[i].gety()-1>= 0)
			{
				shapes[i].setx(shapes[i].getx() - 1);
				shapes[i].sety(shapes[i].gety() - 1);
			}
		}
		return (*ptr_st);
	}
	
	void PolygonDyn::print(ostream& os) noexcept
	{
		int i;
		os<<"\n\t<polygon points=\"";
		for(i=0; i<size; i++)
		{
			os<<" "<<shapes[i].getx()<<" "<<shapes[i].gety()<<" ";		// '[]' index operator used in here instead of shape.shapes[i].getx() and gety().
		}
		os<<"\" fill=\"blue\" stroke=\"red\" stroke-width=\"0.1\" />";
	}
	
	
	void PolygonDyn::set_area(double x) noexcept
	{
		area_ = x;
	}
	void PolygonDyn::set_perimeter(double x) noexcept
	{
		perimeter_ = x;
	}
	string PolygonDyn::getcolor() const noexcept
	{
		return color;
	}
	
}
