#include "polygonvect.h"

namespace DerivedPolyVec
{
	/* Destructor */
	PolygonVect::~PolygonVect() noexcept
	{
		shapes.clear();	
	}
	
	/* Copy constructor */
	PolygonVect::PolygonVect( const PolygonVect &new_shape ) noexcept
	{
		int i = 0;
		size = new_shape.size;
		for(Point2D shape: new_shape.shapes)
		{
			shapes.push_back(shape);
			i++;
		}
		area_ = new_shape.area();
		perimeter_ = new_shape.perimeter();
		name = new_shape.getname();
		color = new_shape.getcolor();
	}
	
	/* Assigment operator */
	PolygonVect& PolygonVect::operator=( const PolygonVect& new_shape ) noexcept
	{
		/* Deallocate old memory then allocate new memory and update size. After that copy points from parameter object */
		int i = 0;
		size = new_shape.size;
		shapes.clear();
		for(Point2D shape: new_shape.shapes)
		{
			shapes.push_back(shape);
			i++;
		}
		area_ = new_shape.area();
		perimeter_ = new_shape.perimeter();
		name = new_shape.getname();
		color = new_shape.getcolor();
		return *this;		// return this object
	}
	
	/* Default constructor */
	PolygonVect::PolygonVect() noexcept
				:Polygon("polygonvect")
	{
		// size will be 0 and pointer will be null
		size = 0;
		area_ = 0;
		perimeter_ = 0;
		color = "blue";
	}
	
	/* A constructor that takes an vector of Point2D objects to represent the Polygon points */
	PolygonVect::PolygonVect(vector<Point2D> inners) noexcept
								:Polygon("polygonvect")
	{
		int i = 0;
		size = inners.size();		// assign size 
		for(Point2D shape: inners)
		{
			// Copy Point2D object from vector into Polygon object.
			shapes.push_back(shape);
			i++;
		}
		area_ = 0;
		perimeter_ = 0;
	}
	
	/* A conversion constructor that converts from a 2D Point. */
	PolygonVect::PolygonVect(Point2D shape) noexcept
								:Polygon("polygonvect")
	{
		// Allocate memory to 1 Point2D object then copy in array
		size = 1;		// size will be 1.
		shapes.push_back(shape);
		area_ = 0;
		perimeter_ = 0;
	}
	
	/* Conversion constructors that convert from Rectangle object. */
	PolygonVect::PolygonVect(Rectangle shape) noexcept
								:Polygon("polygonvect")
	{
		size = 4;		// size will be 4.
		// Allocate memory to 4 Point2D object then copy in array
		Point2D Points[4];
		Points[0].setx(shape.getposx());
		Points[0].sety(shape.getposy());
		Points[1].setx(shape.getposx() + shape.getwidth());
		Points[1].sety(shape.getposy());
		Points[2].setx(shape.getposx() + shape.getwidth());
		Points[2].sety(shape.getposy() + shape.getheight());
		Points[3].setx(shape.getposx());
		Points[3].sety(shape.getposy() + shape.getheight());
		for(int i=0; i<size; i++)
		{
			shapes.push_back(Points[i]);
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/* Conversion constructors that convert from Circle object. */
	PolygonVect::PolygonVect(Circle shape) noexcept
							:Polygon("polygonvect")
	{
		size = 100;		// size will be 100.
		double angle = 0;
		Point2D Points[100];
		for(int i=0; i<100; i++)
		{
			// Circle parametric equation
			//	x = cx + r * cos(a)
			//	y = cy + r * sin(a)	
			angle = (360.0/100) * i;
			Points[i].setx(shape.getcenterx() + shape.getradius() * cos(angle * PI / 180.0));
			Points[i].sety(shape.getcentery() + shape.getradius() * sin(angle * PI / 180.0));
			shapes.push_back(Points[i]);
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/* Conversion constructors that convert from Triangle object. */
	PolygonVect::PolygonVect(Triangle shape) noexcept
								:Polygon("polygonvect")
	{
		size = 3;	// size will be 3.
		// Allocate memory to 3 Point2D object then copy in array
		Point2D Points[3];
		Points[0].setx(shape.getposx1());
		Points[0].sety(shape.getposy1());
		Points[1].setx(shape.getposx2());
		Points[1].sety(shape.getposy2());
		Points[2].setx(shape.getposx3());
		Points[2].sety(shape.getposy3());
		for(int i=0; i<size; i++)
		{
			shapes.push_back(Points[i]);
		}
		area_ = shape.area();
		perimeter_ = shape.perimeter();
		color = shape.getcolor();
	}
	
	/* Operator[] that returns a reference of Point2D object to the point at the given index.  */
	// Left Sýde
	PolygonVect::Point2D& PolygonVect::operator [](int index) throw(out_of_range&)
	{
		// error check
		try 
		{
			shapes.at(index);      // vector::at throws an out-of-range
		}
		catch (const std::out_of_range& oor)
		{
			std::cerr << "Out of Range error: " << oor.what() << '\n';
			exit(1);
		}
		
		return shapes[index];
	}
	// Rýght Sýde
    const PolygonVect::Point2D& PolygonVect::operator [](int index) const throw(out_of_range&)
    {
    	// error check
		try 
		{
			shapes.at(index);      // vector::at throws an out-of-range
		}
		catch (const std::out_of_range& oor)
		{
			std::cerr << "Out of Range error: " << oor.what() << '\n';
			exit(1);
		}
		
		return shapes[index];
	}
	
	/* Size setter */
	void PolygonVect::set_size(int number) noexcept
	{
		size = number;
	}
	/* Size getter */
	int PolygonVect::get_size() const noexcept
	{
		return size;
	}
	
	double PolygonVect::perimeter() const noexcept
	{
		return perimeter_;
	}
	
	double PolygonVect::area() const noexcept
	{
		return area_;
	}
	
	//Prefix incrementing : Firstly increase value then return shape.
	PolygonVect& PolygonVect::operator++() noexcept
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
	PolygonVect& PolygonVect::operator++(int) noexcept
	{
		PolygonVect shape_temp = (*this);
		PolygonVect* ptr_st = &shape_temp;
		int i;
		for(i = 0 ; i < size ; i++)
		{
			shapes[i].setx(shapes[i].getx() + 1);
			shapes[i].sety(shapes[i].gety() + 1);
		}
		return (*ptr_st);
	}
	//Prefix decrementing : Firstly decrease value then return shape.
	PolygonVect& PolygonVect::operator--() noexcept
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
	PolygonVect& PolygonVect::operator--(int) noexcept
	{
		// position can not be negative.
		PolygonVect shape_temp = (*this);
		PolygonVect* ptr_st = &shape_temp;
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
	
	void PolygonVect::print(ostream& os) noexcept
	{
		os<<"\n\t<polygon points=\"";
		for(unsigned int i=0; i<shapes.size(); i++)
		{
			os<<" "<<shapes[i].getx()<<" "<<shapes[i].gety()<<" ";		// '[]' index operator used in here instead of shape.shapes[i].getx() and gety().
		}
		os<<"\" fill=\""<<color<<"\" stroke=\"red\" stroke-width=\"0.1\" />";
	}
	
	void PolygonVect::set_area(double x) noexcept
	{
		area_ = x;
	}
	void PolygonVect::set_perimeter(double x) noexcept
	{
		perimeter_ = x;
	}
	string PolygonVect::getcolor() const noexcept
	{
		return color;
	}
	
}
