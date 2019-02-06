#include "shape.h"	
#include <iostream>

namespace BaseShape
{
	Shape::Shape() noexcept
	{	}
	
	Shape::Shape(string x) noexcept
					:name(x)
	{	}

	Shape::~Shape() noexcept
	{	}

	bool Shape::operator==(const Shape& other) const noexcept
	{
		return (area() == other.area());
	}
	bool Shape::operator!=(const Shape& other) const noexcept
	{
		return (area() != other.area());
	}
	bool Shape::operator>=(const Shape& other) const noexcept
	{
		return (area() >= other.area());
	}
	bool Shape::operator<=(const Shape& other) const noexcept
	{
		return (area() <= other.area());
	}
	bool Shape::operator>(const Shape& other) const noexcept
	{
		return (area() > other.area());
	}
	bool Shape::operator<(const Shape& other) const noexcept
	{
		return (area() < other.area());
	}
	
	string Shape::getname() const noexcept
	{
		return name;
	}
	
	void Shape::setname(string x) noexcept
	{
		name = x;
	}
	
}
