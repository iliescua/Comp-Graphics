SOURCES = math.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = making_ex1

making_ex1: $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)

math.o: math.cpp
	g++ -c math.cpp
	
clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)