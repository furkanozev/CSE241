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
	cout<<"------------   DRÝVER   ------------\n";
	int counter = 1;
	/*  Driver make 4 objects of each class and should make array of objects of each class. */ 
	/* I used different constructor structures when creating. */
	/* Then I set some values for constructor. */
	Rectangle 	Rectangles[4] = {{},{450,500},{30,40,0,0},{}};
	Circle	 	Circles[4] = {{300},{},{20,20,20},{30}};
	Triangle 	Triangles[4] = {{},{500},{60,30,0,0,51.962,60,51.962},{40}};
	
	/* First Rectangle and it's functions. */
	Rectangles[0].setwidth(500);
	Rectangles[0].setheight(400);
	Rectangles[0].setposx(50);
	Rectangles[0].setposy(70);
	Rectangles[0].setcolor("red");
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
	Rec_in_Rec.drawcontainer(Rec_in_Rec.get_r_container());
	Rec_in_Rec.draw(Rec_in_Rec.get_rec_vec());
	Rec_in_Rec.fileclose();

	ComposedShape Cir_in_Rec(Rectangles[1], Circles[3]);
	Cir_in_Rec.OptimalFit(Cir_in_Rec.get_r_container(), Cir_in_Rec.get_c_inner());
	Cir_in_Rec.fileopen("cir_in_rec.svg");
	Cir_in_Rec.drawcontainer(Cir_in_Rec.get_r_container());
	Cir_in_Rec.draw(Cir_in_Rec.get_cir_vec());
	Cir_in_Rec.fileclose();

	ComposedShape Tri_in_Rec(Rectangles[0], Triangles[3]);
	Tri_in_Rec.OptimalFit(Tri_in_Rec.get_r_container(), Tri_in_Rec.get_t_inner());
	Tri_in_Rec.fileopen("tri_in_rec.svg");
	Tri_in_Rec.drawcontainer(Tri_in_Rec.get_r_container());
	Tri_in_Rec.draw(Tri_in_Rec.get_tri_vec());
	Tri_in_Rec.fileclose();

	ComposedShape Rec_in_Cir(Circles[1], Rectangles[2]);
	Rec_in_Cir.OptimalFit(Rec_in_Cir.get_c_container(), Rec_in_Cir.get_r_inner());
	Rec_in_Cir.fileopen("rec_in_cir.svg");
	Rec_in_Cir.drawcontainer(Rec_in_Cir.get_c_container());
	Rec_in_Cir.draw(Rec_in_Cir.get_rec_vec());
	Rec_in_Cir.fileclose();

	ComposedShape Cir_in_Cir(Circles[0], Circles[3]);
	Cir_in_Cir.OptimalFit(Cir_in_Cir.get_c_container(), Cir_in_Cir.get_c_inner());
	Cir_in_Cir.fileopen("cir_in_cir.svg");
	Cir_in_Cir.drawcontainer(Cir_in_Cir.get_c_container());
	Cir_in_Cir.draw(Cir_in_Cir.get_cir_vec());
	Cir_in_Cir.fileclose();

	ComposedShape Tri_in_Cir(Circles[1], Triangles[2]);
	Tri_in_Cir.OptimalFit(Tri_in_Cir.get_c_container(), Tri_in_Cir.get_t_inner());
	Tri_in_Cir.fileopen("tri_in_cir.svg");
	Tri_in_Cir.drawcontainer(Tri_in_Cir.get_c_container());
	Tri_in_Cir.draw(Tri_in_Cir.get_tri_vec());
	Tri_in_Cir.fileclose();

	ComposedShape Rec_in_Tri(Triangles[0], Rectangles[3]);
	Rec_in_Tri.OptimalFit(Rec_in_Tri.get_t_container(), Rec_in_Tri.get_r_inner());
	Rec_in_Tri.fileopen("rec_in_tri.svg");
	Rec_in_Tri.drawcontainer(Rec_in_Tri.get_t_container());
	Rec_in_Tri.draw(Rec_in_Tri.get_rec_vec());
	Rec_in_Tri.fileclose();

	ComposedShape Cir_in_Tri(Triangles[0], Circles[2]);
	Cir_in_Tri.OptimalFit(Cir_in_Tri.get_t_container(), Cir_in_Tri.get_c_inner());
	Cir_in_Tri.fileopen("cir_in_tri.svg");
	Cir_in_Tri.drawcontainer(Cir_in_Tri.get_t_container());
	Cir_in_Tri.draw(Cir_in_Tri.get_cir_vec());
	Cir_in_Tri.fileclose();

	ComposedShape Tri_in_Tri(Triangles[1], Triangles[3]);
	Tri_in_Tri.OptimalFit(Tri_in_Tri.get_t_container(), Tri_in_Tri.get_t_inner());
	Tri_in_Tri.fileopen("tri_in_tri.svg");
	Tri_in_Tri.drawcontainer(Tri_in_Tri.get_t_container());
	Tri_in_Tri.draw(Tri_in_Tri.get_tri_vec());
	Tri_in_Tri.fileclose();
	
	cout<<"\n 9 different combinations were printed on 9 different files. \n";
	
	cout<<"\n All functions in the class were used. All functions were tested. \n";
		
	return 0;
}
