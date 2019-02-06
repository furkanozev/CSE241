driver : shape.o rectangle.o circle.o triangle.o composedshape.o polygon.o polygondyn.o polygonvect.o 161044036_main.o
	 g++ -o driver shape.o rectangle.o circle.o triangle.o composedshape.o polygon.o polygondyn.o polygonvect.o 161044036_main.o

161044036_main.o : 161044036_main.cpp
	 g++ -c -std=c++11 -Wall 161044036_main.cpp

shape.o : shape.cpp
		  g++ -c -std=c++11 -Wall shape.cpp

rectangle.o : rectangle.cpp
		  g++ -c -std=c++11 -Wall rectangle.cpp

triangle.o : triangle.cpp
		  g++ -c -std=c++11 -Wall triangle.cpp

circle.o : circle.cpp
		  g++ -c -std=c++11 -Wall circle.cpp

composedshape.o : composedshape.cpp
		  g++ -c -std=c++11 -Wall composedshape.cpp
		  
polygon.o : polygon.cpp
		  g++ -c -std=c++11 -Wall polygon.cpp

polygondyn.o : polygondyn.cpp
		  g++ -c -std=c++11 -Wall polygondyn.cpp

polygonvect.o : polygonvect.cpp
		  g++ -c -std=c++11 -Wall polygonvect.cpp


clean:
	rm *.o driver

