/*
	FURKAN OZEV
	161044036
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "composedshape.h"
#include "polygon.h"
#include "polyline.h"

using namespace std;
using mycomposedshape::ComposedShape;	// Using mycomposedshape namespace
using mypolygon::Polygon;				// Using mypolygon namespace
using mypolyline::Polyline;				// Using mypolyline namespace

/* unnamed namespace */
namespace {
   int i;
   int flag = 0, flag2 = 0;
}

int main()
{
cout<<"------------   DRIVER   ------------\n";
	ofstream file;
	/*  Driver make 5 objects of each class and should make array of objects of each class. */ 
	/* I used different value when creating objects. */
	Rectangle 	Rectangles[5] = {{500,400},{450,500},{30,40},{50,40},{540,470}};
	Circle	 	Circles[5] = {{300},{350},{20},{30},{345}};
	Triangle 	Triangles[5] = {{600},{500},{60},{20},{760}};

	/* Create vector to operate constructors that take vector. Firstly create array then data copy into vector */
	Polygon::Point2D rec_arr[4] = {{40.0,50.0}, {450.0,50.0}, {450.0,470.0}, {40.0,470.0}};
	Polygon::Point2D tri_arr[3] = {{280.0,50.0}, {40.0,465.692194}, {520.0,465.692194}};
	vector<Polygon::Point2D> vec1, vec2;
	for(i=0; i<4; i++)
	{
		vec1.push_back(rec_arr[i]);
	}
	for(i=0; i<3; i++)
	{
		vec2.push_back(tri_arr[i]);
	}
	
	/* Polygon array 4 different constructor will operate and tested. */
	Polygon Shapes_Polygon[5] = {{Rectangles[4]}, {Circles[4]}, {Triangles[4]}, {vec1}, {vec2}};
	/* Polyline array 4 different constructor will operate and tested. */
	Polyline Shapes_Polyline[5] = {{Rectangles[4]}, {Circles[4]}, {Triangles[4]}, {vec1}, {vec2}};
	
	/* Different 9 combination. */
	/* Test all ComposedShape's function and create differen 9 svg file */
	
	/* ComposedShape array 3 different constructor will operate and tested. */
	ComposedShape Shapes[9] = {{Rectangles[0], Rectangles[2]}, {Rectangles[1], Circles[3]},
							   {Rectangles[0], Triangles[3]}, {Circles[1], Rectangles[2]},
							   {Circles[0], Circles[3]}, {Circles[1], Triangles[2]},
							   {Triangles[0], Rectangles[3]}, {Triangles[0], Circles[2]},
							   {Triangles[1], Triangles[3]}};
	 	
	/* 9 Combination test and print result in svg file */
	Shapes[0].OptimalFit(Shapes[0].get_r_container(), Shapes[0].get_r_inner());
	Shapes[0].fileopen("rec_in_rec.svg");
	cout<<Shapes[0];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[0].fileclose();
	
	
	Shapes[1].OptimalFit(Shapes[1].get_r_container(), Shapes[1].get_c_inner());
	Shapes[1].fileopen("cir_in_rec.svg");
	cout<<Shapes[1];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[1].fileclose();

	Shapes[2].OptimalFit(Shapes[2].get_r_container(), Shapes[2].get_t_inner());
	Shapes[2].fileopen("tri_in_rec.svg");
	cout<<Shapes[2];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[2].fileclose();

	Shapes[3].OptimalFit(Shapes[3].get_c_container(), Shapes[3].get_r_inner());
	Shapes[3].fileopen("rec_in_cir.svg");
	cout<<Shapes[3];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[3].fileclose();

	Shapes[4].OptimalFit(Shapes[4].get_c_container(), Shapes[4].get_c_inner());
	Shapes[4].fileopen("cir_in_cir.svg");
	cout<<Shapes[4];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[4].fileclose();

	Shapes[5].OptimalFit(Shapes[5].get_c_container(), Shapes[5].get_t_inner());
	Shapes[5].fileopen("tri_in_cir.svg");
	cout<<Shapes[5];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[5].fileclose();

	Shapes[6].OptimalFit(Shapes[6].get_t_container(), Shapes[6].get_r_inner());
	Shapes[6].fileopen("rec_in_tri.svg");
	cout<<Shapes[6];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[6].fileclose();

	Shapes[7].OptimalFit(Shapes[7].get_t_container(), Shapes[7].get_c_inner());
	Shapes[7].fileopen("cir_in_tri.svg");
	cout<<Shapes[7];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[7].fileclose();

	Shapes[8].OptimalFit(Shapes[8].get_t_container(), Shapes[8].get_t_inner());
	Shapes[8].fileopen("tri_in_tri.svg");
	cout<<Shapes[8];		// Overloaded operator<< function os<< <ComposedShape> 
	Shapes[8].fileclose();
	
	cout<<"\n 9 different combinations (ComposedShape objects) were printed on 9 different files. \n";
	
	/* 5 polygon objects print in polygon svg files */
	/* Polygon '<<' operator is tested. */
	cout<<"\n Polygon 1 Rectangle width = 540, height = 470. ";
	file.open("polygon_1.svg");
	file<<Shapes_Polygon[0];
	file.close();
	
	cout<<"\n Polygon 2 Circle radius = 345. ";
	file.open("polygon_2.svg");
	file<<Shapes_Polygon[1];
	file.close();
	
	cout<<"\n Polygon 3 Triangle radius = 760. ";
	file.open("polygon_3.svg");
	file<<Shapes_Polygon[2];
	file.close();
	
	cout<<"\n Polygon 4 Rectangle vector points = {40.0,50.0}, {450.0,50.0}, {450.0,470.0}, {40.0,470.0} .";
	file.open("polygon_4.svg");
	file<<Shapes_Polygon[3];
	file.close();
	
	cout<<"\n Polygon 5 Triangle vector points = {{280.0,50.0}, {40.0,465.692194}, {520.0,465.692194} .";
	file.open("polygon_5.svg");
	file<<Shapes_Polygon[4];
	file.close();
	
	cout<<"\n 5 different polygons were printed on 5 different files as polygon_number. \n";
	
	/* 5 polyline objects print in polyline svg files */
	/* Polyline '<<' operator is tested. */
	cout<<"\n Polygon 1 Rectangle width = 540, height = 470. ";
	file.open("polyline_1.svg");
	file<<Shapes_Polyline[0];
	file.close();
	
	cout<<"\n Polyline 2 Circle radius = 345. ";
	file.open("polyline_2.svg");
	file<<Shapes_Polyline[1];
	file.close();
	
	cout<<"\n Polyline 3 Triangle radius = 760. ";
	file.open("polyline_3.svg");
	file<<Shapes_Polyline[2];
	file.close();
	
	cout<<"\n Polyline 4 Rectangle vector points = {40.0,50.0}, {450.0,50.0}, {450.0,470.0}, {40.0,470.0} .";
	file.open("polyline_4.svg");
	file<<Shapes_Polyline[3];
	file.close();
	
	cout<<"\n Polyline 5 Triangle vector points = {{280.0,50.0}, {40.0,465.692194}, {520.0,465.692194} .";
	file.open("polyline_5.svg");
	file<<Shapes_Polyline[4];
	file.close();
	
	cout<<"\n 5 different polylines were printed on 5 different files as polylines_number. \n";
	
	/* These tests are designed to show that the functions are working correctly. There is no output except success or fault. */
	/* There are some checks in test part. */
	/* Test Composed Shape functions */
	cout<<"\n\n ----- Test of ComposedShape functions that are '+=' and '[]' ----- ";
	double w=77, h = 87;
	int test_size = Shapes[0].get_vector().size();		// Keep first object's size
	cout<<"\n Current size: "<<test_size;
	Polygon::Point2D test_point{w,h};		// Create new Point2D object and tested Point2D constructor.
	cout<<"\n Add Point2D object with '+=' => width = "<<w<<" height = "<<h;
	Shapes[0] += test_point;		// Add to Shapes and tested '+=' operator.
	int test_newsize = Shapes[0].get_vector().size();		// Keep new object's size
	cout<<"\n New size: "<<test_newsize;
	cout<<"\n Show added object("<<test_newsize<<".object) properties with '[]' => width= "<<Shapes[0][test_newsize-1][0].getx()<<" height= "<<Shapes[0][test_newsize-1][0].gety();
	// If old object coordinate and coordinate of the last element of the vector is same, test will be success. Else will be fault. 
	if(w == Shapes[0][test_newsize-1][0].getx() && h == Shapes[0][test_newsize-1][0].gety())
	cout<<"\n Test successful";
	else cout<<"\n Test fault";
	
	
	cout<<"\n\n ----- Test of Polygon functions that are '[]' , '==' , '!=' , '+' '=' , copy constructor and constructors ----- \n";
	
	Polygon polygon_test1 = Shapes_Polygon[0] + Shapes_Polygon[1];		//  '+' and copy constructor are tested.
	/* Check Size */
	cout<<"\n -- Test of copy constructor and '+' operator. -- ";
	if(Shapes_Polygon[0].get_size() + Shapes_Polygon[1].get_size() == polygon_test1.get_size()) cout<<"\n Test successful";
	else cout<<"\n Test fault";
	cout<<endl;
	
	cout<<"\n -- Test of assigment '=' operator. -- ";
	Polygon polygon_test2, polygon_test3;		//  default constructor is tested.
	polygon_test2 = Shapes_Polygon[1];			//  assigment '=' operator is tested.
	/* Check Sizes */
	if(Shapes_Polygon[1].get_size() == polygon_test2.get_size()) cout<<"\n Test successful";
	else cout<<"\n Test fault";
	
	/* Assigment '=' and '+' operator are tested. */
	polygon_test3 = Shapes_Polygon[0] + polygon_test2;
	cout<<endl;
	
	cout<<"\n -- Test of assigment '==' and '!=' operator. -- ";
	/* Assigment '==' and '!=' operator are tested. */
	if(polygon_test1 == polygon_test3)	flag = 1;
	else flag = -1;
	if(polygon_test1 != polygon_test2)	flag2 = 1;
	else	flag2 = -1;
	
	if(flag == 1 && flag2 == 1)		cout<<"\n Test successful";
	else cout<<"\n Test fault";
	cout<<endl;
	
	cout<<"\n -- Test of index '[]' operator and constructor(Point2D). -- ";
	Polygon::Point2D test_point2(30,40);		// Point2D constructor is tested.
	Polygon polygon_test4(test_point2);			// Constructor that take Point2D object is tested.
	/* Index operator is tested */
	if(polygon_test4[0].getx() == test_point2.getx() && polygon_test4[0].gety() == test_point2.gety())
	{	cout<<"\n Test successful"; }
	else cout<<"\n Test fault";
	
	
	cout<<"\n\n ----- Test of Polyline functions that are '[]' , '==' , '!=' , '+' '=' , copy constructor and constructors ----- \n";
	flag = 0, flag2 = 0;
	
	Polyline polyline_test1 = Shapes_Polyline[0] + Shapes_Polyline[1];		//  '+' and copy constructor are tested.
	cout<<"\n -- Test of copy constructor and '+' operator. -- ";
	/* Check Size */
	if(Shapes_Polyline[0].get_size() + Shapes_Polyline[1].get_size() == polyline_test1.get_size()) cout<<"\n Test successful";
	else cout<<"\n Test fault";
	cout<<endl;
	
	cout<<"\n -- Test of assigment '=' operator. -- ";
	Polyline polyline_test2, polyline_test3;			//  default constructor is tested.
	polyline_test2 = Shapes_Polyline[1];				//  assigment '=' operator is tested.
	if(Shapes_Polyline[1].get_size() == polyline_test2.get_size()) cout<<"\n Test successful";
	else cout<<"\n Test fault";
	
	/* Assigment '=' and '+' operator are tested. */
	polyline_test3 = Shapes_Polyline[0] + polyline_test2;
	cout<<endl;
	
	cout<<"\n -- Test of assigment '==' and '!=' operator. -- ";
	/* Assigment '==' and '!=' operator are tested. */
	if(polyline_test1 == polyline_test3)	flag = 1;
	else flag = -1;
	if(polyline_test1 != polyline_test2)	flag2 = 1;
	else	flag2 = -1;
	
	if(flag == 1 && flag2 == 1)		cout<<"\n Test successful";
	else cout<<"\n Test fault";
	cout<<endl;
	
	cout<<"\n -- Test of index '[]' operator and constructor(Point2D). -- ";
	Polygon::Point2D test_point3(50,60);		// Point2D constructor is tested.
	Polyline polyline_test4(test_point3);		// Constructor that take Point2D object is tested.
	/* Index operator is tested */
	if(polyline_test4[0].getx() == test_point3.getx() && polyline_test4[0].gety() == test_point3.gety())
	{	cout<<"\n Test successful"; }
	else cout<<"\n Test fault";
	cout<<endl;

	return 0;
}
	

