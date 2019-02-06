driver : rectangle.o circle.o triangle.o composedshape.o polygon.o polyline.o 161044036_main.o
	 g++ -o driver rectangle.o circle.o triangle.o composedshape.o polygon.o polyline.o 161044036_main.o

161044036_main.o : 161044036_main.cpp
	 g++ -c -std=c++11 -Wall 161044036_main.cpp

polyline.o : polyline.cpp
		  g++ -c -std=c++11 -Wall polyline.cpp

polygon.o : polygon.cpp
		  g++ -c -std=c++11 -Wall polygon.cpp

composedshape.o : composedshape.cpp
		  g++ -c -std=c++11 -Wall composedshape.cpp

rectangle.o : rectangle.cpp
		  g++ -c -std=c++11 -Wall rectangle.cpp

triangle.o : triangle.cpp
		  g++ -c -std=c++11 -Wall triangle.cpp

circle.o : circle.cpp
		  g++ -c -std=c++11 -Wall circle.cpp

clean:
	rm *.o driver
