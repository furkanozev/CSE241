#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

namespace BaseShape
{
	class Shape{
	
		public:
			Shape() noexcept;
			Shape(string x) noexcept;
			
			virtual ~Shape() noexcept;
			
			virtual double area() const = 0;
			virtual double perimeter() const = 0;
			
			bool operator==(const Shape& other) const noexcept;
			bool operator!=(const Shape& other) const noexcept;
			bool operator>=(const Shape& other) const noexcept;
			bool operator<=(const Shape& other) const noexcept;
			bool operator<(const Shape& other) const noexcept;
			bool operator>(const Shape& other) const noexcept;
			
			virtual Shape& operator++() = 0;
			virtual Shape& operator++(int) = 0;
			virtual Shape& operator--() = 0;
			virtual Shape& operator--(int) = 0;					
					
			virtual void print(ostream& os) = 0;
			
			string getname() const noexcept;
			void setname(string x) noexcept;
		
		protected:
			string name;	
			
	};
}

#endif
