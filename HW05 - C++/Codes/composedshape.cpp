#include <iostream>
#include "composedshape.h"
# define M_PI		3.14159265358979323846

using namespace std;

namespace DerivedComp{
	/* auto and decltype was used in this part much times.*/
	/* Composition used in this part. */
	/* Determine container enum type */
	/* Constructors */
	ComposedShape::ComposedShape(Rectangle shape1, Rectangle shape2) noexcept
					:Shape("composedshape"), r_container(shape1), r_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
	
	ComposedShape::ComposedShape(Rectangle shape1, Circle shape2) noexcept
					:Shape("composedshape"), r_container(shape1), c_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
	
	ComposedShape::ComposedShape(Rectangle shape1, Triangle shape2) noexcept
					:Shape("composedshape"), r_container(shape1), t_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
	
	
	ComposedShape::ComposedShape(Circle shape1, Rectangle shape2) noexcept
						:Shape("composedshape"), c_container(shape1), r_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
		
	ComposedShape::ComposedShape(Circle shape1, Circle shape2) noexcept
						:Shape("composedshape"), c_container(shape1), c_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
	
	ComposedShape::ComposedShape(Circle shape1, Triangle shape2) noexcept
						:Shape("composedshape"), c_container(shape1), t_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
	
	ComposedShape::ComposedShape(Triangle shape1, Rectangle shape2) noexcept
						:Shape("composedshape"), t_container(shape1), r_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
	
	ComposedShape::ComposedShape(Triangle shape1, Circle shape2) noexcept
						:Shape("composedshape"), t_container(shape1), c_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
	
	ComposedShape::ComposedShape(Triangle shape1, Triangle shape2) noexcept
						:Shape("composedshape"), t_container(shape1), t_inner(shape2)
	{	
		area_ = shape1.area();
		perimeter_ = shape1.perimeter();
	}
	
	ComposedShape::ComposedShape() noexcept
					:Shape("composedshape")
	{	
		area_ = 0;
		perimeter_ = 0;
	}
	
	ComposedShape::~ComposedShape() noexcept
	{
		for(Shape* x: inners)
		{
			delete x;
			x = nullptr;
		}
		inners.clear();
	}
   	ComposedShape::ComposedShape( const ComposedShape& a ) noexcept
   	{
   		Rectangle* rec;
   		Circle* cir;
   		Triangle* tri;
   		for(Shape* x: a.get_inners())
		{
			if(dynamic_cast < Rectangle* > (x) != nullptr)
			{
				rec = new Rectangle;	
				(*rec) = *(dynamic_cast < Rectangle* > (x));
				inners.push_back(rec);
			}
			else if(dynamic_cast < Circle* > (x) != nullptr)
			{	
				cir = new Circle;	
				(*cir) = *(dynamic_cast < Circle* > (x));
				inners.push_back(cir);	
			}
			else if(dynamic_cast < Triangle* > (x) != nullptr)
			{	
				tri = new Triangle;	
				(*tri) = *(dynamic_cast < Triangle* > (x));	
				inners.push_back(tri);
			}
		}
		r_container = a.get_r_container();
		c_container = a.get_c_container();
		t_container = a.get_t_container();
		r_inner = a.get_r_inner();
		c_inner = a.get_c_inner();
		t_inner = a.get_t_inner();
	}
   	ComposedShape& ComposedShape::operator=( const ComposedShape& a ) noexcept
   	{
   		for(Shape* x: inners)
		{
			delete x;
			x = nullptr;
		}
		inners.clear();
   		Rectangle* rec;
   		Circle* cir;
   		Triangle* tri;
   		for(Shape* x: a.get_inners())
		{
			if(dynamic_cast < Rectangle* > (x) != nullptr)
			{
				rec = new Rectangle;	
				(*rec) = *(dynamic_cast < Rectangle* > (x));
				inners.push_back(rec);
			}
			else if(dynamic_cast < Circle* > (x) != nullptr)
			{	
				cir = new Circle;	
				(*cir) = *(dynamic_cast < Circle* > (x));
				inners.push_back(cir);	
			}
			else if(dynamic_cast < Triangle* > (x) != nullptr)
			{	
				tri = new Triangle;	
				(*tri) = *(dynamic_cast < Triangle* > (x));	
				inners.push_back(tri);
			}
		}
		r_container = a.get_r_container();
		c_container = a.get_c_container();
		t_container = a.get_t_container();
		r_inner = a.get_r_inner();
		c_inner = a.get_c_inner();
		t_inner = a.get_t_inner();

		return (*this);
	}
	
	/* auto and decltype was used in this OptimalFit functions much times.*/
	/* new memmory allocate used in OptimalFit functions then these pointers have been sent to vector. */
	/* Rectangles within A Rectangle */
	void ComposedShape::OptimalFit(Rectangle shape1, Rectangle shape2) noexcept
	{
		Rectangle* conta = new Rectangle(shape1.getwidth(),shape1.getheight(),0,0,"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double width = shape1.getwidth(), height = shape1.getheight(), width2 = shape2.getwidth(), height2 = shape2.getheight();
		/* pos1 and pos2 => To calculate possibility to rotate, x and y => to keep coordinate */
		auto x=0 ,y=0;
		decltype(x) pos1, pos2, temp;
		/* tempx and tempy keep coordinate, count_x keep numbers of shapes that fit horizontally, count_y keep numbers of shapes that fit vertically, temp_count keep numbers of shapes fitted in big rectangle */
		int tempx, tempy, count_x=0, count_y=0;
		double area = 0;		/* Total area of placed shapes */
		
		pos1 = (width / width2) * (height / height2);			/* If we place rectangles as user enters */
		pos2 = (width / height2) * (height / width2);			/* If we place rectangles as rotate 90 degrees */
		
		/* Compared to which one can have more shapes*/
		if(pos2 > pos1)			/* Rotate 90 degrees and fit in big Rectangle */
		{
			temp = width2;
			width2 = height2;
			height2 = temp;
		}
		
		/* Small shapes will be placed upwards from the bottom of the large rectangle. */
		while(height - y >= height2)
		{
			x=0;		/* Started point is 0 for x axis */
			/* Small shapes will be placed from the left of the large rectangle to the right. */
			while(width - x >= width2)
			{
				/* Create new inner shape and send pointer of this shape to vector */
				Rectangle * small_shape = new Rectangle;
				/* For different colors */
				if(count_x % 3 == 0) small_shape->setcolor("green");
				else if(count_x % 3 == 1) small_shape->setcolor("yellow");
				else small_shape->setcolor("pink");
				/* Set values in small_shape then small_shape pushed in vector to keep */
				small_shape->setname("rectangle");
				small_shape->setposx(x);
				small_shape->setposy(y);
				small_shape->setwidth(width2);
				small_shape->setheight(height2);
				small_shape->add_total_area();
				small_shape->add_total_perimeter();
				inners.push_back(small_shape);
				/* Next possible coordinate */
				x += width2;
				count_x++;
			}
			y += height2;
			count_y++;
		}
		
		/* Let's fit shapes on the empty parts of right. */
		tempx = x;
		tempy = y;
		
		y=0;
		/* It is trying to fit the small rectangles by rotate 90 degrees on the right side of the large rectangle. Start from the top of y axis.*/
		while(height - y >= width2)
		{
			x = tempx;
			while(width - x >= height2)
			{
				/* Create new inner shape and send pointer of this shape to vector */
				Rectangle * small_shape2 = new Rectangle;
				/* For different colors */
				if(count_x % 3 == 0) small_shape2->setcolor("green");
				else if(count_x % 3 == 1) small_shape2->setcolor("yellow");
				else small_shape2->setcolor("pink");
				/* Set values in small_shape then small_shape pushed in vector to keep */
				small_shape2->setname("rectangle");
				small_shape2->setposx(x);
				small_shape2->setposy(y);
				small_shape2->setwidth(height2);
				small_shape2->setheight(width2);
				small_shape2->add_total_area();
				small_shape2->add_total_perimeter();
				inners.push_back(small_shape2);
				/* Next possible coordinate */
				x += height2;
				count_x++;
			}
			y += width2;
			count_y++;
		}
		/* Let's fit shapes on the empty parts of bottom. */
		/* It is trying to fit the small rectangles by rotate 90 degrees on the bottom side of the large rectangle. Start from the top of x axis.*/
		y=tempy;
		x=0;
		while(height - y >= width2)
		{
			x = 0;
			while(width - x >= height2)
			{
				/* Create new inner shape and send pointer of this shape to vector */
				Rectangle * small_shape3 = new Rectangle;
				/* For different colors */
				if(count_x % 3 == 0) small_shape3->setcolor("green");
				else if(count_x % 3 == 1) small_shape3->setcolor("yellow");
				else small_shape3->setcolor("pink");
				/* Set values in small_shape then small_shape pushed in vector to keep */
				small_shape3->setname("rectangle");
				small_shape3->setposx(x);
				small_shape3->setposy(y);
				small_shape3->setwidth(height2);
				small_shape3->setheight(width2);
				small_shape3->add_total_area();
				small_shape3->add_total_perimeter();
				inners.push_back(small_shape3);
				/* Next possible coordinate */
				x += height2;
				count_x++;
			}
			y += width2;
			count_y++;
		}

		/* Calculate area and shapes' number */
		area = (width*height)-(width2*height2*count_x);
		cout<<endl<<"---- Rectangles in Rectangle ----"<<endl;
		cout<<"Container width = "<<width<<" height = "<<height<<" - Inner width = "<<width2<<" height = "<<height2<<endl;
		cout<<"I can fit at most "<<count_x<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n"; 
	}
	
	/* Circles within A Rectangle */
	void ComposedShape::OptimalFit(Rectangle shape1, Circle shape2) noexcept
	{
		Rectangle* conta = new Rectangle(shape1.getwidth(),shape1.getheight(),0,0,"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double width = shape1.getwidth(), height = shape1.getheight(), radius2 = shape2.getradius();
		Circle small_shape;
		
		auto numx=0, numy=0, countx=0, county=0;
		decltype(numx) tempx, tempy, temp;
		/* numx =>  Number of horizontally fits , numy =>  Number of vertically fits, countx keep fitted shapes, county keep step of vertically */
		double wastex, wastey;
		/* wastex and wastey keep free places */
		double area = 0;
		/* Calculate how many shapes by horizontal and vertical  will be placed. */
		numx = temp = width / (2*radius2);
		numy = height / (2*radius2);
		/*It can center the small shapes by sharing the free places equally.*/
		wastex = (width - numx * radius2 * 2) / 2;
		wastey = (height - numy * radius2 * 2) / 2;
		
		while(numy > 0)
		{
			/* Calculate y coordinate */
			tempy = radius2 + county * radius2 * 2;
			countx = 0;
			numx = temp;		/* Started point for x axis */
			while(numx > 0)
			{
				/* Create new inner shape and send pointer of this shape to vector */
				Circle * small_shape = new Circle;
				/* Calculate x coordinate */
				tempx = radius2 + countx * radius2 * 2;
				/* Set values in small_shape then small_shape pushed in vector to keep */
				small_shape->setname("circle");
				small_shape->setcolor("green");
				small_shape->setradius(radius2);
				small_shape->setcenterx(wastex+tempx);
				small_shape->setcentery(wastey+tempy);
				small_shape->add_total_area();
				small_shape->add_total_perimeter();
				inners.push_back(small_shape);
				countx++;
				numx--;
			}
			county++;
			numy--;
		}
		
		/* Calculate area and shapes' number */
		area = (width * height) - ((M_PI*radius2*radius2)*(countx*county));
		cout<<endl<<"---- Circles in Rectangle ----"<<endl;
		cout<<"Container width = "<<width<<" height = "<<height<<" - Inner radius = "<<radius2<<endl;
		cout<<"I can fit at most "<<countx*county<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	}
	
	/* Triangles within A Rectangle */
	void ComposedShape::OptimalFit(Rectangle shape1, Triangle shape2) noexcept
	{
		Rectangle* conta = new Rectangle(shape1.getwidth(),shape1.getheight(),0,0,"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double width = shape1.getwidth(), height = shape1.getheight(), edge2 = shape2.getedge();
		Triangle small_shape;
		
		auto countx=0, county=0, sum=0;
		/* Coordinate of triangles */
		double x1, x2, x3, y1, y2, y3;
		double tempx, tempy;
		/* numx =>  Number of horizontally fits , numy =>  Number of vertically fits */
		double area=0;
		decltype(countx) i, j, temp_counter = 0, numx, numy, temp;
		
		
		numx = width / edge2;
		numy = height / (edge2*sqrt(3)/2);
		temp = numx;
		
		x1 = 0;
		y1 = 0;
		x2 = edge2;
		y2 = 0;
		x3 = edge2/2;
		y3 = edge2/2*sqrt(3);
		
		i = numy;
		j = numx;
		
		/* Calculate to fit shapes by possible horizontal and vertical. */ 
		while(i>0)
		{
			j = temp;
			tempy = county*edge2*sqrt(3)/2;		/* Calculate y coordinate */
			temp_counter = 0;
			while(j>0)
			{
				/* Create new inner shape and send pointer of this shape to vector */
				Triangle * small_shape = new Triangle;
				/* Calculate x coordinate */
				tempx = temp_counter*edge2;
				/* Set values in small_shape then small_shape pushed in vector to keep */
				small_shape->setname("triangle");
				small_shape->setcolor("yellow");
				small_shape->setedge(edge2);
				small_shape->setposx1(x1+tempx);
				small_shape->setposy1(y1+tempy);
				small_shape->setposx2(x2+tempx);
				small_shape->setposy2(y2+tempy);
				small_shape->setposx3(x3+tempx);
				small_shape->setposy3(y3+tempy);
				small_shape->add_total_area();
				small_shape->add_total_perimeter();
				inners.push_back(small_shape);
				j--;
				countx++;
				temp_counter++;
			}
			county++;
			i--;	
		}
		/* Keep fitted shapes number */
		sum += countx;
		
		countx = 0;
		county = 0;
		/* Calculate to fit shapes */
		numx = (width-edge2/2) / edge2;
		numy = height / (edge2*sqrt(3)/2);
		temp = numx;
		
		/* Calculate new coordinate for triangles' base at the top. */
		x1 = edge2;
		y1 = 0;
		x2 = edge2/2;
		y2 = edge2/2*sqrt(3);
		x3 = edge2*3/2;
		y3 = edge2/2*sqrt(3);
		
		i = numy;
		j = numx;
		/* The triangles are placed with the base on top. */
		while(i>0)
		{
			j = temp;
			tempy = county*edge2*sqrt(3)/2;			/* Calculate y coordinate */
			temp_counter = 0;
			while(j>0)
			{
				/* Create new inner shape and send pointer of this shape to vector */
				Triangle * small_shape2 = new Triangle;
				tempx = temp_counter*edge2;			/* Calculate x coordinate */
				/* Set values in small_shape then small_shape pushed in vector to keep */
				small_shape2->setname("triangle");
				small_shape2->setcolor("green");
				small_shape2->setedge(edge2);
				small_shape2->setposx1(x1+tempx);
				small_shape2->setposy1(y1+tempy);
				small_shape2->setposx2(x2+tempx);
				small_shape2->setposy2(y2+tempy);
				small_shape2->setposx3(x3+tempx);
				small_shape2->setposy3(y3+tempy);
				small_shape2->add_total_area();
				small_shape2->add_total_perimeter();
				inners.push_back(small_shape2);
				j--;
				countx++;
				temp_counter++;
			}
			county++;
			i--;	
		}

		/* Calculate area and shapes' number */
		sum += countx;
		area = (width*height)- sum * (pow(edge2,2)*sqrt(3)/4);
		cout<<endl<<"---- Triangles in Rectangle ----"<<endl;
		cout<<"Container width = "<<width<<" height = "<<height<<" - Inner edge = "<<edge2<<endl;
		cout<<"I can fit at most "<<sum<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";

	}
	
	/* Rectangles within A Circle */
	void ComposedShape::OptimalFit(Circle shape1, Rectangle shape2) noexcept
	{
		Circle* conta = new Circle(shape1.getradius(),shape1.getradius(),shape1.getradius(),"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double radius = shape1.getradius(), width2 = shape2.getwidth(), height2 = shape2.getheight();
		Rectangle small_shape;
		
		auto countx=0, county=0, flag=0;
		/* Variables to define center coordinate */
		double x; 
		decltype(x) y, area=0;
		/* Start to fit on x=0 and y=0 */
		x = 0;
		y = 0;
		
		/* It places rectangles in the circle from upper to bottom. */
		while(y <= 2*radius)
		{
			x = 0.5;
			flag = 0;
			/* It places rectangles in the circle from left to right. */
			while(x <= 2*radius)
			{
				/* Check that the rectangle is inside the circle. To use circle equation for corners of the rectangle.*/ 
				if((pow(radius-x,2) + pow(radius-y,2) <= pow(radius,2)) && (pow(radius-x-width2,2) + pow(radius-y,2) <= pow(radius,2)) && (pow(radius-x,2) + pow(radius-y-height2,2) <= pow(radius,2)) && (pow(radius-x-width2,2) + pow(radius-y-height2,2) <= pow(radius,2)))
				{
					/* Create new inner shape and send pointer of this shape to vector */
					Rectangle * small_shape = new Rectangle;
					/* Set values in small_shape then small_shape pushed in vector to keep */
					small_shape->setname("rectangle");
					small_shape->setcolor("green");
					small_shape->setwidth(width2);
					small_shape->setheight(height2);
					small_shape->setposx(x+0.5);
					small_shape->setposy(y+0.5);
					small_shape->add_total_area();
					small_shape->add_total_perimeter();
					inners.push_back(small_shape);
					countx++;
					/* New x coordinate */
					x += (width2+0.5);
					/* If the rectangle is placed, flag will be 1. */
					flag=1;
				}
				/* Fit rectangles not possible for this x coordinate then x increase 1 and check again */
				else x += 1;
			}
			/* If the rectangle is placed, determine new y coordinate */
			if(flag==1) y += (height2+0.5);
			/* Fit rectangles not possible for this y coordinate then y increase  1 and check again */
			else y += 1;
			county++;
		}

		/* Calculate area and shapes' number */
		area = M_PI * pow(radius,2) - countx*width2*height2;
		cout<<endl<<"---- Rectangles in Circle ----"<<endl;
		cout<<"Container radius = "<<radius<<" - Inner width = "<<width2<<" height = "<<height2<<endl;
		cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";

	}
	
	/* Circles within A Circle */
	void ComposedShape::OptimalFit(Circle shape1, Circle shape2) noexcept
	{
		Circle* conta = new Circle(shape1.getradius(),shape1.getradius(),shape1.getradius(),"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double radius = shape1.getradius(), radius2 = shape2.getradius();
		Circle small_shape;
		
		auto countx=0, county=0 , flag=0;
		double x=0;
		decltype(x) y=0,area=0;
		
		/* It places circles in the circle from upper to bottom. */
		while(y <= 2*radius)
		{
			x = 0;
			flag = 0;
			/* It places rectangles in the circle from left to right. */
			while(x <= 2*radius)
			{
				/* Check that the small circles is inside the circle. To use circle equation for small circle. Think of it as fitting the smallest squares around the circle. But not fit squares , fit circles. So checked squares corners with circle equation.*/ 
				if((pow(radius-x,2) + pow(radius-y,2) <= pow(radius,2)) && (pow(radius-x-radius2*2,2) + pow(radius-y,2) <= pow(radius,2)) && (pow(radius-x,2) + pow(radius-y-radius2*2,2) <= pow(radius,2)) && (pow(radius-x-radius2*2,2) + pow(radius-y-radius2*2,2) <= pow(radius,2)))
				{
					/* Create new inner shape and send pointer of this shape to vector */
					Circle * small_shape = new Circle;
					/* Set values in small_shape then small_shape pushed in vector to keep */
					small_shape->setname("circle");
					small_shape->setcolor("green");
					small_shape->setradius(radius2);
					small_shape->setcenterx(x+radius2);
					small_shape->setcentery(y+radius2);
					small_shape->add_total_area();
					small_shape->add_total_perimeter();
					inners.push_back(small_shape);
					countx++;
					/* Update new possible coordinate */
					x += radius2*2;
					/* If circle is fitted, then flag will be 1 .*/
					flag=1;
				}
				/* Circle was not fitted, then increase x coordinate by 1 then check again. */
				else x += 1;
			}
			/* If circle is fitted, then update new possible y coordinate */
			if(flag==1) y += radius2*2;
			/* else increase y coordinate by 1 then check again */
			else y += 1;
			county++;
		}

		/* Calculate area and shapes' number */
		area = M_PI * pow(radius,2) - countx*M_PI * pow(radius2,2);
		cout<<endl<<"---- Circles in Circle ----"<<endl;
		cout<<"Container radius = "<<radius<<" - Inner radius = "<<radius2<<endl;
		cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";

	}
	
	/* Triangles within A Circle */
	void ComposedShape::OptimalFit(Circle shape1, Triangle shape2) noexcept
	{
		Circle* conta = new Circle(shape1.getradius(),shape1.getradius(),shape1.getradius(),"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double radius = shape1.getradius(), edge2 = shape2.getedge();
		Triangle small_shape;
		
		auto countx=0, county=0, flag=0;
		double x1; 
		decltype(x1) x2, x3, y1, y2, y3, area=0;			/* Coordinate of triangles */
		
		/* Calculate triangles coordinate */
		x1 = 0;
		y1 = 2*radius;
		x2 = x1+edge2;
		y2 = y1;
		x3 = (x1+x2)/2;
		y3 = y1-edge2*sqrt(3)/2;
		
		/* It places triangles in the circle from bottom to upper. */
		while(y3 >= 0)
		{
			/* Update new coordinate of next possible triangle */
			x1 = 0;
			x2 = x1+edge2;
			x3 = (x1+x2)/2;
			y2 = y1;
			y3 = y1-edge2*sqrt(3)/2;
			flag=0;
			/* It places triangles in the circle from left to right. */
			while(x2 <= 2*radius)
			{
				/* Check that the small triangles are inside the circle. To use circle equation for small triangles. So checked triangles corners with circle equation.*/ 
				if((pow(radius-x1,2) + pow(radius-y1,2) <= pow(radius,2)) && (pow(radius-x2,2) + pow(radius-y2,2) <= pow(radius,2)) && (pow(radius-x3,2) + pow(radius-y3,2) <= pow(radius,2)))
				{
					/* Create new inner shape and send pointer of this shape to vector */
					Triangle * small_shape = new Triangle;
					/* Set values in small_shape then small_shape pushed in vector to keep */
					small_shape->setname("triangle");
					small_shape->setcolor("green");
					small_shape->setedge(edge2);
					small_shape->setposx1(x1);
					small_shape->setposy1(y1);
					small_shape->setposx2(x2);
					small_shape->setposy2(y2);
					small_shape->setposx3(x3);
					small_shape->setposy3(y3);
					small_shape->add_total_area();
					small_shape->add_total_perimeter();
					inners.push_back(small_shape);
					countx++;
					flag=1;
					/* If possible, print the other triangle that rotated it 60 degrees alongside. Check with circle equation */
					if((pow(radius-x1-edge2*3/2,2) + pow(radius-y1+edge2*sqrt(3)/2,2) <= pow(radius,2)) && (pow(radius-x2,2) + pow(radius-y2,2) <= pow(radius,2)) && (pow(radius-x3,2) + pow(radius-y3,2) <= pow(radius,2)))
					{
						/* Create new inner shape and send pointer of this shape to vector */
						Triangle * small_shape2 = new Triangle;
						/* Set values in small_shape then small_shape pushed in vector to keep */
						small_shape2->setname("triangle");
						small_shape2->setcolor("blue");
						small_shape2->setedge(edge2);
						small_shape2->setposx1(x1+edge2*3/2);
						small_shape2->setposy1(y1-edge2*sqrt(3)/2);
						small_shape2->setposx2(x2);
						small_shape2->setposy2(y2);
						small_shape2->setposx3(x3);
						small_shape2->setposy3(y3);
						small_shape2->add_total_area();
						small_shape2->add_total_perimeter();
						inners.push_back(small_shape2);
						countx++;
					}
					/* If triangle fitted , then next possible x coordinates */
					x1 += edge2;
				}
				/* Else increase x coordinates then checked again */
				/* Calculate new coordinate */
				else x1 += 1;
				x2 = x1+edge2;
				x3 = (x1+x2)/2;
			}
			/* Update new y coordinates */
			if(flag==1) y1 -= edge2*sqrt(3)/2;
			else y1 -= 1;
			county++;
		}

		/* Calculate area and shapes' number */
		area = M_PI * pow(radius,2) - countx*pow(edge2,2)*sqrt(3)/4;
		cout<<endl<<"---- Triangles in Circle ----"<<endl;
		cout<<"Container radius = "<<radius<<" - Inner edge = "<<edge2<<endl;
		cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";

	}
	
	/* Rectangles within A Triangle */
	void ComposedShape::OptimalFit(Triangle shape1, Rectangle shape2) noexcept
	{
		Triangle* conta = new Triangle(shape1.getedge(),shape1.getposx1(),shape1.getposy1(),shape1.getposx2(),shape1.getposy2(),shape1.getposx3(),shape1.getposy3(),"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double edge = shape1.getedge(), width2 = shape2.getwidth(), height2 = shape2.getheight();
		Rectangle small_shape;
		
		auto countx = 0, county = 0, countcolor=0;
		double posx;
		decltype(posx) posy, scroll, area=0;
		/* calculate scroll amount */
		scroll = height2 / sqrt(3);
		/* Determine cursor coordinate */
		posx = 0;
		posy = (edge/2)*sqrt(3);
	
		/* It places rectangles in the triangle from bottom to top. */
		while(posy-height2 >= 0)
		{
			county++;
			/* The position of x changes after each step. */
			posx = scroll*county;
			countcolor=0;
			/* It places rectangles in the triangle from x coordinate to new edge. */
			while( (posx+width2 <= edge-scroll*county) ) 
			{	
			/* Create new inner shape and send pointer of this shape to vector */
				Rectangle * small_shape = new Rectangle;
				small_shape->setname("rectangle");
				/* Choose different color */ 
				if(countcolor % 2 == 0) small_shape->setcolor("green");
				else small_shape->setcolor("yellow");
				/* Set values in small_shape then small_shape pushed in vector to keep */
				small_shape->setwidth(width2);
				small_shape->setheight(height2);
				small_shape->setposx(posx);
				small_shape->setposy(posy-height2);
				small_shape->add_total_area();
				small_shape->add_total_perimeter();
				inners.push_back(small_shape);
				countx++;
				countcolor++;
				/* Update new position of x. */
				posx += width2;
			}
			/* Update new position of y. */
			posy -= height2;
		}

		/* Calculate area and shapes' number */
		area = pow(edge,2)*sqrt(3)/4 - countx*width2*height2;
		cout<<endl<<"---- Rectangles in Triangle ----"<<endl;
		cout<<"Container edge = "<<edge<<" - Inner width = "<<width2<<" height = "<<height2<<endl;	
		cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";

	}
	
	/* Circles within A Triangle */
	void ComposedShape::OptimalFit(Triangle shape1, Circle shape2) noexcept
	{
		Triangle* conta = new Triangle(shape1.getedge(),shape1.getposx1(),shape1.getposy1(),shape1.getposx2(),shape1.getposy2(),shape1.getposx3(),shape1.getposy3(),"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double edge = shape1.getedge(), radius2 = shape2.getradius();
		Circle small_shape;
		
		double y2, h1=0, h2=0, h3=0, h=0, area;
		auto countx = 0;
		y2 = (edge/2)*sqrt(3);
		h = (edge/2)*sqrt(3);
		decltype(y2) posx = 0, posy = y2-radius2;
		auto flag=0;
		
		/* It places circles in the triangle from bottom to top. */
		while(posy-radius2 >= 0)
		{
			flag=0;
			posx = 0;
			while(posx+radius2 <= edge)
			{
				/* It controls the corners of the smallest square surrounding the circle. */
				if(posx <= edge/2) h1 = posx*sqrt(3);
				else h1 = (edge-posx)*sqrt(3);
				if(posx-radius2 <= edge/2) h2 = (posx-radius2)*sqrt(3);
				else h2 = (edge-posx+radius2)*sqrt(3);
				if(posx+radius2 <= edge/2) h3 = (posx+radius2)*sqrt(3);
				else h3 = (edge-posx-radius2)*sqrt(3);
				/* Calculates the coordinates of the corners and checks if they are inside. */
				if(h-(posy-radius2) <= h1 && h-(posy-radius2) <= h2 && h-(posy-radius2) <= h3)
				{
					/* Create new inner shape and send pointer of this shape to vector */
					Circle * small_shape = new Circle;
					small_shape->setname("circle");
					/* Set values in small_shape then small_shape pushed in vector to keep */
					small_shape->setcolor("green");
					small_shape->setcenterx(posx);
					small_shape->setcentery(posy);
					small_shape->setradius(radius2);
					small_shape->add_total_area();
					small_shape->add_total_perimeter();
					inners.push_back(small_shape);
					/* If circle fitted , then next possible x coordinates */
					posx += 2*radius2;
					flag=1;	
					countx++;
				}
				/* Else posx coordinate increase by 1 and check again */
				posx += 1;
			}
			/* If triangle fitted on x axis, then next possible y coordinates */
			if(flag==1)	posy -= 2*radius2;
			/* Else posy coordinate increase by 1 and check again */
			else posy -= 1;
		}
		
		/* Calculate area and shapes' number */
		area = pow(edge,2)*sqrt(3)/4 - countx*M_PI*pow(radius2,2);
		cout<<endl<<"---- Circles in Triangle ----"<<endl;
		cout<<"Container edge = "<<edge<<" - Inner radius = "<<radius2<<endl;	
		cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";

	}
	
	/* Triangles within A Triangle */
	void ComposedShape::OptimalFit(Triangle shape1, Triangle shape2) noexcept
	{
		Triangle* conta = new Triangle(shape1.getedge(),shape1.getposx1(),shape1.getposy1(),shape1.getposx2(),shape1.getposy2(),shape1.getposx3(),shape1.getposy3(),"red");
		inners.push_back(conta);
		/* Get container and inner shapes values. */
		double edge = shape1.getedge(), edge2 = shape2.getedge();
		Triangle small_shape;
		
		auto countx=0, county=0;
		double waste,area=0;
		/* Calculate height of big triangle */
		decltype(area) h = (edge/2)*sqrt(3);
		int num = edge / edge2;
		waste = (edge - num*edge2)/2;
		double posx = waste, posy = h;
		
		/* It should be 0 but -0.0001 the margin of error due to rounding in double calculations. */
		/* It places triangles in the triangle from bottom to top. */
		while(posy-edge2*sqrt(3)/2 >= -0.0001)
		{
			/* Add waste to center small shapes in the big triangle */
			posx = waste + edge2/2*county;
			/* It places triangles in the triangle from left to right. */
			while(posx+edge2 <= edge-edge2/2*county)
			{
				/* Create new inner shape and send pointer of this shape to vector */
				Triangle * small_shape = new Triangle;
				small_shape->setname("triangle");
				/* Set values in small_shape then small_shape pushed in vector to keep */
				small_shape->setcolor("green");
				small_shape->setedge(edge2);
				small_shape->setposx1(posx);
				small_shape->setposy1(posy);
				small_shape->setposx2(posx+edge2);
				small_shape->setposy2(posy);
				small_shape->setposx3(posx+edge2/2);
				small_shape->setposy3(posy-edge2/2*sqrt(3));
				small_shape->add_total_area();
				small_shape->add_total_perimeter();
				inners.push_back(small_shape);
				/* If possible, print the other triangle that rotated it 60 degrees alongside. Check corners and fit */
				if(posx+edge2*3/2 <= edge-edge2/2*county)
				{
					Triangle * small_shape2 = new Triangle;
					small_shape2->setname("triangle");
					/* Set values in small_shape then small_shape pushed in vector to keep */
					small_shape2->setcolor("yellow");
					small_shape2->setedge(edge2);
					small_shape2->setposx1(posx+edge2/2);
					small_shape2->setposy1(posy-edge2/2*sqrt(3));
					small_shape2->setposx2(posx+edge2*3/2);
					small_shape2->setposy2(posy-edge2/2*sqrt(3));
					small_shape2->setposx3(posx+edge2);
					small_shape2->setposy3(posy);
					small_shape2->add_total_area();
					small_shape2->add_total_perimeter();
					inners.push_back(small_shape2);
					countx++;	
				}
				/* Update new x location */
				countx++;
				posx += edge2;
			}
			/* Update new y location */
			posy -= edge2/2*sqrt(3);
			county++;
		}
		
		/* Calculate area and shapes' number */
		area = edge*edge*sqrt(3)/4 - countx*edge2*edge2*sqrt(3)/4;
		cout<<endl<<"---- Triangles in Triangle ----"<<endl;
		cout<<"Container edge = "<<edge<<" - Inner edge = "<<edge2<<endl;
		cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";

	}
	
	/* Getter for container shapes */
	Rectangle ComposedShape::get_r_container() const noexcept
	{
		return r_container;
	}
	
	Circle ComposedShape::get_c_container() const noexcept
	{
		return c_container;
	}
	
	Triangle ComposedShape::get_t_container() const noexcept
	{
		return t_container;
	}
	
	/* Getter for inner shapes */
	Rectangle ComposedShape::get_r_inner() const noexcept
	{
		return r_inner;
	}
	
	Circle ComposedShape::get_c_inner() const noexcept
	{
		return c_inner;
	}
	Triangle ComposedShape::get_t_inner() const noexcept
	{
		return t_inner;
	}
	
	/* Getter vector */
	vector<Shape*> ComposedShape::get_inners() const noexcept
	{
		return inners;
	}
	
	
	Shape& ComposedShape::operator [](int index) throw(out_of_range&)
	{
		try 
		{
			inners.at(index);      // vector::at throws an out-of-range
		}
		catch (const std::out_of_range& oor)
		{
			std::cerr << "Out of Range error: " << oor.what() << '\n';
			return (*inners[0]);
		}
		return (*inners[index]);
	}
	
	const Shape& ComposedShape::operator [](int index) const throw(out_of_range&)
	{
		try 
		{
			inners.at(index);      // vector::at throws an out-of-range
		}
		catch (const std::out_of_range& oor)
		{
			std::cerr << "Out of Range error: " << oor.what() << '\n';
			return (*inners[0]);
		}
		return (*inners[index]);
	}
	
	Shape& ComposedShape::operator +=(Shape &shape) noexcept
	{
 		inners.push_back(&shape);
  		return shape;
 	}
 	
 	
 	void ComposedShape::print(ostream& os) noexcept
	{  
		Rectangle* rec;
   		Circle* cir;
   		Triangle* tri;
		for(Shape* x: inners)
		{
			if(dynamic_cast < Rectangle* > (x) != nullptr)
			{	
				rec = dynamic_cast < Rectangle* > (x);
				(*rec).print(os);
			}
			else if(dynamic_cast < Circle* > (x) != nullptr)
			{	
				cir = dynamic_cast < Circle* > (x);
				(*cir).print(os);	
			}
			else if(dynamic_cast < Triangle* > (x) != nullptr)
			{	
				tri = dynamic_cast < Triangle* > (x);
				(*tri).print(os);
			}
		}
	}
	
	double ComposedShape::area() const noexcept
	{
		return area_;
	}
	double ComposedShape::perimeter() const noexcept
	{
		return perimeter_;
	}
	void ComposedShape::set_area(double x) noexcept
	{
		area_ = x;
	}
	void ComposedShape::set_perimeter(double x) noexcept
	{
		perimeter_ = x;
	}
	
	ComposedShape& ComposedShape::operator++() noexcept
	{
		for(Shape* x: inners)
		{
			if(dynamic_cast < Rectangle* > (x) != nullptr)
			{	
				++(*(dynamic_cast < Rectangle* > (x)));
			}
			else if(dynamic_cast < Circle* > (x) != nullptr)
			{	
				++(*(dynamic_cast < Circle* > (x)));
			}
			else if(dynamic_cast < Triangle* > (x) != nullptr)
			{	
				++(*(dynamic_cast < Triangle* > (x)));
			}
		}
		return (*this);
	}
	ComposedShape& ComposedShape::operator++(int) noexcept
	{
		ComposedShape shape_temp = (*this);
		ComposedShape* ptr_st = &shape_temp;
		for(Shape* x: inners)
		{
			if(dynamic_cast < Rectangle* > (x) != nullptr)
			{	
				++(*(dynamic_cast < Rectangle* > (x)));
			}
			else if(dynamic_cast < Circle* > (x) != nullptr)
			{	
				++(*(dynamic_cast < Circle* > (x)));
			}
			else if(dynamic_cast < Triangle* > (x) != nullptr)
			{	
				++(*(dynamic_cast < Triangle* > (x)));
			}
		}
		return (*ptr_st);
	}
	ComposedShape& ComposedShape::operator--() noexcept
	{	
		for(Shape* x: inners)
		{
			if(dynamic_cast < Rectangle* > (x) != nullptr)
			{	
				--(*(dynamic_cast < Rectangle* > (x)));
			}
			else if(dynamic_cast < Circle* > (x) != nullptr)
			{	
				--(*(dynamic_cast < Circle* > (x)));
			}
			else if(dynamic_cast < Triangle* > (x) != nullptr)
			{	
				--(*(dynamic_cast < Triangle* > (x)));
			}
		}
		return (*this);
	}
	ComposedShape& ComposedShape::operator--(int) noexcept
	{
		ComposedShape shape_temp = (*this);
		ComposedShape* ptr_st = &shape_temp;
		for(Shape* x: inners)
		{
			if(dynamic_cast < Rectangle* > (x) != nullptr)
			{	
				--(*(dynamic_cast < Rectangle* > (x)));
			}
			else if(dynamic_cast < Circle* > (x) != nullptr)
			{	
				--(*(dynamic_cast < Circle* > (x)));
			}
			else if(dynamic_cast < Triangle* > (x) != nullptr)
			{	
				--(*(dynamic_cast < Triangle* > (x)));
			}
		}
		return (*ptr_st);	
	}

}
	
	

