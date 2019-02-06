#include <iostream>
#include <fstream>
#include <cmath>
#include "source1.h"

# define M_PI		3.14159265358979323846

using namespace std;


/* Rectangles within A Rectangle */
int rec_rec(double width, double height, double width2, double height2)
{
	string color;		/* Shapes color */
	int pos1, pos2, temp, x=0 ,y=0;
	/* pos1 and pos2 => To calculate possibility to rotate, x and y => to keep coordinate */
	int tempx, tempy, count_x=0, count_y=0;
	/* tempx and tempy keep coordinate, count_x keep numbers of shapes that fit horizontally, count_y keep numbers of shapes that fit vertically, temp_count keep numbers of shapes fitted in big rectangle */
	double area = 0;		/* Total area of placed shapes */

	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	pos1 = (width / width2) * (height / height2);		/* If we place rectangles as user enters */
	pos2 = (width / height2) * (height / width2);		/* If we place rectangles as rotate 90 degrees */
	
	/* Compared to which one can have more shapes*/
	if(pos2 > pos1)		/* Rotate 90 degrees and fit in big Rectangle */
	{
		temp = width2;
		width2 = height2;
		height2 = temp;
	}
	
	/* Print big rectangle */
	file<<"<svg version=\"1.1\" baseProfile=\"full\" width=\""<<width<<"\" height=\""<<height<<"\" xmlns=\"http://www.w3.org/2000/svg\"> <rect width=\"100%\" height=\"100%\" fill=\"red\" />\n";
	
	/* Small shapes will be placed upwards from the bottom of the large rectangle. */
	while(height - y >= height2)
	{
		x=0; /* Started point is 0 for x axis */
		/* Small shapes will be placed from the left of the large rectangle to the right. */
		while(width - x >= width2)
		{
			/* For different colors */
			if(count_x % 3 == 0) color = "green";
			else if(count_x % 3 == 1) color = "yellow";
			else color = "pink";
			/* print small shapes */
			file<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<width2<<"\" height=\""<<height2<<"\" fill=\""<<color<<"\" />\n";
			/* Next possible coordinate */
			x += width2;
			count_x++;
		}
		/* Next possible coordinate */
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
			if(count_x % 3 == 0) color = "green";
			else if(count_x % 3 == 1) color = "yellow";
			else color = "pink";
			file<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<height2<<"\" height=\""<<width2<<"\" fill=\""<<color<<"\" />\n";
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
			if(count_x % 3 == 0) color = "green";
			else if(count_x % 3 == 1) color = "yellow";
			else color = "pink";
			file<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<height2<<"\" height=\""<<width2<<"\" fill=\""<<color<<"\" />\n";
			x += height2;
			count_x++;
		}
		y += width2;
		count_y++;
	} 
	
	file<<"</svg>";
	
	/* Calculate area and shapes' number */
	area = (width*height)-(width2*height2*count_x);
	
	cout<<"I can fit at most "<<count_x<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	
	/* Close file */
	file.close();
	
	return 0;
}

/* Circles within A Rectangle */
int rec_cir(double width, double height, double radius2)
{
	int numx=0, numy=0, countx=0, county=0, tempx, tempy, temp;
	/* numx =>  Number of horizontally fits , numy =>  Number of vertically fits, countx keep fitted shapes, county keep step of vertically */
	double wastex, wastey, area;
	/* wastex and wastey keep free places */
	
	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	/* Calculate how many shapes by horizontal and vertical  will be placed. */
	numx = temp = width / (2*radius2);
	numy = height / (2*radius2);
	
	/*It can center the small shapes by sharing the free places equally.*/
	wastex = (width - numx * radius2 * 2) / 2;
	wastey = (height - numy * radius2 * 2) / 2;
	
	/* Print big rectangle */
	file<<"<svg version=\"1.1\" baseProfile=\"full\" width=\""<<width<<"\" height=\""<<height<<"\" xmlns=\"http://www.w3.org/2000/svg\"> <rect width=\"100%\" height=\"100%\" fill=\"red\" />\n";
	
	while(numy > 0)
	{
		/* Calculate y coordinate */
		tempy = radius2 + county * radius2 * 2;
		countx = 0;
		numx = temp;	/* Started point for x axis */
		while(numx > 0)
		{
			/* Calculate x coordinate */
			tempx = radius2 + countx * radius2 * 2;
			/* Fits circles in rectangle */
			file<<"\t<circle cx=\""<<wastex+tempx<<"\" cy=\""<<wastey+tempy<<"\" r=\""<<radius2<<"\" fill=\"green\"/>\n";
			countx++;
			numx--;
		}
		county++;
		numy--;
	}

	
	file<<"</svg>";
	
	/* Calculate area and shapes' number */
	area = (width * height) - ((M_PI*radius2*radius2)*(countx*county));
	
	cout<<"I can fit at most "<<countx*county<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	
	/* Close file */
	file.close();
	
	return 0;
}

/* Triangles within A Rectangle */
int rec_tri(double width, double height, double edge2)
{
	/* Vertical and horizantal counter and sum of shapes' number */
	int countx=0, county=0, sum=0;
	/* Coordinate of triangles */
	double x1, x2, x3, y1, y2, y3;
	double tempx, tempy, area;
	/* numx =>  Number of horizontally fits , numy =>  Number of vertically fits */
	int i, j, temp_counter = 0, numx, numy, temp;
	
	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	/* Print rectangle */
	file<<"<svg version=\"1.1\" baseProfile=\"full\" width=\""<<width<<"\" height=\""<<height<<"\" xmlns=\"http://www.w3.org/2000/svg\"> <rect width=\"100%\" height=\"100%\" fill=\"red\" />\n";
	
	/* Calculate to fit shapes by possible horizontal and vertical. */ 
	numx = width / edge2;
	numy = height / (edge2*sqrt(3)/2);
	temp = numx;
	/* Points of the triangle */
	x1 = 0;
	y1 = 0;
	x2 = edge2;
	y2 = 0;
	x3 = edge2/2;
	y3 = edge2/2*sqrt(3);
	
	i = numy;
	j = numx;
	
	/* The triangles are placed with the base at the bottom. */
	while(i>0)
	{
		j = temp;
		tempy = county*edge2*sqrt(3)/2;		/* Calculate y coordinate */
		temp_counter = 0;
		while(j>0)
		{
			tempx = temp_counter*edge2;		/* Calculate x coordinate */
			file<<"\t<polygon points=\""<<x1+tempx<<" "<<y1+tempy<<" "<<x2+tempx<<" "<<y2+tempy<<" "<<x3+tempx<<" "<<y3+tempy<<"\" fill=\"yellow\"/>"<<endl;
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
			tempx = temp_counter*edge2;			/* Calculate x coordinate */
			file<<"\t<polygon points=\""<<x1+tempx<<" "<<y1+tempy<<" "<<x2+tempx<<" "<<y2+tempy<<" "<<x3+tempx<<" "<<y3+tempy<<"\" fill=\"green\"/>"<<endl;
			j--;
			countx++;
			temp_counter++;
		}
		county++;
		i--;	
	}

	file<<"</svg>";
	
	/* Calculate area and shapes' number */
	sum += countx;
	area = (width*height)- sum * (pow(edge2,2)*sqrt(3)/4);
	
	cout<<"I can fit at most "<<sum<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	
	/* Close file */
	file.close();
	
	return 0;
}

/* Rectangles within A Circle ?*/
int cir_rec(double radius, double width2, double height2)
{
	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	int countx=0, county=0, flag=0;
	/* Variables to define center coordinate */
	double x, y, area;
	/* Start to fit on x=0 and y=0 */
	x = 0;
	y = 0;
	/* Print circle */
	file<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> <circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius<<"\" fill=\"red\"/>\n";
	
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
				/* print rectangles */
				file<<"\t<rect x=\""<<x+0.5<<"\" y=\""<<y+0.5<<"\" width=\""<<width2<<"\" height=\""<<height2<<"\" fill=\"green\" stroke-width=\"0.5\" stroke=\"blue\" />\n";
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
	
	file<<"</svg>";
	
	/* Calculate area and shapes' number */
	area = M_PI * pow(radius,2) - countx*width2*height2;
	
	cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	
	/* Close file */
	file.close();
	
	return 0;
}

/* Circles within A Circle ?*/
int cir_cir(double radius, double radius2)
{
	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	int countx=0, county=0 , flag=0;
	double x=0,y=0,area=0;
	
	/* Print circle */
	file<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> <circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius<<"\" fill=\"red\"/>\n";
	
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
				/* print small circle in file */
				file<<"\t<circle cx=\""<<x+radius2<<"\" cy=\""<<y+radius2<<"\" r=\""<<radius2<<"\" fill=\"green\"/>\n";
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
	
	file<<"</svg>";
	
	/* Calculate area and shapes' number */
	area = M_PI * pow(radius,2) - countx*M_PI * pow(radius2,2);
	
	cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	
	/* Close file */
	file.close();
	
	return 0;
}

/* Triangles within A Circle */
int cir_tri(double radius, double edge2)
{
	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	int countx=0, county=0, flag=0;
	double x1, x2, x3, y1, y2, y3, area=0;		/* Coordinate of triangles */
	/* Calculate triangles coordinate */
	x1 = 0;
	y1 = 2*radius;
	x2 = x1+edge2;
	y2 = y1;
	x3 = (x1+x2)/2;
	y3 = y1-edge2*sqrt(3)/2;
	
	/* Print circle in file */
	file<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> <circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius<<"\" fill=\"red\"/>\n";
	
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
				file<<"\t<polygon points=\""<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<"\" fill=\"green\"/>\n";
				countx++;
				flag=1;
				/* If possible, print the other triangle that rotated it 60 degrees alongside. Check with circle equation */
				if((pow(radius-x1-edge2*3/2,2) + pow(radius-y1+edge2*sqrt(3)/2,2) <= pow(radius,2)) && (pow(radius-x2,2) + pow(radius-y2,2) <= pow(radius,2)) && (pow(radius-x3,2) + pow(radius-y3,2) <= pow(radius,2)))
				{
					file<<"\t<polygon points=\""<<x1+edge2*3/2<<" "<<y1-edge2*sqrt(3)/2<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<"\" fill=\"blue\"/>\n";
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
	
	file<<"</svg>";
	
	/* Calculate area and shapes' number */
	
	area = M_PI * pow(radius,2) - countx*pow(edge2,2)*sqrt(3)/4;
	
	cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";

	/* Close file */
	file.close();

	return 0;
}

/* Rectangles within A Triangle */
int tri_rec(double edge, double width2, double height2)
{
	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	string color;		/* To make different colors for shapes */
	int countx = 0, county = 0, countcolor=0;
	/* Triangles corner points, posx and posy cursor location, scroll is Scroll amount */
	double x1, x2, x3, y1, y2, y3, posx, posy, scroll, area;
	/* Calculate triangle's corners coordinate */
	x1 = edge / 2;
	y1 = 0;
	x2 = 0;
	y2 = (edge/2)*sqrt(3);
	x3 = edge;
	y3 = (edge/2)*sqrt(3);
	/* calculate scroll amount */
	scroll = height2 / sqrt(3);
	/* Determine cursor coordinate */
	posx = 0;
	posy = (edge/2)*sqrt(3);

	/* Print triangle in file */
	file<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> <polygon points=\""<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<"\" fill=\"red\"/>\n";
	
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
			if(countcolor % 2 == 0) color = "green";
			else color = "yellow";
			/* print rectangles */
			file<<"\t<rect x=\""<<posx<<"\" y=\""<<posy-height2<<"\" width=\""<<width2<<"\" height=\""<<height2<<"\" fill=\""<<color<<"\" />\n";
			countx++;
			countcolor++;
			/* Update new position of x. */
			posx += width2;
		}
		/* Update new position of y. */
		posy -= height2;
	}

	file<<"</svg>";
	
	
	/* Calculate area and shapes' number */
	
	area = pow(edge,2)*sqrt(3)/4 - countx*width2*height2;
	
	cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	
	/* Close file */
	file.close();
	
	return 0;
}

/* Circles within A Triangle */
int tri_cir(double edge, double radius2)
{
	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	double x1, x2, x3, y1, y2, y3, h1=0, h2=0, h3=0, h=0, area;
	int countx = 0;
	/* Determine triangle's corner coordinate */
	x1 = edge / 2;
	y1 = 0;
	x2 = 0;
	y2 = (edge/2)*sqrt(3);
	x3 = edge;
	y3 = (edge/2)*sqrt(3);
	h = (edge/2)*sqrt(3);
	double posx = 0, posy = y2-radius2;
	int flag=0;
	
	/* Print Triangle */
	file<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> <polygon points=\""<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<"\" fill=\"red\"/>\n";

	/* It places circles in the triangle from bottom to top. */
	while(posy-radius2 >= 0)
	{
		flag=0;
		posx = 0;
		/* It places circles in the triangle from left to right. */
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
				file<<"\t<circle cx=\""<<posx<<"\" cy=\""<<posy<<"\" r=\""<<radius2<<"\" fill=\"green\"/>\n";
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
	
	file<<"</svg>";
	
	/* Calculate area and shapes' number */
	
	area = pow(edge,2)*sqrt(3)/4 - countx*M_PI*pow(radius2,2);
	
	cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	
	/* Close file */
	file.close();
	
	return 0;
}

/* Triangles within A Triangle */
int tri_tri(double edge, double edge2)
{
	ofstream file;
	/* Open .svg file */
	file.open("output.svg");
	
	int countx=0, county=0;
	/* Determine coordinates of triangle's corners */
	double x1, x2, x3, y1, y2, y3,waste,area=0;
	x1 = edge / 2;
	y1 = 0;
	x2 = 0;
	y2 = (edge/2)*sqrt(3);
	x3 = edge;
	y3 = (edge/2)*sqrt(3);
	/* Calculate height of big triangle */
	double h = (edge/2)*sqrt(3);
	int num = edge / edge2;
	waste = (edge - num*edge2)/2;
	double posx = waste, posy = h;
	/* Print big triangle */
	file<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> <polygon points=\""<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<"\" fill=\"red\"/>\n";
	
	/* It should be 0 but -0.0001 the margin of error due to rounding in double calculations. */
	/* It places triangles in the triangle from bottom to top. */
	while(posy-edge2*sqrt(3)/2 >= -0.0001)
	{
		/* Add waste to center small shapes in the big triangle */
		posx = waste + edge2/2*county;
		/* It places triangles in the triangle from left to right. */
		while(posx+edge2 <= edge-edge2/2*county)
		{
			file<<"\t<polygon points=\""<<posx<<" "<<posy<<" "<<posx+edge2<<" "<<posy<<" "<<posx+edge2/2<<" "<<posy-edge2/2*sqrt(3)<<" "<<"\" fill=\"green\"/>\n";
			/* If possible, print the other triangle that rotated it 60 degrees alongside. Check corners and fit */
			if(posx+edge2*3/2 <= edge-edge2/2*county)
			{
				file<<"\t<polygon points=\""<<posx+edge2/2<<" "<<posy-edge2/2*sqrt(3)<<" "<<posx+edge2*3/2<<" "<<posy-edge2/2*sqrt(3)<<" "<<posx+edge2<<" "<<posy<<" "<<"\" fill=\"yellow\"/>\n";
				countx++;	
			}
			
			countx++;
			/* Update new x location */
			posx += edge2;
		}
		/* Update new y location */
		posy -= edge2/2*sqrt(3);
		county++;
	}
	
	file<<"</svg>";
	
	/* Calculate area and shapes' number */
	area = edge*edge*sqrt(3)/4 - countx*edge2*edge2*sqrt(3)/4;
	
	cout<<"I can fit at most "<<countx<<" small shapes into the main container. The empty area (red) in container is "<<area<<" . \n";
	
	/* Close file */
	file.close();
	
	return 0;
}
