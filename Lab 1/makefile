SOURCES = lab1.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = making_ex1

making_ex1: $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS)

lab1.o: lab1.cpp
	g++ -c lab1.cpp
	
clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)