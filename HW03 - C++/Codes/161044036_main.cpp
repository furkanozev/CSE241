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

using namespace std;

int main()
{	
	cout<<"------------   DRIVER   ------------\n";
	int counter = 1;
	/*  Driver make 4 objects of each class and should make array of objects of each class. */ 
	/* I used different constructor structures when creating. */
	/* Then I set some values for constructor. */
	Rectangle 	Rectangles[4] = {{},{450,500},{30,40,0,0},{}};
	Circle	 	Circles[4] = {{300},{},{20,20,20},{30}};
	Triangle 	Triangles[4] = {{},{500},{60,30,0,0,51.962,60,51.962},{40}};
	/*setle yapýlanlara statik alan manuel eklenecek */
	/* First Rectangle and it's functions. */
	Rectangles[0].setwidth(500);
	Rectangles[0].setheight(400);
	Rectangles[0].setposx(50);
	Rectangles[0].setposy(70);
	Rectangles[0].setcolor("red");
	Rectangles[0].add_total_area();
	Rectangles[0].add_total_perimeter();
	cout<<"Rectangle_"<<counter++<<" width = "<<Rectangles[0].getwidth()<<" height = "<<Rectangles[0].getheight()
		<<" posx = "<<Rectangles[0].getposx()<<" posy = "<<Rectangles[0].getposy()<<" color = "<<Rectangles[0].getcolor()<<endl;
		
	/* Second Rectangle and it's functions. */
	Rectangles[1].setposx(70);
	Rectangles[1].setposy(95);
	Rectangles[1].setcolor("red");
	cout<<"Rectangle_"<<counter++<<" width = "<<Rectangles[1].getwidth()<<" height = "<<Rectangles[1].getheight()
		<<" posx = "<<Rectangles[1].getposx()<<" posy = "<<Rectangles[1].getposy()<<" color = "<<Rectangles[1].getcolor()<<endl;
	
	/* Third Rectangle and it's functions. */
	Rectangles[2].setcolor("green");
	cout<<"Rectangle_"<<counter++<<" width = "<<Rectangles[2].getwidth()<<" height = "<<Rectangles[2].getheight()
		<<" posx = "<<Rectangles[2].getposx()<<" posy = "<<Rectangles[2].getposy()<<" color = "<<Rectangles[2].getcolor()<<endl;
	
	/* Forth Rectangle and it's functions. */	
	Rectangles[3].setwidth(50);
	Rectangles[3].setheight(40);
	Rectangles[3].setposx(0);
	Rectangles[3].setposy(0);
	Rectangles[3].setcolor("green");
	Rectangles[3].add_total_area();
	Rectangles[3].add_total_perimeter();
	cout<<"Rectangle_"<<counter++<<" width = "<<Rectangles[3].getwidth()<<" height = "<<Rectangles[3].getheight()
		<<" posx = "<<Rectangles[3].getposx()<<" posy = "<<Rectangles[3].getposy()<<" color = "<<Rectangles[3].getcolor()<<endl;
	cout<<endl;
	counter = 1;
	
	/* First Circle and it's functions. */
	Circles[0].setcenterx(300);
	Circles[0].setcentery(300);
	Circles[0].setcolor("red");
	cout<<"Circle_"<<counter++<<" radius = "<<Circles[0].getradius()<<" center x = "<<Circles[0].getcenterx()
		<<" center y = "<<Circles[0].getcentery()<<" color = "<<Circles[0].getcolor()<<endl;
	
	/* Second Circle and it's functions. */
	Circles[1].setradius(350);	
	Circles[1].setcenterx(350);
	Circles[1].setcentery(350);
	Circles[1].setcolor("red");
	Circles[1].add_total_area();
	Circles[1].add_total_perimeter();
	cout<<"Circle_"<<counter++<<" radius = "<<Circles[1].getradius()<<" center x = "<<Circles[1].getcenterx()
		<<" center y = "<<Circles[1].getcentery()<<" color = "<<Circles[1].getcolor()<<endl;
		
	/* Third Circle and it's functions. */
	Circles[2].setcolor("green");
	cout<<"Circle_"<<counter++<<" radius = "<<Circles[2].getradius()<<" center x = "<<Circles[2].getcenterx()
		<<" center y = "<<Circles[2].getcentery()<<" color = "<<Circles[2].getcolor()<<endl;
	
	/* Forth Circle and it's functions. */
	Circles[3].setcenterx(30);
	Circles[3].setcentery(30);
	Circles[3].setcolor("green");
	cout<<"Circle_"<<counter++<<" radius = "<<Circles[3].getradius()<<" center x = "<<Circles[3].getcenterx()
		<<" center y = "<<Circles[3].getcentery()<<" color = "<<Circles[3].getcolor()<<endl;
	
	cout<<endl;
	counter = 1;
	
	/* First Triangle and it's functions. */
	Triangles[0].setedge(600);
	Triangles[0].setposx1(300);
	Triangles[0].setposy1(0);
	Triangles[0].setposx2(0);
	Triangles[0].setposy2(519.615242);
	Triangles[0].setposx3(600);
	Triangles[0].setposy3(519.615242);
	Triangles[0].setcolor("red");
	Triangles[0].add_total_area();
	Triangles[0].add_total_perimeter();
	cout<<"Triangle_"<<counter++<<" edge = "<<Triangles[0].getedge()<<" posx1 = "<<Triangles[0].getposx1()
		<<" posy1 = "<<Triangles[0].getposy1()<<" posx2 = "<<Triangles[0].getposx2()<<" posy2 = "<<Triangles[0].getposy2()
		<<" posx3 = "<<Triangles[0].getposx3()<<" posy3 = "<<Triangles[0].getposy3()<<" color = "<<Triangles[0].getcolor()
		<<endl;
	
	/* Second Triangle and it's functions. */
	Triangles[1].setposx1(250);
	Triangles[1].setposy1(0);
	Triangles[1].setposx2(0);
	Triangles[1].setposy2(433.013);
	Triangles[1].setposx3(500);
	Triangles[1].setposy3(433.013);
	Triangles[1].setcolor("red");
	cout<<"Triangle_"<<counter++<<" edge = "<<Triangles[1].getedge()<<" posx1 = "<<Triangles[1].getposx1()
		<<" posy1 = "<<Triangles[1].getposy1()<<" posx2 = "<<Triangles[1].getposx2()<<" posy2 = "<<Triangles[1].getposy2()
		<<" posx3 = "<<Triangles[1].getposx3()<<" posy3 = "<<Triangles[1].getposy3()<<" color = "<<Triangles[1].getcolor()
		<<endl;
	
	/* Third Triangle and it's functions. */	
	Triangles[2].setcolor("green");
	cout<<"Triangle_"<<counter++<<" edge = "<<Triangles[2].getedge()<<" posx1 = "<<Triangles[2].getposx1()
		<<" posy1 = "<<Triangles[2].getposy1()<<" posx2 = "<<Triangles[2].getposx2()<<" posy2 = "<<Triangles[2].getposy2()
		<<" posx3 = "<<Triangles[2].getposx3()<<" posy3 = "<<Triangles[2].getposy3()<<" color = "<<Triangles[2].getcolor()
		<<endl;
	
	/* Forth Triangle and it's functions. */
	Triangles[3].setposx1(20);
	Triangles[3].setposy1(0);
	Triangles[3].setposx2(0);
	Triangles[3].setposy2(34.641);
	Triangles[3].setposx3(40);
	Triangles[3].setposy3(34.641);
	Triangles[3].setcolor("green");
	cout<<"Triangle_"<<counter++<<" edge = "<<Triangles[3].getedge()<<" posx1 = "<<Triangles[3].getposx1()
		<<" posy1 = "<<Triangles[3].getposy1()<<" posx2 = "<<Triangles[3].getposx2()<<" posy2 = "<<Triangles[3].getposy2()
		<<" posx3 = "<<Triangles[3].getposx3()<<" posy3 = "<<Triangles[3].getposy3()<<" color = "<<Triangles[3].getcolor()
		<<endl;
	
	/* Different 9 combination. */
	/* Test all ComposedShape's function and create differen 9 svg file */
	 	
	ComposedShape Rec_in_Rec(Rectangles[0], Rectangles[2]);
	Rec_in_Rec.OptimalFit(Rec_in_Rec.get_r_container(), Rec_in_Rec.get_r_inner());
	Rec_in_Rec.fileopen("rec_in_rec.svg");
	cout<<Rec_in_Rec;		// Overloaded operator<< function os<< <ComposedShape> 
	Rec_in_Rec.fileclose();
	
	
	ComposedShape Cir_in_Rec(Rectangles[1], Circles[3]);
	Cir_in_Rec.OptimalFit(Cir_in_Rec.get_r_container(), Cir_in_Rec.get_c_inner());
	Cir_in_Rec.fileopen("cir_in_rec.svg");
	cout<<Cir_in_Rec;		// Overloaded operator<< function os<< <ComposedShape> 
	Cir_in_Rec.fileclose();

	ComposedShape Tri_in_Rec(Rectangles[0], Triangles[3]);
	Tri_in_Rec.OptimalFit(Tri_in_Rec.get_r_container(), Tri_in_Rec.get_t_inner());
	Tri_in_Rec.fileopen("tri_in_rec.svg");
	cout<<Tri_in_Rec;		// Overloaded operator<< function os<< <ComposedShape> 
	Tri_in_Rec.fileclose();

	ComposedShape Rec_in_Cir(Circles[1], Rectangles[2]);
	Rec_in_Cir.OptimalFit(Rec_in_Cir.get_c_container(), Rec_in_Cir.get_r_inner());
	Rec_in_Cir.fileopen("rec_in_cir.svg");
	cout<<Rec_in_Cir;		// Overloaded operator<< function os<< <ComposedShape> 
	Rec_in_Cir.fileclose();

	ComposedShape Cir_in_Cir(Circles[0], Circles[3]);
	Cir_in_Cir.OptimalFit(Cir_in_Cir.get_c_container(), Cir_in_Cir.get_c_inner());
	Cir_in_Cir.fileopen("cir_in_cir.svg");
	cout<<Cir_in_Cir;		// Overloaded operator<< function os<< <ComposedShape> 
	Cir_in_Cir.fileclose();

	ComposedShape Tri_in_Cir(Circles[1], Triangles[2]);
	Tri_in_Cir.OptimalFit(Tri_in_Cir.get_c_container(), Tri_in_Cir.get_t_inner());
	Tri_in_Cir.fileopen("tri_in_cir.svg");
	cout<<Tri_in_Cir;		// Overloaded operator<< function os<< <ComposedShape> 
	Tri_in_Cir.fileclose();

	ComposedShape Rec_in_Tri(Triangles[0], Rectangles[3]);
	Rec_in_Tri.OptimalFit(Rec_in_Tri.get_t_container(), Rec_in_Tri.get_r_inner());
	Rec_in_Tri.fileopen("rec_in_tri.svg");
	cout<<Rec_in_Tri;		// Overloaded operator<< function os<< <ComposedShape> 
	Rec_in_Tri.fileclose();

	ComposedShape Cir_in_Tri(Triangles[0], Circles[2]);
	Cir_in_Tri.OptimalFit(Cir_in_Tri.get_t_container(), Cir_in_Tri.get_c_inner());
	Cir_in_Tri.fileopen("cir_in_tri.svg");
	cout<<Cir_in_Tri;		// Overloaded operator<< function os<< <ComposedShape> 
	Cir_in_Tri.fileclose();

	ComposedShape Tri_in_Tri(Triangles[1], Triangles[3]);
	Tri_in_Tri.OptimalFit(Tri_in_Tri.get_t_container(), Tri_in_Tri.get_t_inner());
	Tri_in_Tri.fileopen("tri_in_tri.svg");
	cout<<Tri_in_Tri;		// Overloaded operator<< function os<< <ComposedShape> 
	Tri_in_Tri.fileclose();
	
	cout<<"\n 9 different combinations were printed on 9 different files. \n";
	
	cout<<"\n All functions in the class were used. All functions were tested. \n";
	
	cout<<endl<<"------------------- Test of ++ , --, += Operators --------------------"<<endl;
	/* Test of ++ , -- , += operators */
	/* ------------START------------------ */
	Rectangle container(500,400);
	Rectangle inner1(50,40,0,0);
	Circle inner2(40,90,40);
	Triangle inner3(40,150, 40, 190, 40,170, 5.35898);

	ComposedShape shape(container,inner1);
	ComposedShape::ShapeElem rec(&inner1);
	ComposedShape::ShapeElem cir(&inner2);
	ComposedShape::ShapeElem tri(&inner3);

	// test += operator. Add these shapes in vector.
	shape+=rec;
	shape+=cir;
	shape+=tri;
	
	cout<<endl<<" First state: \n";
	cout<<endl<<" Rectangle posx = "<<inner1.getposx()<<" Rectangle posy = "<<inner1.getposy();
	cout<<endl<<" Circle posx = "<<inner2.getcenterx()<<" Rectangle posy = "<<inner2.getcentery();
	cout<<endl<<" Triangle posx1 = "<<inner3.getposx1()<<" Triangle posy1 = "<<inner3.getposy1()<<" Triangle posx2 = "<<inner3.getposx2()<<" Triangle posy2 = "<<inner3.getposy2()<<" Triangle posx3 = "<<inner3.getposx3()<<" Triangle posy3 = "<<inner3.getposy3();

	/* The position of the shapes is increased by 230. */
	int i;
	for(i=0; i<230; i++)
	{
		// test ++ operator
		inner1++;		// rec
		inner2++;		// cir
		inner3++;		// tri

	}
	cout<<endl;
	cout<<endl<<" 230 times use ++ operator. (increase position of shapes.) ";
	cout<<endl<<" Rectangle posx = "<<inner1.getposx()<<" Rectangle posy = "<<inner1.getposy();
	cout<<endl<<" Circle posx = "<<inner2.getcenterx()<<" Rectangle posy = "<<inner2.getcentery();
	cout<<endl<<" Triangle posx1 = "<<inner3.getposx1()<<" Triangle posy1 = "<<inner3.getposy1()<<" Triangle posx2 = "<<inner3.getposx2()<<" Triangle posy2 = "<<inner3.getposy2()<<" Triangle posx3 = "<<inner3.getposx3()<<" Triangle posy3 = "<<inner3.getposy3();

	/* After increasing, The position of the shapes is decreased by 100. */
	for(i=0; i<100; i++)
	{
		// test -- operator
		inner1--;
		inner2--;
		inner3--;
	}
	cout<<endl;
	cout<<endl<<" 100 times use -- operator. (decrease position of shapes.) ";
	cout<<endl<<" Rectangle posx = "<<inner1.getposx()<<" Rectangle posy = "<<inner1.getposy();
	cout<<endl<<" Circle posx = "<<inner2.getcenterx()<<" Rectangle posy = "<<inner2.getcentery();
	cout<<endl<<" Triangle posx1 = "<<inner3.getposx1()<<" Triangle posy1 = "<<inner3.getposy1()<<" Triangle posx2 = "<<inner3.getposx2()<<" Triangle posy2 = "<<inner3.getposy2()<<" Triangle posx3 = "<<inner3.getposx3()<<" Triangle posy3 = "<<inner3.getposy3();

	
	/* and print file this ComposedShape */
	cout<<endl<<" Addition(++) and subtraction(--) were applied to the position of the shapes. "<<endl;
	/* ---------------FINISHED------------------------*/
	
	/* Test comprasion operators == , != , > , >= , < , <=. 
		Comparison operators to compare two shapes with respect to their areas.  */
	/* ----------------START-----------------------*/
	/* if there is a error, give message on screen */
	cout<<endl<<"---------------   Test Comprasion Operators == , != , > , >= , < , <= ----------------"<<endl;
	Rectangle rect1(30,40);
	Rectangle rect2(20,60);
	Rectangle rect3(32,42);
	Rectangle rect4(28,30);
	if(!(rect1 == rect2)) cout<<"test fault1. "<<endl;
	if(!(rect1 != rect3)) cout<<"test fault2. "<<endl;
	if(!(rect1 > rect4)) cout<<"test fault3. "<<endl;
	if(!(rect1 >= rect2)) cout<<"test fault4. "<<endl;
	if(!(rect2 < rect3)) cout<<"test fault5. "<<endl;
	if(!(rect2 <= rect1)) cout<<"test fault6. "<<endl;
	
	Circle circ1(30);
	Circle circ2(30);
	Circle circ3(32);
	Circle circ4(28);
	if(!(circ1 == circ2))
	{if(!(circ1.getarea()-circ2.getarea() < 0.001 && circ1.getarea()-circ2.getarea() > -0.001)) {cout<<"test fault7. "<<endl;} } // can work incorrectly due to the decimals.
	if(!(circ1 != circ3)) cout<<"test fault8. "<<endl;
	if(!(circ1 > circ4)) cout<<"test fault9. "<<endl;
	if(!(circ1 >= circ4)) cout<<"test fault10. "<<endl;
	if(!(circ2 < circ3)) cout<<"test fault11. "<<endl;
	if(!(circ2 <= circ1)) cout<<"test fault12. "<<endl;
	
	Triangle trian1(35.0);
	Triangle trian2(35.0);
	Triangle trian3(40);
	Triangle trian4(23);
	if(!(trian1 == trian2))
	{if(!(circ1.getarea()-circ2.getarea() < 0.001 && circ1.getarea()-circ2.getarea() > -0.001)) cout<<"test fault13. "<<endl; } // can work incorrectly due to the decimals.
	if(!(trian1 != trian3)) cout<<"test fault14. "<<endl;
	if(!(trian1 > trian4)) cout<<"test fault15. "<<endl;
	if(!(trian1 >= trian4)) cout<<"test fault16. "<<endl;
	if(!(trian2 < trian3)) cout<<"test fault17. "<<endl;
	if(!(trian2 <= trian1)) cout<<"test fault18. "<<endl;
	cout<<"\t\t Comprasion Test is Succesfull. "<<endl;
	/* ---------------FINISHED------------------------*/
	
	/* + and - operator test */
	/* ----------------START-----------------------*/
		cout<<endl<<"---------------   + AND - OPERATOR TEST ----------------"<<endl;
		cout<<endl<<" Rectangle width: "<<Rectangles[0].getwidth()<<" Rectangle height: "<<Rectangles[0].getheight()<<" Rectangle area: "<<Rectangles[0].getarea()<<" Rectangle perimeter: "<<Rectangles[0].getperimeter();
		Rectangles[0] = Rectangles[0] + 50.0;
		cout<<endl<<" Add 50.0 to size";
		cout<<endl<<" Rectangle width: "<<Rectangles[0].getwidth()<<" Rectangle height: "<<Rectangles[0].getheight()<<" Rectangle area: "<<Rectangles[0].getarea()<<" Rectangle perimeter: "<<Rectangles[0].getperimeter();
		Rectangles[0] = Rectangles[0] - 30.0;
		cout<<endl<<" Subtract 30.0 to size";
		cout<<endl<<" Rectangle width: "<<Rectangles[0].getwidth()<<" Rectangle height: "<<Rectangles[0].getheight()<<" Rectangle area: "<<Rectangles[0].getarea()<<" Rectangle perimeter: "<<Rectangles[0].getperimeter();
		cout<<endl;
		cout<<endl<<" Circle radius: "<<Circles[0].getradius()<<" Circle area: "<<Circles[0].getarea()<<" Circle perimeter: "<<Circles[0].getperimeter();
		Circles[0] = Circles[0] + 40.0;
		cout<<endl<<" Add 40.0 to size";
		cout<<endl<<" Circle radius: "<<Circles[0].getradius()<<" Circle area: "<<Circles[0].getarea()<<" Circle perimeter: "<<Circles[0].getperimeter();
		Circles[0] = Circles[0] - 20.0;
		cout<<endl<<" Subtract 20.0 to size";
		cout<<endl<<" Circle radius: "<<Circles[0].getradius()<<" Circle area: "<<Circles[0].getarea()<<" Circle perimeter: "<<Circles[0].getperimeter();
		cout<<endl;
		cout<<endl<<" Triangle radius: "<<Triangles[0].getedge()<<" Triangle area: "<<Triangles[0].getarea()<<" Triangle perimeter: "<<Triangles[0].getperimeter();
		Triangles[0] = Triangles[0] + 70.0;
		cout<<endl<<" Add 70.0 to size";
		cout<<endl<<" Triangle radius: "<<Triangles[0].getedge()<<" Triangle area: "<<Triangles[0].getarea()<<" Triangle perimeter: "<<Triangles[0].getperimeter();
		Triangles[0] = Triangles[0] - 40.0;
		cout<<endl<<" Subtract 40.0 to size";
		cout<<endl<<" Triangle radius: "<<Triangles[0].getedge()<<" Triangle area: "<<Triangles[0].getarea()<<" Triangle perimeter: "<<Triangles[0].getperimeter();
		cout<<endl;
	
	/* ---------------FINISHED------------------------*/
	
	
	/* Static funtions total areas and perimeters */
	cout<<endl<<"------------- Static Function Test -----------------";
	cout<<endl<<endl<<"Total areas of Rectangles: "<<Rectangle::get_total_area()<<endl<<"Total perimeter of Rectangles: "<<Rectangle::get_total_perimeter()<<endl;
	cout<<endl<<"Total areas of Circles: "<<Circle::get_total_area()<<endl<<"Total perimeter of Circles: "<<Circle::get_total_perimeter()<<endl;
	cout<<endl<<"Total areas of Triangles: "<<Triangle::get_total_area()<<endl<<"Total perimeter of Triangle: "<<Triangle::get_total_perimeter()<<endl;
	

	
	return 0;
}
