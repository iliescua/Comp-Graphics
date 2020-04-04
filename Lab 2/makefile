SOURCES = matrix.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = making_ex1

making_ex1: $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)

matrix.o: matrix.cpp
	g++ -c matrix.cpp

main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)