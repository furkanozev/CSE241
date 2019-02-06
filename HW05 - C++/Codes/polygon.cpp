#include "polygon.h"

namespace DerivedPolygon
{
	Polygon::Polygon() noexcept
				:Shape("polygon")
	{	}
	
	Polygon::Polygon(string name) noexcept
				:Shape(name)
	{	}
	
	/* Point2D nested class's default constructor */
	Polygon::Point2D::Point2D() noexcept
							:x(0),y(0)
	{	}
	/* Point2D nested class's constructor that take coordinate */
	Polygon::Point2D::Point2D(double a, double b) noexcept
							:x(a),y(b)
	{	}
	
	/* Point2D getter x coordinate */
	double Polygon::Point2D::getx() const noexcept
	{
		return x;
	}
	/* Point2D getter y coordinate */
	double Polygon::Point2D::gety() const noexcept
	{
		return y;
	}
	/* Point2D setter x coordinate */
	void Polygon::Point2D::setx(double point) noexcept
	{
		x = point;
	}
	/* Point2D setter y coordinate */
	void Polygon::Point2D::sety(double point) noexcept
	{
		y = point;
	}
}
