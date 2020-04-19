SOURCES = gcontext.cpp x11context.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = making_ex1

making_ex1: $(OBJECTS)
	g++ -lX11 -o $(EXECUTABLE) $(OBJECTS)

gcontext.o: gcontext.cpp
	g++ -c gcontext.cpp

x11context.o: x11context.cpp
	g++ -c x11context.cpp

main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)