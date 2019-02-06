#include <iostream>
#include"source1.h"

using namespace std;

int main()
{
	/* Create variable to keep container shape */
	Shapes container;
	char shape;
	int width, height, radius, edge, flag;
	do
	{
		flag = 0;
		/* Get shape's character for container from user */
		cout<<"Please enter the main container shape (R, C, T)"<<endl;
		cin>>shape;
		/* Match user entire charachter and container shape */
		if(shape == 'R' || shape == 'r')	container = Shapes::rectangle;
		else if(shape == 'C' || shape == 'c') container = Shapes::circle;
		else if(shape == 'T' || shape == 't') container = Shapes::triangle;
		else{
			cout<<"You entered the wrong character. "<<endl;
			flag = -1;
		}	
	}while(flag == -1);
	
	/* Get container shape's features */
	switch(container)
	{
		case Shapes::rectangle:
			cout<<"Please enter the width"<<endl;
			cin>>width;
			cout<<"Please enter the height"<<endl;
			cin>>height;
			break;
		case Shapes::circle:
			cout<<"Please enter the radius"<<endl;
			cin>>radius;
			break;
		case Shapes::triangle:
			cout<<"Please enter the edge"<<endl;
			cin>>edge;
			break;
	}
	
	/* Create variable to keep small shape */
	Shapes small_shape;
	do
	{
		flag = 0;
		cout<<"Please enter the small shape (R, C, T)"<<endl;
		/* Get shape's character for container from user */
		cin>>shape;
		/* Match user entire charachter and container shape */
		if(shape == 'R' || shape == 'r')	small_shape = Shapes::rectangle;
		else if(shape == 'C' || shape == 'c') small_shape = Shapes::circle;
		else if(shape == 'T' || shape == 't') small_shape = Shapes::triangle;
		else{
			cout<<"You entered the wrong character. "<<endl;
			flag = -1;
		}
	}while(flag == -1);
	
	int width2, height2, radius2, edge2;
	
	/* Get small shape's features */
	switch(small_shape)
	{
		case Shapes::rectangle:
			cout<<"Please enter the width"<<endl;
			cin>>width2;
			cout<<"Please enter the height"<<endl;
			cin>>height2;
			break;
		case Shapes::circle:
			cout<<"Please enter the radius"<<endl;
			cin>>radius2;
			break;
		case Shapes::triangle:
			cout<<"Please enter the edge"<<endl;
			cin>>edge2;
			break;
	}
	

	/* Call the correct function */
	if(container == Shapes::rectangle)
	{
		if(small_shape == Shapes::rectangle)		rec_rec(width, height, width2, height2);
		else if(small_shape == Shapes::circle)		rec_cir(width, height, radius2);
		else if(small_shape == Shapes::triangle)	rec_tri(width, height, edge2);
	}
	else if(container == Shapes::circle)
	{
		if(small_shape == Shapes::rectangle)		cir_rec(radius, width2, height2);
		else if(small_shape == Shapes::circle)		cir_cir(radius, radius2);
		else if(small_shape == Shapes::triangle)	cir_tri(radius, edge2);
	}
	else if(container == Shapes::triangle)
	{
		if(small_shape == Shapes::rectangle)		tri_rec(edge, width2, height2);
		else if(small_shape == Shapes::circle)		tri_cir(edge, radius2);
		else if(small_shape == Shapes::triangle)	tri_tri(edge, edge2);
	}

	return 0;
}
