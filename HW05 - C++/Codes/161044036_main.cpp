#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "composedshape.h"
#include "polygon.h"
#include "polygondyn.h"
#include "polygonvect.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace DerivedPolygon;
using namespace DerivedRect;
using namespace DerivedCirc;
using namespace DerivedTri;
using namespace DerivedComp;
using namespace DerivedPolygon;
using namespace DerivedPolyDyn;
using namespace DerivedPolyVec;

ostream& operator<<(ostream& os, Shape& shape) noexcept
{
	shape.print(os); //call the virtual function whose job is printing!
	
	return os;
}

void printAll(ostream& os, vector<Shape*> vec) noexcept
{
	Rectangle* rec;
	Circle* cir;
	Triangle* tri;
	ComposedShape* com;
	for(Shape* x: vec)
	{
		if(dynamic_cast < Rectangle* > (x) != nullptr)
		{	
			rec = dynamic_cast < Rectangle* > (x);
			os<<(*rec);
		}
		else if(dynamic_cast < Circle* > (x) != nullptr)
		{	
			cir = dynamic_cast < Circle* > (x);
			os<<(*cir);
		}
		else if(dynamic_cast < Triangle* > (x) != nullptr)
		{	
			tri = dynamic_cast < Triangle* > (x);
			os<<(*tri);
		}
		else if(dynamic_cast < ComposedShape* > (x) != nullptr)
		{	
			com = dynamic_cast < ComposedShape* > (x);
			os<<(*com);
		}
	}
}

void printPoly(ostream& os, vector<Shape*> vec) noexcept
{
	PolygonDyn* dyn;
	PolygonVect* vect;
	for(Shape* x: vec)
	{
		if(dynamic_cast < PolygonDyn* > (x) != nullptr)
		{	
			dyn = dynamic_cast < PolygonDyn* > (x);
			os<<(*dyn);
		}
		else if(dynamic_cast < PolygonVect* > (x) != nullptr)
		{	
			vect = dynamic_cast < PolygonVect* > (x);
			os<<(*vect);
		}
	}
}

vector<Shape*> convertAll(vector<Shape*> vec) noexcept
{
	vector<Shape*> new_shapes;
	Rectangle* rec;
	Circle* cir;
	Triangle* tri;
	ComposedShape* com;
	PolygonVect* vect;
	PolygonDyn* dyn;

	for(Shape* x: vec)
	{
		if(dynamic_cast < Rectangle* > (x) != nullptr)
		{	
			rec = dynamic_cast < Rectangle* > (x);
			vect = new PolygonVect((*rec));
			new_shapes.push_back(vect);
		}
		else if(dynamic_cast < Circle* > (x) != nullptr)
		{	
			cir = dynamic_cast < Circle* > (x);
			vect = new PolygonVect((*cir));
			new_shapes.push_back(vect);
		}
		else if(dynamic_cast < Triangle* > (x) != nullptr)
		{	
			tri = dynamic_cast < Triangle* > (x);
			vect = new PolygonVect((*tri));
			new_shapes.push_back(vect);
		}
		else if(dynamic_cast < ComposedShape* > (x) != nullptr)
		{	
			com = dynamic_cast < ComposedShape* > (x);
			vector<Shape*> new_vec = convertAll(com->get_inners());
			
			for(Shape* x : new_vec)
			{
				new_shapes.push_back(x);
			}
		}
		else if(dynamic_cast < PolygonVect* > (x) != nullptr)
		{
			new_shapes.push_back(x);
		}
		else if(dynamic_cast < PolygonDyn* > (x) != nullptr)
		{
			dyn = dynamic_cast < PolygonDyn* > (x);
			vect = new PolygonVect();
			for(int i=0; i<dyn->get_size(); i++)
			{
				vect->get_vec().push_back(dyn->get_arr()[i]);
			}
			vect->set_size(dyn->get_size());
			vect->set_area(dyn->area());
			vect->set_perimeter(dyn->perimeter());
			new_shapes.push_back(vect);
		}
	}
	
	return new_shapes;
}

void sortShapes(vector<Shape *>& vec)
{
	size_t i,j;
	size_t size = vec.size();
	double area1, area2;

	Shape* shp;

	for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
			area1 = vec[i]->area();
			area2 = vec[j]->area();
			if(area1 < area2)
			{
				shp = vec[i];
				vec[i] = vec[j];
				vec[j] = shp;
			}
		}
	} 

}

void fopen(ofstream& os) noexcept
{
	os<<"<svg xmlns=\"http://www.w3.org/2000/svg\"> ";
}
void fclose(ofstream& os) noexcept
{
	os<<"\n </svg>";
	os.close();
}

int main()
{
	cout<<"------------   DRIVER   ------------\n";
	/*  Driver make 5 objects of each class and should make array of objects of each class. */ 
	/* I used different value when creating objects. */
	Rectangle 	Rectangles[5] = {{500,400},{450,500},{30,40},{50,40},{540,470}};
	Circle	 	Circles[5] = {{300},{350},{20},{30},{345}};
	Triangle 	Triangles[5] = {{600},{500},{60},{20},{760}};
	
	/* ComposedShape array 3 different constructor will operate and tested. */
	ComposedShape Shapes[9] = {{Rectangles[0], Rectangles[2]}, {Rectangles[1], Circles[3]},
							   {Rectangles[0], Triangles[3]}, {Circles[1], Rectangles[2]},
							   {Circles[0], Circles[3]}, {Circles[1], Triangles[2]},
							   {Triangles[0], Rectangles[3]}, {Triangles[0], Circles[2]},
							   {Triangles[1], Triangles[3]}};
	
	PolygonDyn vdyn1(Circle(300));
	PolygonDyn vdyn2(Triangle(60));
	PolygonDyn vdyn3(Rectangle(450,500));
	
	PolygonDyn vvect1(Circle(300));
	PolygonDyn vvect2(Triangle(60));
	PolygonDyn vvect3(Rectangle(450,500));		   
	
	cout<<"\n Optimal Fits : \n";			   
	Shapes[0].OptimalFit(Shapes[0].get_r_container(), Shapes[0].get_r_inner());
	Shapes[1].OptimalFit(Shapes[1].get_r_container(), Shapes[1].get_c_inner());
	Shapes[2].OptimalFit(Shapes[2].get_r_container(), Shapes[2].get_t_inner());
	Shapes[3].OptimalFit(Shapes[3].get_c_container(), Shapes[3].get_r_inner());
	Shapes[4].OptimalFit(Shapes[4].get_c_container(), Shapes[4].get_c_inner());
	Shapes[5].OptimalFit(Shapes[5].get_c_container(), Shapes[5].get_t_inner());
	Shapes[6].OptimalFit(Shapes[6].get_t_container(), Shapes[6].get_r_inner());
	Shapes[7].OptimalFit(Shapes[7].get_t_container(), Shapes[7].get_c_inner());
	Shapes[8].OptimalFit(Shapes[8].get_t_container(), Shapes[8].get_t_inner());
	
	ofstream file;
	
	cout<<"\n\n------------   TEST Area Perimeter  ------------\n";
	
	PolygonDyn dyn(Circles[4]);
	PolygonVect vect(Circles[4]);
	
	cout<<endl<<"Rectangle"<<" width= "<<Rectangles[0].getwidth()<<" height= "<<Rectangles[0].getheight()<<" area= "<<Rectangles[0].area()<<" perimeter= "<<Rectangles[0].perimeter();
	cout<<endl<<"Circle"<<" radius= "<<Circles[0].getradius()<<" area= "<<Circles[0].area()<<" perimeter= "<<Circles[0].perimeter();
	cout<<endl<<"Triangle"<<" edge= "<<Triangles[0].getedge()<<" area= "<<Triangles[0].area()<<" perimeter= "<<Triangles[0].perimeter();
	cout<<endl<<"ComposedShape"<<" Container radius= "<<Shapes[5].get_c_container().getradius()<<" area= "<<Shapes[5].area()<<" perimeter= "<<Shapes[5].perimeter();
	cout<<endl<<"PolygonDyn"<<" radius= "<<Circles[4].getradius()<<" area= "<<dyn.area()<<" perimeter= "<<dyn.perimeter();
	cout<<endl<<"PolygonVect"<<" radius= "<<Circles[4].getradius()<<" area= "<<vect.area()<<" perimeter= "<<vect.perimeter();
		
	cout<<"\n\n------------   TEST ++ --  ------------\n";
	
	cout<<endl<<"Rectangle"<<" posx= "<<Rectangles[0].getposx()<<" posy= "<<Rectangles[0].getposy();
	cout<<endl<<"Circle"<<" posx= "<<Circles[0].getcenterx()<<" posy= "<<Circles[0].getcentery();
	cout<<endl<<"Triangle"<<" posx= "<<Triangles[0].getposx1()<<" posy= "<<Triangles[0].getposy1();
	
	cout<<"\n\nIncrease postfix 50 times:\n";
	for(int i=0 ; i<50; i++)
	{
		Rectangles[0]++;
		Circles[0]++;
		Triangles[0]++;
		Shapes[5]++;
		dyn++;
		vect++;
	}
	cout<<endl<<"Rectangle"<<" posx= "<<Rectangles[0].getposx()<<" posy= "<<Rectangles[0].getposy();
	cout<<endl<<"Circle"<<" posx= "<<Circles[0].getcenterx()<<" posy= "<<Circles[0].getcentery();
	cout<<endl<<"Triangle"<<" posx= "<<Triangles[0].getposx1()<<" posy= "<<Triangles[0].getposy1();
	
	cout<<"\n\nIncrease prefix 50 times:\n";
	for(int i=0 ; i<50; i++)
	{
		++Rectangles[0];
		++Circles[0];
		++Triangles[0];
		++Shapes[5];
		++dyn;
		++vect;
	}
	cout<<endl<<"Rectangle"<<" posx= "<<Rectangles[0].getposx()<<" posy= "<<Rectangles[0].getposy();
	cout<<endl<<"Circle"<<" posx= "<<Circles[0].getcenterx()<<" posy= "<<Circles[0].getcentery();
	cout<<endl<<"Triangle"<<" posx= "<<Triangles[0].getposx1()<<" posy= "<<Triangles[0].getposy1();
	
	cout<<"\n\nDecrease postfix 25 times:\n";
	for(int i=0 ; i<25; i++)
	{
		Rectangles[0]--;
		Circles[0]--;
		Triangles[0]--;
		Shapes[5]--;
		dyn--;
		vect--;
	}
	cout<<endl<<"Rectangle"<<" posx= "<<Rectangles[0].getposx()<<" posy= "<<Rectangles[0].getposy();
	cout<<endl<<"Circle"<<" posx= "<<Circles[0].getcenterx()<<" posy= "<<Circles[0].getcentery();
	cout<<endl<<"Triangle"<<" posx= "<<Triangles[0].getposx1()<<" posy= "<<Triangles[0].getposy1();
	
	cout<<"\n\nDecrease prefix 25 times:\n";
	for(int i=0 ; i<25; i++)
	{
		--Rectangles[0];
		--Circles[0];
		--Triangles[0];
		--Shapes[5];
		--dyn;
		--vect;
	}
	cout<<endl<<"Rectangle"<<" posx= "<<Rectangles[0].getposx()<<" posy= "<<Rectangles[0].getposy();
	cout<<endl<<"Circle"<<" posx= "<<Circles[0].getcenterx()<<" posy= "<<Circles[0].getcentery();
	cout<<endl<<"Triangle"<<" posx= "<<Triangles[0].getposx1()<<" posy= "<<Triangles[0].getposy1();
		
	cout<<"\n\n------------   TEST == != <= >= < >  ------------\n";
	cout<<"\n --- Rectangle --- \n";
	if(Rectangles[0] == Rectangles[0]) cout<<" == success."<<endl;
	else cout<<" == unsuccess."<<endl;
	if(Rectangles[3] != Rectangles[2]) cout<<" != success."<<endl;
	else cout<<" != unsuccess."<<endl;
	if(Rectangles[1] >= Rectangles[3]) cout<<" >= success."<<endl;
	else cout<<" >= unsuccess."<<endl;
	if(Rectangles[1] <= Rectangles[1]) cout<<" <= success."<<endl;
	else cout<<" <= unsuccess."<<endl;
	if(Rectangles[4] > Rectangles[3]) cout<<" > success."<<endl;
	else cout<<" > unsuccess."<<endl;
	if(Rectangles[0] < Rectangles[1]) cout<<" < success."<<endl;
	else cout<<" < unsuccess."<<endl;
	
	cout<<"\n\n --- Circle --- \n";
	if(Circles[0] == Circles[0]) cout<<" == success."<<endl;
	else cout<<" == unsuccess."<<endl;
	if(Circles[3] != Circles[2]) cout<<" != success."<<endl;
	else cout<<" != unsuccess."<<endl;
	if(Circles[1] >= Circles[3]) cout<<" >= success."<<endl;
	else cout<<" >= unsuccess."<<endl;
	if(Circles[1] <= Circles[1]) cout<<" <= success."<<endl;
	else cout<<" <= unsuccess."<<endl;
	if(Circles[4] > Circles[3]) cout<<" > success."<<endl;
	else cout<<" > unsuccess."<<endl;
	if(Circles[0] < Circles[1]) cout<<" < success."<<endl;
	else cout<<" < unsuccess."<<endl;
	
	cout<<"\n\n --- Triangle --- \n";
	if(Triangles[0] == Triangles[0]) cout<<" == success."<<endl;
	else cout<<" == unsuccess."<<endl;
	if(Triangles[3] != Triangles[2]) cout<<" != success."<<endl;
	else cout<<" != unsuccess."<<endl;
	if(Triangles[1] >= Triangles[3]) cout<<" >= success."<<endl;
	else cout<<" >= unsuccess."<<endl;
	if(Triangles[1] <= Triangles[1]) cout<<" <= success."<<endl;
	else cout<<" <= unsuccess."<<endl;
	if(Triangles[4] > Triangles[3]) cout<<" > success."<<endl;
	else cout<<" > unsuccess."<<endl;
	if(Triangles[3] < Triangles[1]) cout<<" < success."<<endl;
	else cout<<" < unsuccess."<<endl;
	
	cout<<"\n\n --- ComposedShape --- \n";
	if(Shapes[0] == Shapes[0]) cout<<" == success."<<endl;
	else cout<<" == unsuccess."<<endl;
	if(Shapes[3] != Shapes[2]) cout<<" != success."<<endl;
	else cout<<" != unsuccess."<<endl;
	if(Shapes[5] >= Shapes[3]) cout<<" >= success."<<endl;
	else cout<<" >= unsuccess."<<endl;
	if(Shapes[1] <= Shapes[1]) cout<<" <= success."<<endl;
	else cout<<" <= unsuccess."<<endl;
	if(Shapes[2] > Shapes[6]) cout<<" > success."<<endl;
	else cout<<" > unsuccess."<<endl;
	if(Shapes[7] < Shapes[3]) cout<<" < success."<<endl;
	else cout<<" < unsuccess."<<endl;
	
	cout<<"\n\n --- PolygonDyn --- \n";
	if(vdyn1 == vdyn1) cout<<" == success."<<endl;
	else cout<<" == unsuccess."<<endl;
	if(vdyn2 != vdyn1) cout<<" != success."<<endl;
	else cout<<" != unsuccess."<<endl;
	if(vdyn1 >= vdyn3) cout<<" >= success."<<endl;
	else cout<<" >= unsuccess."<<endl;
	if(vdyn1 <= vdyn1) cout<<" <= success."<<endl;
	else cout<<" <= unsuccess."<<endl;
	if(vdyn3 > vdyn2) cout<<" > success."<<endl;
	else cout<<" > unsuccess."<<endl;
	if(vdyn3 < vdyn1) cout<<" < success."<<endl;
	else cout<<" < unsuccess."<<endl;
	
	cout<<"\n\n --- PolygonVect --- \n";
	if(vvect1 == vvect1) cout<<" == success."<<endl;
	else cout<<" == unsuccess."<<endl;
	if(vvect2 != vvect1) cout<<" != success."<<endl;
	else cout<<" != unsuccess."<<endl;
	if(vvect1 >= vvect3) cout<<" >= success."<<endl;
	else cout<<" >= unsuccess."<<endl;
	if(vvect1 <= vvect1) cout<<" <= success."<<endl;
	else cout<<" <= unsuccess."<<endl;
	if(vvect3 > vvect2) cout<<" > success."<<endl;
	else cout<<" > unsuccess."<<endl;
	if(vvect3 < vvect1) cout<<" < success."<<endl;
	else cout<<" < unsuccess."<<endl;
	
	cout<<"\n\n------------   TEST <<  ------------\n";
	
	cout<<"\n Shape position increased 50. \n";
	
	file.open("rectangle.svg");
	fopen(file);
	file<<Rectangles[0];
	fclose(file);
	cout<<"\n Rectangle printed rectangle.svg file";
	
	file.open("circle.svg");
	fopen(file);
	file<<Circles[0];
	fclose(file);
	cout<<"\n Circle printed circle.svg file";
	
	file.open("triangle.svg");
	fopen(file);
	file<<Triangles[0];
	fclose(file);
	cout<<"\n Triangle printed triangle.svg file";
	
	file.open("composedshape.svg");
	fopen(file);
	file<<Shapes[5];
	fclose(file);
	cout<<"\n ComposedShape printed composedshape.svg file";
	
	file.open("polygondyn.svg");
	fopen(file);
	file<<dyn;
	fclose(file);
	cout<<"\n PolygonDyn printed polygondyn.svg file";
	
	file.open("polygonvect.svg");
	fopen(file);
	file<<vect;
	fclose(file);
	cout<<"\n PolygonVect printed polygonvect.svg file";
	
	cout<<"\n ----------------------------------- \n";
	
	cout<<"\n\n------------   TEST printAll function ------------\n";
	vector<Shape *> shapevec;
	
	shapevec = Shapes[2].get_inners();
	file.open("PrintAll_1.svg");
	fopen(file);
	printAll(file, shapevec);
	fclose(file);
	shapevec.clear();
	
	shapevec = Shapes[6].get_inners();
	file.open("PrintAll_2.svg");
	fopen(file);
	printAll(file, shapevec);
	fclose(file);
	shapevec.clear();
	
	shapevec = Shapes[8].get_inners();
	file.open("PrintAll_3.svg");
	fopen(file);
	printAll(file, shapevec);
	fclose(file);
	shapevec.clear();
	
	shapevec.push_back(&Shapes[7]);
	file.open("PrintAll_4.svg");
	fopen(file);
	printAll(file, shapevec);
	fclose(file);
	shapevec.clear();
	
	cout<<"Four shape* vector print Print_All_num files. All combination tried.";
	
	cout<<"\n\n------------ PolygonDyn and PolygonVect object print";
	file.open("polygondyn1.svg");
	fopen(file);
	file<<vdyn1;
	fclose(file);
	cout<<"\n PolygonDyn printed polygondyn1.svg file";
	
	file.open("polygondyn2.svg");
	fopen(file);
	file<<vdyn2;
	fclose(file);
	cout<<"\n PolygonDyn printed polygondyn2.svg file";
	
	file.open("polygondyn3.svg");
	fopen(file);
	file<<vdyn3;
	fclose(file);
	cout<<"\n PolygonDyn printed polygondyn3.svg file";
	
	file.open("polygonvect1.svg");
	fopen(file);
	file<<vvect1;
	fclose(file);
	cout<<"\n PolygonVect printed polygonvect1.svg file";
	
	file.open("polygonvect2.svg");
	fopen(file);
	file<<vvect2;
	fclose(file);
	cout<<"\n PolygonVect printed polygonvect2.svg file";
	
	file.open("polygonvect3.svg");
	fopen(file);
	file<<vvect3;
	fclose(file);
	cout<<"\n PolygonVect printed polygonvect3.svg file";
	
	cout<<"\n\n------------   TEST printPolly and convertAll function ------------\n";
	vector<Shape *> shapevec2;
	
	shapevec2 = Shapes[2].get_inners();
	file.open("PrintPoly_1.svg");
	fopen(file);
	printPoly(file, convertAll(shapevec2));
	fclose(file);
	shapevec2.clear();
	
	shapevec2 = Shapes[6].get_inners();
	file.open("PrintPoly_2.svg");
	fopen(file);
	printPoly(file, convertAll(shapevec2));
	fclose(file);
	shapevec2.clear();
	
	shapevec2 = Shapes[8].get_inners();
	file.open("PrintPoly_3.svg");
	fopen(file);
	printPoly(file, convertAll(shapevec2));
	fclose(file);
	shapevec2.clear();
	
	shapevec2.push_back(&Shapes[7]);
	file.open("PrintPoly_4.svg");
	fopen(file);
	printPoly(file, convertAll(shapevec2));
	fclose(file);
	shapevec2.clear();
	
	cout<<"Four shape* vector print Print_Poly_num files. All combination tried.";
	
	cout<<"\n\n------------   TEST  sortShapes function ------------\n";

	vector<Shape *> shapevec3;
	shapevec3 = Shapes[1].get_inners();
	shapevec3.push_back(&Shapes[3]);
	shapevec3.push_back(&Rectangles[4]);
	shapevec3.push_back(&Circles[2]);
	shapevec3.push_back(&Triangles[3]);
	PolygonDyn a(Circles[4]);
	PolygonVect b(Rectangles[3]);
	shapevec3.push_back(&a);
	shapevec3.push_back(&b);
	
	cout<<"\n Before Sort: \n";
	for(Shape* x: shapevec3)
	{
		cout<<x->area()<<" ";
	}
	
	sortShapes(shapevec3);
	
	cout<<"\n\n After Sort: \n";
	for(Shape* x: shapevec3)
	{
		cout<<x->area()<<" ";
	}
	
	shapevec3.clear();
	
	cout<<"\n\n ------------------------  END ---------------------\n";
	
	
	


	return 0;
}
