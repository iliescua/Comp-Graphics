SOURCES = gcontext.cpp x11context.cpp shape.cpp matrix.cpp line.cpp triangle.cpp image.cpp mydrawing.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = run

run: $(OBJECTS)
	g++ -lX11 -o $(EXECUTABLE) $(OBJECTS)

gcontext.o: gcontext.cpp
	g++ -c gcontext.cpp

x11context.o: x11context.cpp
	g++ -c x11context.cpp

shape.o: shape.cpp
	g++ -c shape.cpp

matrix.o: matrix.cpp
	g++ -c matrix.cpp

line.o: line.cpp
	g++ -c line.cpp

triangle.o: triangle.cpp
	g++ -c triangle.cpp

image.o: image.cpp
	g++ -c image.cpp

mydrawing.o: mydrawing.cpp
	g++ -c mydrawing.cpp

main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)